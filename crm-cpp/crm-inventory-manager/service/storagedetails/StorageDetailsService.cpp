#include "stdafx.h"
#include "StorageDetailsService.h"
#include "uselib/fastdfs/useFastDFS.h"
#include "uselib/excel/useExcel.h"
#include "dao/storagedetails/StorageDetailsDAO.h"



StorageDetailsPageDTO::Wrapper StorageDetailsService::listAll(const StorageDetailsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = StorageDetailsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	StorageDetailsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<StorageDetailsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (StorageDetailsDO sub : result)
	{
		auto dto = StorageDetailsDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, goods_id, GoodsId, sku_id, SKUID, goods_name, GoodsName, number, Number,category_name,CateGoryName,store_name,StoreName,into_intro,IntoIntro,into_time,IntoTime,remarks,Remarks,supplier_name,SupplierName);
		pages->addData(dto);

	}
	return pages;
}

std::string StorageDetailsService::exportData(const oatpp::List<ExportStorageDetailsDTO::Wrapper> storagedetailsQuery)
{
	StorageDetailsDAO dao;
	auto DOList = dao.selectWithIdList(storagedetailsQuery);

	// 获取标题行
	auto title = getTitles();

	// 添加标题行
	vector<vector<std::string>> data{};
	data.push_back(title);

	// 添加数据行
	for (const auto& i : DOList)
	{
		vector<string> row{};
		row.push_back(to_string(i.getGoodsId()));
		row.push_back(to_string(i.getSKUID()));
		row.push_back(i.getGoodsName());
		row.push_back(i.getSKUName());
		row.push_back(to_string(i.getNumber()));
		row.push_back(i.getCateGoryName());
		row.push_back(i.getStoreName());
		row.push_back(i.getIntoIntro());
		row.push_back(i.getIntoTime());
		row.push_back(i.getRemarks());
		data.push_back(row);
	}

	// 创建Excel并上传到Nacos
	string downloadURL = useFastDFS::useDfsWithNacos(useExcel::createExcelFile(data));

	return downloadURL;
}

std::vector<string> StorageDetailsService::getTitles()
{
	vector<string> title;
	title.push_back(u8"商品ID");
	title.push_back(u8"SKU ID");
	title.push_back(u8"商品名称");
	title.push_back(u8"SKU名称");
	title.push_back(u8"数量");
	title.push_back(u8"商品类型");
	title.push_back(u8"仓库名称");
	title.push_back(u8"对应入库单");
	title.push_back(u8"入库时间");
	title.push_back(u8"备注");
	return title;
}
