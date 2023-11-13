#include "stdafx.h"
#include "Out_stockService.h"
#include "dao/out_stock/Out_stockDAO.h"
#include"domain/do/out_stock/Out_stockDO.h"

Out_StockPageDTO::Wrapper Out_stockService::listAll(const Out_StockQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = Out_StockPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	Out_stockDAO dao;
	/*uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}*/

	// 分页查询数据
	pages->total = 1;

	pages->calcPages();
	list<Out_StockPagDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (Out_StockPagDO sub : result)
	{
		auto dto = Out_stockDTO::createShared();
		/* 		dto->id = sub.getId();
				dto->name = sub.getName();
				dto->sex = sub.getSex();
				dto->age = sub.getAge();*/
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, out_stock_id, Out_Stock_Id, number, Number, status, Status, out_time, Out_Time,
			remarks, Remarks, supplier_name, Supplier_Name, out_stock_person, Out_Stock_Person, out_type, Out_Type)
			pages->addData(dto);

	}
	return pages;
}
//查询出库单明细(用id查询) 负责人：小彬
Out_stockDTO::Wrapper Out_stockService::queryone(const string& id)
{
	auto dto = Out_stockDTO::createShared();
	Out_stockDAO dao;
	list<Out_StocDetailDO> result = dao.selectById(id);
	if (result.empty()) {
		return dto;
	}
	// 将DO转换成DTO
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), goods_id, Goods_Id, sku_id, Sku_Id, goods_name, Goods_Name, sku_name, Sku_Name, number, Number, out_time, Out_Time,
		remarks, Remarks, supplier_name, Supplier_Name, category_name, Category_Name, store_name, Store_Name, out_stock_order, Out_Stock_Order)
		return dto;

}
//添加出库单
bool Out_stockService::addData(const AddOut_stock::Wrapper& dto)
{
	// 组装DO数据	
	AddOut_StockDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Store_Name, store_name, Number, number, Status, status, Out_Stock_Person, out_stock_person, Out_Time, out_time,
		Out_Type, out_type, Create_User_Id, create_user_id, Create_Time, create_time);
	// 执行插入数据
	Out_stockDAO dao;
	return dao.insert(data);
}