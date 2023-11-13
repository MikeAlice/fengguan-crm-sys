#pragma once
#include "stdafx.h"
#include "InventoryListDAO.h"
#include "InventoryListMapper.h"
#include "domain/query/inventorylist/InventoryListQuery.h"

//定义条件解析宏，减少重复代码
#define FLOW_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->goods_id) { \
	sql << " AND `goods_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->goods_id.getValue(0)); \
} //\
//if (query->connect_id) { \
//	sql << " AND connect_id=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->connect_id.getValue("")); \
//} \
//if (query->create_time) { \
//	sql << " AND create_time=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
//}
namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：record_id！
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->goods_id.getValue({});
		}
		sql << ")";
	}
	/*
	* In C++20:
	* #define insertIdList(sql, dto, varname) \
	* []<typename T>(stringstream &sql, T &dto){ \
	* sql << "("; \
	*	for (auto i = dto->begin(); i != dto->end(); i++) \
	*	{ \
	*		if (i != dto->begin())	sql << ","; \
	*		sql << (*i)->varname.getValue({}); \
	*	} \
	*	sql << ")"; \
	* }()
	*/
}

std::list<InventoryListDO> InventoryListDAO::select2export(const oatpp::List<ExportInventoryList::Wrapper>& dto)
{
	//创建sql对象 然后联表查询
	stringstream sql;
	sql << "SELECT sgs.goods_id, sgs.sku_id, sgs.goods_name, sgs.sku_name, sgs.stock, fg.goods_attribute_id,sgs.store_id, sgs.sale_price, sgs.cost_price, sgs.total_cost_money, sgs.total_profit_money, sgs.code "
		"FROM stock_goods_sku sgs "
		"LEFT JOIN fly_goods fg ON sgs.goods_id = fg.goods_id "
		"LEFT JOIN stock_store ss ON sgs.store_id = ss.store_id "
		"WHERE sgs.goods_id IN ";
	////生成sql语句
	sqlHelpers::insertIdList(sql, dto);
	/*sql << "select goods_id from stock_goods_sku ";
	FLOW_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;*/
	InventoryListMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQuery<InventoryListDO, InventoryListMapper>(sqlStr, mapper);
}

std::list<InventoryListDO> InventoryListDAO::selectWithPage(const InventoryListPageQuery::Wrapper& query)
{
	//创建sql对象 然后联表查询
	stringstream sql;
	//sql << "SELECT sgs.goods_id,sgs.sku_id,sgs.goods_name,sgs.sku_name,sgs.stock,fg.goods_attribute_id,sgs.sale_price,sgs.cost_price,sgs.total_cost_money,sgs.total_profit_money,sgs.code,fpp.supplier_name,cc.address "
	//	"FROM stock_goods_sku sgs "
	//	"LEFT JOIN fly_goods fg ON fg.goods_id=sgs.goods_id,fg.goods_name=sgs.goods_name,fg.sale_price=sgs.sale_price,fg.cost_price=sgs.cost_price,fg.code=sgs.code "
	//	"LEFT JOIN fin_pay_plan fpp "
	//	"LEFT JOIN cst_customer cc "
	//	"WHERE goods_id IN ";
	////生成sql语句
	//sqlHelpers::insertIdList(sql, dto);
	sql << "select goods_id from stock_goods_sku ";
	FLOW_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	InventoryListMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQuery<InventoryListDO, InventoryListMapper>(sqlStr, mapper, params);
}

//uint64_t InventoryListDAO::removeData(const oatpp::List<DelInventoryListDTO::Wrapper>& dto)
//{
//	stringstream sql;
//	sql << "DELETE FROM stock_goods_sku sgs "
//		"WHERE goods_id IN ";
//	sqlHelpers::insertIdList(sql, dto);
//	string sqlStr = sql.str();
//	std::cout << sqlStr << std::endl;
//	return sqlSession->executeUpdate(sqlStr);
//}
