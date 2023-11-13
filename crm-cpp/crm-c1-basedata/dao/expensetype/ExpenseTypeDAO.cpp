#include "stdafx.h"
#include "ExpenseTypeDAO.h"
#include "ExpenseTypeMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->parentid != 0) { \
	sql << " AND parentID=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->parentid.getValue(0)); \
} 


std::list<ExpenseDO> ExpenseDAO::selectALL()
{
	string sql = "SELECT id,name,parentID FROM  fin_expenses_type";
	ExpenseMapper mapper;
	return sqlSession->executeQuery<ExpenseDO, ExpenseMapper>(sql, mapper);
}

list<ExpenseDO> ExpenseDAO::selectTree(const ExpenseQuery::Wrapper& query)
{

	stringstream sql;
	SqlParams params;
	sql << "WITH RECURSIVE tree AS( \
				SELECT id,name,parentID,sort,visible,intro, 1 AS depth\
				FROM fin_expenses_type \
				WHERE parentID =? \
				UNION  \
				SELECT fin.id,fin.name,fin.parentID,fin.sort,fin.visible,fin.intro,t.depth+1 \
				FROM  fin_expenses_type fin JOIN tree t \
				ON t.id = fin.parentID  \
				WHERE t.depth+1<=? \
			) \
			SELECT * FROM tree; ";

	SQLPARAMS_PUSH(params, "i", int, query->parentid.getValue(0));
	SQLPARAMS_PUSH(params, "i", int, query->depth.getValue(0));
	ExpenseMapper mapper;
	string sqlStr = sql.str();
	//	std::cout << sqlStr << '\n';
	return sqlSession->executeQuery<ExpenseDO, ExpenseMapper>(sqlStr, mapper, params);
}


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->parentID) { \
	sql << " AND parentID=?"; \
	SQLPARAMS_PUSH(params, "ull", int, query->parentID.getValue(0)); \
} \
if (query->sort) { \
	sql << " AND sort=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->sort.getValue(0)); \
} \
if (query->visible) { \
		sql << " AND visible=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->visible.getValue(0)); \
} \
if (query->intro) { \
		sql << " AND intro=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->intro.getValue("")); \
} 



uint64_t ExpenseTypeDAO::count(const ExpenseTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_expenses_type";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ExpenseTypeDO> ExpenseTypeDAO::selectWithPage(const ExpenseTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,name,parentID,sort,visible,intro FROM fin_expenses_type";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ExpenseTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExpenseTypeDO, ExpenseTypeMapper>(sqlStr, mapper, params);
}

uint64_t ExpenseTypeDAO::insert(const ExpenseTypeDO& iObj)
{
	string sql = "INSERT INTO `fin_expenses_type` (`name`, `parentID`, `sort`, `visible`, `intro`) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%ull%i%i%s", iObj.getName(), iObj.getParentID(), iObj.getSort(), iObj.getVisible(), iObj.getIntro());
}


int ExpenseTypeDAO::update(const ExpenseTypeDO& uObj)
{
	string sql = "UPDATE `fin_expenses_type` SET `name`=?, `parentID`=?, `sort`=? , `visible`=?, `intro`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%ull%i%i%s%ull", uObj.getName(), uObj.getParentID(), uObj.getSort(), uObj.getVisible(), uObj.getIntro(), uObj.getId());
}

int ExpenseTypeDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `fin_expenses_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}


//uint64_t ExpenseTypeDAO::insert(const ExpenseTypeDO& iObj)
//{
//	string sql = "INSERT INTO `fin_expenses_type` (`name`, `parentID`, `sort`,`visible`,`intro`) VALUES (?, ?, ?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%ull%i%i%s", iObj.getName(), iObj.getParentID(), iObj.getSort(), iObj.getVisible(), iObj.getIntro());
//}
//int ExpenseTypeDAO::update(const ExpenseTypeDO& uObj)
//{
//	string sql = "UPDATE `fin_expenses_type` SET `name`=?, `parentID`=?, `sort`=? , `visible`=?, `intro`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%ull%i%i%s%ull", uObj.getName(), uObj.getParentID(), uObj.getSort(), uObj.getVisible(), uObj.getIntro(), uObj.getId());
//    return 0;
//}
//
//int ExpenseTypeDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM `fin_expenses_type` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//    return 0;
//}
