#include "stdafx.h"
#include "DictClassifyDAO.h"
#include "DictClassifyMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define DICTCLASSIFY_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->typeName) { \
	sql << " AND `typename`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typeName.getValue("")); \
} \
if (query->typedir) { \
	sql << " AND typedir=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typedir.getValue("")); \
} \
if (query->typetag) { \
	sql << " AND typetag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typetag.getValue("")); \
} \
if (query->sort) { \
	sql << " AND sort=?"; \
	SQLPARAMS_PUSH(params, "s", int, query->sort.getValue(0)); \
}\
if (query->visible) { \
	sql << " AND visible=?"; \
	SQLPARAMS_PUSH(params, "b", int, query->visible.getValue(0)); \
}\
if (query->intro) { \
	sql << " AND intro=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intro.getValue("")); \
} \
if (query->seotitle) { \
	sql << " AND seotitle=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->seotitle.getValue(0)); \
}\
if (query->keywords) { \
	sql << " AND keywords=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->keywords.getValue(0)); \
}
#define DICTCLASSIFYLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->typetag) { \
	sql << " AND typetag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typetag.getValue("")); \
} \
if (query->typeName) { \
	sql << " AND `typename`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typeName.getValue("")); \
} 
uint64_t DictClassifyDAO::count(const DictClassifyQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `cst_dict_type`";
	DICTCLASSIFY_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<DictClassifyDO> DictClassifyDAO::selectWithPage(const DictClassifyQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,typename,typedir,typetag,sort,visible,intro,seotitle,keywords FROM cst_dict_type";
	DICTCLASSIFY_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DictClassifyMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DictClassifyDO, DictClassifyMapper>(sqlStr, mapper, params);
}
std::list<DictClassifyListDO> DictClassifyDAO::selectPage()
{
	auto query = DictClassifyListQuery::createShared();
	stringstream sql;
	sql << "SELECT id,typename,typetag FROM cst_dict_type";
	DICTCLASSIFYLIST_TERAM_PARSE(query, sql);
	DictClassifyListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DictClassifyListDO, DictClassifyListMapper>(sqlStr, mapper, params);
}
std::list<DictClassifyDO> DictClassifyDAO::selectByName(const string& name)
{
	string sql = "SELECT id,typename,typedir,typetag,sort,visible,intro,seotitle,keywords FROM cst_dict_type WHERE typename LIKE CONCAT('%',?,'%')";
	DictClassifyMapper mapper;
	return sqlSession->executeQuery<DictClassifyDO, DictClassifyMapper>(sql, mapper, "%s", name);
}
//uint64_t DictClassifyDAO::insert(const DictClassifyDO& iObj)
//{
//	string sql = "INSERT INTO `cst_dict_type` (`typeName`, `typetag`, `sort`,`visible`,`intro`,`seotitle`,`keywords`) VALUES (?, ?, ?, ?, ?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%ull%ull%s%ull%ull", iObj.getTypeName(), iObj.getTypetag(), iObj.getSort(), iObj.getVisible(), iObj.getIntro(), iObj.getSeotitle(), iObj.getKeywords());
//}
//
//int DictClassifyDAO::update(const DictClassifyDO& uObj)
//{
//	string sql = "UPDATE `cst_dict_type` SET `typeName`=?, `typetag`=?, `sort`=?,`visible`=?,`intro`=?,`seotitle`=?,`keywords`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%ull%ull%s%ull%ull", uObj.getTypeName(), uObj.getTypetag(), uObj.getSort(), uObj.getVisible(), uObj.getIntro(), uObj.getSeotitle(), uObj.getKeywords());
//}
//
//int DictClassifyDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM `cst_dict_type` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//}
uint64_t DictClassifyDAO::insert(const DictClassifyDO& iObj)
{
	string sql = "INSERT INTO `cst_dict_type` (`typename`, `typedir`,`typetag`, `sort`,`visible`,`intro`,`seotitle`,`keywords`) VALUES (?, ?, ?, ?, ?, ?, ?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%ull%ull%s%ull%ull", iObj.getTypeName(), iObj.getTypedir(), iObj.getTypetag(), iObj.getSort(), iObj.getVisible(), iObj.getIntro(), iObj.getSeotitle(), iObj.getKeywords());
}

int DictClassifyDAO::update(const DictClassifyDO& uObj)
{
string sql = "UPDATE `cst_dict_type` SET `typename`=?,`typedir`=?, `typetag`=?, `sort`=?,`visible`=?,`intro`=?,`seotitle`=?,`keywords`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%ull%ull%s%ull%ull%ull", uObj.getTypeName(), uObj.getTypedir(),uObj.getTypetag(), uObj.getSort(), uObj.getVisible(), uObj.getIntro(), uObj.getSeotitle(), uObj.getKeywords(),uObj.getId());
}

int DictClassifyDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `cst_dict_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

//list<DictClassifyListDO>DictClassifyDAO::selectWithList(const DictClassifyListQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT id,typename FROM cst_dict_type";
//	DICTCLASSIFYLIST_TERAM_PARSE(query, sql);
//	DictClassifyListMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<DictClassifyListDO, DictClassifyListMapper>(sqlStr, mapper, params);
//	
//}
