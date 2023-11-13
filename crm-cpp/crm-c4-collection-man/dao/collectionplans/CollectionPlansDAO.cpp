#include "stdafx.h"
#include "CollectionPlansDAO.h"
#include <sstream>
#include "CollectionPlansMapper.h"
//定义条件解析宏，减少重复代码
#define COLLECTIONPLANS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->backdate) { \
	sql << " AND `plan_date` <= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->backdate.getValue("")); \
} \
if (query->createdate) { \
	sql << " AND create_time <= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->createdate.getValue("")); \
} \
if (query->ifpay) { \
	sql << " AND ifpay=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ifpay.getValue("")); \
} \
if (query->contract_name) { \
	sql << " AND contract_name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_name.getValue("")); \
}

uint64_t CollectionPlansDAO::count(const CollectionPlansQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_rece_plan";
	COLLECTIONPLANS_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<GetCollectionPlanListDO> CollectionPlansDAO::selectWithPage(const CollectionPlansQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT customer_name,contract_name,plan_date,stages,money,create_user_id,create_time,ifpay FROM fin_rece_plan";
	COLLECTIONPLANS_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CollectionPlansMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetCollectionPlanListDO, CollectionPlansMapper>(sqlStr, mapper, params);
}

uint64_t CollectionPlansDAO::insert(const GetCollectionPlanListDO& iObj)
{
	string sql = "INSERT INTO `fin_rece_plan` (`customer_id`,`customer_name`, `contract_name`,`contract_id`, `plan_date`, `stages`, `money`,`create_user_id`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ? )";
	return sqlSession->executeInsert(sql, "%i%s%s%i%s%i%i%i%s", iObj.getCustomer_id(), iObj.getCustomer_name(), iObj.getContract_name(), iObj.getContract_id(), iObj.getPlan_date(), iObj.getStages(), iObj.getMoney(), iObj.getCreate_user_id(), iObj.getCreate_time());
}