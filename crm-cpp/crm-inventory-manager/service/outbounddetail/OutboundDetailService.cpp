#include "stdafx.h"
#include "OutboundDetailService.h"
#include "dao/outbounddetail/OutboundDAO.h"
#include "ExcelComponent.h"
#include "uselib/fastdfs/useFastDFS.h"




OutboundDetailPageDTO::Wrapper OutboundDetailService::listAll(const OutboundDetailQuery::Wrapper& query)
{
	auto pages = OutboundDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	
	OutboundDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	pages->total = count;
	pages->calcPages();
	list<OutboundDetailDO> result = dao.selectWithPage(query);
	
	for (OutboundDetailDO sub : result) {
		auto dto = OutboundDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, SKUID, Skuid,goodsName,GoodsName,SKUname,Skuname,goodsId,GoodsId,number,Number,commodityType,CommodityType,stockOut,StockOut,stockOutTime,StockOutTime,note,Note);
		pages->addData(dto);
	}
	return pages;
}

oatpp::String OutboundDetailService::exportData(const List<ExportOutboundDetailsDTO::Wrapper>& query)
{
	OutboundDetailDAO dao;
	auto DOList = dao.selectWithId(query);

	//添加表头
	std::vector<std::string> title = {u8"SKU编号",u8"商品编号",u8"SKU名称",u8"商品名称",u8"数量",u8"商品类型",u8"仓库名称",u8"对应出库单",u8"出库时间",u8"备注"};
	std::vector<std::vector<std::string>> data{};
	data.push_back(title);
	
	//添加数据
	for (const auto& i : DOList) {
		std::vector<std::string> row;
		row.push_back(to_string(i.getSkuid()));
		row.push_back(to_string(i.getGoodsId()));
		row.push_back(i.getSkuname());
		row.push_back(i.getGoodsName());
		row.push_back(to_string(i.getNumber()));
		row.push_back(i.getCommodityType());
		row.push_back(i.getStorehouse());
		row.push_back(to_string(i.getStockOut()));
		row.push_back(i.getStockOutTime());
		row.push_back(i.getNote());
		data.push_back(row);
	}

	//创建Excel
	std::string excelFile = getExcelFileName();
	std::string sheetName{ u8"数据表1" };
	ExcelComponent excel;
	excel.writeVectorToFile(excelFile, sheetName, data);

	//上传
	string url = useFastDFS::useDfsWithNacos(excelFile);
	
	return url;
}

std::string OutboundDetailService::getExcelFileName()
{
	std::string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}

