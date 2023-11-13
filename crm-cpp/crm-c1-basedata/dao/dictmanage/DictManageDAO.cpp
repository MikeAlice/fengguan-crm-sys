#include "stdafx.h"
#include "DictManageDAO.h"
#include "DictMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define DICT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->typetag) { \
	sql << " AND typetag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typetag.getValue("")); \
}
//����
uint64_t DictDAO::count(const DictQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cst_dict";
	DICT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//��ѯ
std::list<DictDO> DictDAO::selectWithPage(const DictQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM cst_dict";
	DICT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DictMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DictDO, DictMapper>(sqlStr, mapper, params);
}
//��ѯ���з���-��ȡ�����б�
std::list<DictTypeDO> DictDAO::selectPage()
{
	auto query = DictQuery::createShared();
	stringstream sql;
	sql << "SELECT dict_id,name FROM cst_dict";
	DICT_TERAM_PARSE(query, sql);
	DictTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DictTypeDO, DictTypeMapper>(sqlStr, mapper, params);
}
//���
uint64_t DictDAO::insert(const DictDO& iObj)
{
	string sql = "INSERT INTO `cst_dict` (`name`, `typetag`, `sort`, `visible`) VALUES (?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i%i", iObj.getName(), iObj.getTypetag(), iObj.getSort(), iObj.getVisible());
}
//�޸�
int DictDAO::update(const DictDO& uObj)
{
	string sql = "UPDATE `cst_dict` SET `name`=?, `typetag`=?, `sort`=?, `visible`=? WHERE `dict_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%i%ull", uObj.getName(), uObj.getTypetag(), uObj.getSort(), uObj.getVisible(), uObj.getId()); //ID��uint64_t�� ʹ��ull��ȡ
}
//ɾ��
int DictDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `cst_dict` WHERE `dict_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}