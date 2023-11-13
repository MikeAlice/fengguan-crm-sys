#include "stdafx.h"
#include "FeeIncomeDAO.h"
#include "FeeIncomeMapper.h"
#include <sstream>
// 定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->parentID) { \
	sql << " AND parentID=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->parentID.getValue(0)); \
} \
if (query->sort) { \
	sql << " AND sort=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->sort.getValue(0)); \
} \
if (query->visible) { \
	sql << " AND visible=?"; \
	SQLPARAMS_PUSH(params, "i", int32_t, query->visible.getValue(0)); \
} \
if (query->intro) { \
	sql << " AND intro=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intro.getValue("")); \
}
// 统计数据条数
uint64_t FeeIncomeDAO::count(const FeeIncomeQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_income_type";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询数据
std::list<FeeIncomeDO> FeeIncomeDAO::selectWithPage(const FeeIncomeQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT id,name,parenID,sort,visible,intro FROM fin_income_type";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	FeeIncomeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<FeeIncomeDO, FeeIncomeMapper>(sqlStr, mapper, params);
}
uint64_t FeeIncomeDAO::insert(const FeeIncomeDO & iObj)
{
	string sql = "INSERT INTO `fin_expenses_type` (`name`, `parentID`, `sort`,`visible`,`intro`) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%ull%ull%i%s", iObj.getName(), iObj.getParentid(), iObj.getSort(), iObj.getVisible(), iObj.getIntro());
	
}

int FeeIncomeDAO::update(const FeeIncomeDO & uObj)
{
	string sql = "UPDATE `fin_expenses_type` SET `name`=?, `parentID`=?, `sort`=? , `visible`=?, `intro`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%ull%%ull%s%ull", uObj.getName(), uObj.getParentid(), uObj.getSort(), uObj.getVisible(), uObj.getIntro(), uObj.getId());
}

int FeeIncomeDAO::deleteById(uint64_t id)
{

	return sqlSession->executeUpdate("1");
}

std::list<FeeIncomeDO> FeeIncomeDAO::selectALL()
{
	string sql = "SELECT id,name,parentID FROM fin_income_type";
	FeeIncomeMapper mapper;
	return sqlSession->executeQuery<FeeIncomeDO, FeeIncomeMapper>(sql, mapper);
}

list<FeeIncomeDO> FeeIncomeDAO::selectTree(const FeeIncomeQuery::Wrapper& query)
{

	stringstream sql;
	SqlParams params;
	sql << "WITH RECURSIVE tree AS( \
				SELECT id,name,parentID,sort,visible,intro, 1 AS depth\
				FROM fin_income_type \
				WHERE parentID =? \
				UNION  \
				SELECT fin.id,fin.name,fin.parentID,fin.sort,fin.visible,fin.intro,t.depth+1 \
				FROM fin_income_type fin JOIN tree t \
				ON t.id = fin.parentID  \
				WHERE t.depth+1<=? \
			) \
			SELECT * FROM tree; ";
	
	SQLPARAMS_PUSH(params, "i", int, query->parentid.getValue(0));
	SQLPARAMS_PUSH(params, "i", int, query->depth.getValue(0));
	FeeIncomeMapper mapper;
	string sqlStr = sql.str();
//	std::cout << sqlStr << '\n';
	return sqlSession->executeQuery<FeeIncomeDO, FeeIncomeMapper>(sqlStr, mapper,params);
}
