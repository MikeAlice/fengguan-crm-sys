#include "stdafx.h"
#include "Out_stockDAO.h"
#include"dao/out_stock/Out_stockMapper.h"
#include <sstream>
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->out_stock_id) { \
	sql << " AND s.out_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->out_stock_id.getValue(0)); \
} \
if (query->number) { \
	sql << " AND s.number=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->number.getValue(0)); \
} \
if (query->status) { \
	sql << " AND s.status=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->status.getValue(0)); \
}\
if (query->out_time) { \
	sql << " AND s.out_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->out_time.getValue("")); \
}\
if (query->remarks) { \
	sql << " AND t.remarks=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->remarks.getValue("")); \
}\
if (query->supplier_name) { \
	sql << " AND supplier_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->supplier_name.getValue("")); \
}\
if (query->out_stock_person) { \
	sql << " AND s.out_user_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->out_stock_person.getValue("")); \
}\
if (query->out_type) { \
	sql << " AND s.out_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->out_type.getValue("")); \
}\
if (query->goods_name) { \
	sql << " AND t.goods_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue("")); \
}\
if (query->sku_name) { \
	sql << " AND t.sku_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sku_name.getValue("")); \
}\
if (query->category_name) { \
	sql << " AND f.category_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->category_name.getValue("")); \
}\
if (query->goods_id) { \
	sql << " AND t.goods_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->goods_id.getValue(0)); \
} \
if (query->sku_id) { \
	sql << " AND t.sku_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->sku_id.getValue(0)); \
} \
if (query->store_name) { \
	sql << " AND s.store_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->store_name.getValue("")); \
}

namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：out_id！
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->out_id.getValue({});
		}
		sql << ")";
	}
}

uint64_t Out_stockDAO::counts(const Out_StockQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM stock_out s INNER JOIN stock_out_list t ON s.out_id=t.out_id";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	cout << sqlStr;
	return sqlSession->executeQueryNumerical(sqlStr);
}
//分页查询出库单列表 负责人：小彬
list<Out_StockPagDO> Out_stockDAO::selectWithPage(const Out_StockQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT s.out_id, s.store_id,s.number,s.status,s.create_user_id,s.create_time,s.out_type,s.out_time ,t.out_user_id ,t.remarks FROM stock_out s INNER JOIN stock_out_list t ON s.out_id=t.out_id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	Out_stockMapper1 mapper;
	string sqlStr = sql.str();
	cout << sqlStr;
	return sqlSession->executeQuery<Out_StockPagDO, Out_stockMapper1>(sqlStr, mapper, params);
}
//查询出库单明细(用id查询) 负责人：小彬
list<Out_StocDetailDO> Out_stockDAO::selectById(const string& id)
{
	string sql = "SELECT t.out_id,t.store_id,t.goods_id,t.goods_name,t.sku_id,t.sku_name,t.number,t.remarks,t.out_time,f.category_name FROM stock_out_list t INNER JOIN stock_out s ON s.out_id=t.out_id INNER JOIN fly_goods_category f ON  f.category_id=t.goods_id WHERE t.out_id LIKE CONCAT('%',?,'%')";
	Out_stockMapper2 mapper;
	cout << sql;
	return sqlSession->executeQuery< Out_StocDetailDO, Out_stockMapper2>(sql, mapper, "%s", id);
}
//添加出库单 负责人：小彬
uint64_t Out_stockDAO::insert(const AddOut_StockDO& iObj)
{
	string sql = "INSERT INTO stock_out (store_id,`status`,number, out_user_id, out_type, out_time, create_user_id, create_time) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	cout << sql;
	return sqlSession->executeInsert(sql, "%s%i%i%s%s%s%i%s", iObj.getStore_Name(), iObj.getStatus(), iObj.getNumber(), iObj.getOut_Stock_Person(), iObj.getOut_Type(),
		iObj.getOut_Time(), iObj.getCreate_User_Id(), iObj.getCreate_Time());
}