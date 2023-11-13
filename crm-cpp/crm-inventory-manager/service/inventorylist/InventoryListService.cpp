/*
 Copyright Zero One Star. All rights reserved.

 @Author: ruodi
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/


#include "stdafx.h"
#include "InventoryListService.h"
#include "dao/inventorylist/InventoryListDAO.h"
#include "../crm-inventory-manager/Macros.h"
#include "ExcelComponent.h"
#include "uselib/excel/useExcel.h"
#include"uselib/fastdfs/useFastDFS.h"
#include "domain/dto/inventorylist/InventorylistDTO.h"




InventoryListPageDTO::Wrapper InventoryListService::listAll(const InventoryListPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = InventoryListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	InventoryListDAO dao;
	/*uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}*/
	/*pages->total_expenditure = dao.count_total_pay(query);
	pages->total_income = dao.count_total_rece(query);*/
	// 分页查询数据
	/*pages->total = count;*/
	pages->calcPages();
	list<InventoryListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (InventoryListDO sub : result)
	{
		auto dto = InventoryListDTO::createShared();
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, bank_id, Bankid, income, Income, expenditure, Expenditure, surplus, Surplus, \
			type, Type, connect_id, Connectid, create_user, Createuser, create_time, Createtime)*/
		dto->goods_id = sub.getGoods_id();
			pages->addData(dto);

	}
	return pages;
}


// 导出功能 先创建dao  拿到daolist 传到fast fds
std::string InventoryListService::exportData(const oatpp::List<ExportInventoryList::Wrapper>& dto)
{
	//return "url";
	InventoryListDAO dao;
	auto DOList = dao.select2export(dto);

	// 获取标题行
	auto title = getTitles();

	// 添加标题行
	vector<vector<std::string>> data{};
	data.push_back(title);

	// 添加数据行  遍历数据 塞数据 到data
	for (const auto& i : DOList)
	{
		vector<string> row{};
		row.push_back(to_string(i.getGoods_id()));
		row.push_back(to_string(i.getSku_id()));
		row.push_back(i.getGoods_name());
		row.push_back(i.getSku_name());
		row.push_back(to_string(i.getNumber()));
		row.push_back(i.getCategory_name());
		row.push_back(i.getStore_name());
		row.push_back(to_string(i.getSale_price()));
		row.push_back(to_string(i.getCost_price()));
		row.push_back(to_string(i.getCost_amount()));
		row.push_back(to_string(i.getAnticipated_profit()));
		row.push_back(i.getOriginal_code());
		data.push_back(row);
	}

	// 创建Excel并上传到Nacos

	string downloadURL = useFastDFS::useDfsWithNacos(useExcel::createExcelFile(data));

	return downloadURL;
}
//自己写出来 表头 也可以sql查出来表头
std::vector<std::string> InventoryListService::getTitles()
{
	vector<string> title;
	
	title.push_back(u8"商品ID");
	title.push_back(u8"SKU ID");
	title.push_back(u8"商品名称");
	title.push_back(u8"SKU名称");
	title.push_back(u8"库存数量");
	title.push_back(u8"商品类型");
	title.push_back(u8"仓库名称");
	title.push_back(u8"销售价格");
	title.push_back(u8"成本价格");
	title.push_back(u8"成本金额");
	title.push_back(u8"预计利润");
	title.push_back(u8"原厂编码");
	return title;
}

std::string InventoryListService::getExcelFileName()
{
	string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示 生成时间戳
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}

