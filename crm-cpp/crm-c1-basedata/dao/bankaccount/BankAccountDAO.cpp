#include "stdafx.h"
#include "BankAccountDAO.h"
#include "BankAccountMapper.h"
#include"domain/dto/bankaccount/BankAccountDTO.h"
#include <sstream>

//namespace sqlHelpers {
//	template<typename T>
//	void insertIdList(stringstream& sql, T& dto)
//	{
//		sql << "(";
//		for (auto i = dto->begin(); i != dto->end(); i++)
//		{
//			if (i != dto->begin())	sql << ",";
//			sql << (*i)->bank_id.getValue({});
//			sql << (*i)->name.getValue({});
//			sql << (*i)->card.getValue({});
//			sql << (*i)->holders.getValue({});
//			sql << (*i)->address.getValue({});
//		}
//		sql << ")";
//	}
//}
//定义条件解析宏，减少重复代码
#define BANKACCOUNT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->card) { \
	sql << " AND card=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->card.getValue(0)); \
} \
if (query->address) { \
	sql << " AND address=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->address.getValue("")); \
}\
if (query->holders) { \
	sql << " AND holders=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->holders.getValue("")); \
}\
if (query->sort) { \
	sql << " AND sort=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->sort.getValue(0)); \
} \
if (query->visible) { \
	sql << " AND visible=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->visible.getValue(0)); \
}
#define BANKACCOUNTLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->card) { \
	sql << " AND card=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->card.getValue(0)); \
}

uint64_t BankAccountDAO::count(const BankAccountQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_bank_account";
	BANKACCOUNT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<BankAccountDO> BankAccountDAO::selectWithPage(const BankAccountQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT bank_id,name,card,address,holders,sort,visible FROM fin_bank_account";
	BANKACCOUNT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	BankAccountMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BankAccountDO, BankAccountMapper>(sqlStr, mapper, params);
}
list<BankAccountListDO> BankAccountDAO::selectWithList(const BankAccountListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT bank_id,name,card FROM fin_bank_account";
	BANKACCOUNTLIST_TERAM_PARSE(query, sql);
	BankAccountListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BankAccountListDO, BankAccountListMapper>(sqlStr, mapper, params);
}
std::list<BankAccountDO> BankAccountDAO::selectByName(const string& name)
{
	string sql = "SELECT bank_id,name,card,address,holders,sort,visible FROM `fin_bank_account`WHERE name LIKE CONCAT('%',?,'%')";
	BankAccountMapper mapper;
	return sqlSession->executeQuery<BankAccountDO, BankAccountMapper>(sql, mapper, "%s", name);
}
uint64_t BankAccountDAO::insert(const BankAccountDO& iObj)
{
	string sql = "INSERT INTO `fin_bank_account` (`name`, `card`, `address`,`holders`,`sort`,`visible`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%ull%s%s%ull%ull", iObj.getName(), iObj.getCard(), iObj.getAddress(), iObj.getHolders(), iObj.getSort(), iObj.getVisible());
}

int BankAccountDAO::update(const BankAccountDO& uObj)
{
	string sql = "UPDATE `fin_bank_account` SET `name`=?, `card`=?, `address`=?,`holders`=?,`sort`=?,`visible`=? WHERE `bank_id`=?";
	return sqlSession->executeUpdate(sql, "%s%ull%s%s%ull%ull%ull", uObj.getName(), uObj.getCard(), uObj.getAddress(), uObj.getHolders(), uObj.getSort(),uObj.getVisible(),uObj.getBank_id());
}

int BankAccountDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `fin_bank_account` WHERE `bank_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

std::list<BankAccountDO> BankAccountDAO::selectexport(const oatpp::List<BankAccountExportDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "SELECT bank_id,name,card,address,holders,sort,visible FROM fin_bank_account";

	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	BankAccountMapper mapper;
	return sqlSession->executeQuery<BankAccountDO, BankAccountMapper>(sqlStr, mapper);
}
std::list<BankAccountListDO> BankAccountDAO::selectPage()
{
	auto query = BankAccountListQuery::createShared();
	stringstream sql;
	sql << "SELECT bank_id,name,card FROM fin_bank_account";
	BANKACCOUNTLIST_TERAM_PARSE(query, sql);
	BankAccountListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BankAccountListDO, BankAccountListMapper>(sqlStr, mapper, params);
}