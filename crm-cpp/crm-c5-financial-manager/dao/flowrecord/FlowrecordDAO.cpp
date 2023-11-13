#include "stdafx.h"
#include "FlowrecordDAO.h"
#include "FlowrecordMapper.h"
#include "domain/dto/flowrecord/FlowrecordDTO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define FLOW_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->bank_id) { \
	sql << " AND card LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bank_id.getValue("")); \
} \
if (query->connect_id) { \
	sql << " AND connect_id LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->connect_id.getValue("")); \
} \
if (query->create_time) { \
	sql << " AND create_time LIKE CONCAT(?,'%')"; \
	SQLPARAMS_PUSH(params, "dt", std::string, query->create_time.getValue("")); \
}
//	sql << " AND `card`=?"; 
namespace sqlHelpers {
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->bank_id.getValue({});
		}
		sql << ")";
	}
}

uint64_t FlowrecordDAO::count(const FlowrecordPageQuery::Wrapper& query)
{
	stringstream sql;
	// 输入为银行账户，但该表里没有该列，需要使用bank_id查询对应的账户
	sql << "SELECT COUNT(*) FROM fin_flow_record AS ffr "
		"LEFT JOIN fin_bank_account AS fba ON ffr.bank_id=fba.bank_id";
	FLOW_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

double FlowrecordDAO::count_total_pay(const FlowrecordPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT sum(pay_money) FROM fin_flow_record AS ffr "
		"LEFT JOIN fin_bank_account AS fba ON ffr.bank_id=fba.bank_id";
	FLOW_TERAM_PARSE(query, sql);
	DoubleMapper doublemapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	auto list = sqlSession->executeQuery<double,DoubleMapper>(sqlStr, doublemapper, params);
	return *list.begin();
}

double FlowrecordDAO::count_total_rece(const FlowrecordPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT sum(rece_money) FROM fin_flow_record AS ffr "
		"LEFT JOIN fin_bank_account AS fba ON ffr.bank_id=fba.bank_id";
	FLOW_TERAM_PARSE(query, sql);
	DoubleMapper doublemapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	auto list = sqlSession->executeQuery<double, DoubleMapper>(sqlStr, doublemapper, params);
	return *list.begin();
}

list<FlowrecordDO> FlowrecordDAO::selectWithPage(const FlowrecordPageQuery::Wrapper& query)
{
	stringstream sql;
	sql <<"SELECT fba.card,ffr.rece_money,ffr.pay_money,ffr.balance,ffr.bus_type,ffr.bus_id,fsu.name,ffr.create_time "
		"FROM fin_bank_account AS fba "
		"LEFT JOIN fin_flow_record AS ffr ON fba.bank_id=ffr.bank_id "
		"LEFT JOIN fly_sys_user AS fsu ON ffr.create_user_id=fsu.id ";
	//"SELECT " << column_list << " FROM fin_flow_record";
	FLOW_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	FlowrecordMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQuery<FlowrecordDO, FlowrecordMapper>(sqlStr, mapper, params);
}

//list<FlowrecordDO> FlowrecordDAO::selectByBankid(const string& bank_id)
//{
//	string sql = "SELECT "+ column_list+" FROM fin_flow_record WHERE `bank_id` LIKE CONCAT('%', ? , '%')";
//	FlowrecordMapper mapper;
//	return sqlSession->executeQuery<FlowrecordDO, FlowrecordMapper>(sql, mapper, "%s", bank_id);
//}
//
//list<FlowrecordDO> FlowrecordDAO::selectByCreatetime(const string& create_time)
//{
//	string sql = "SELECT " + column_list + " FROM fin_flow_record WHERE `create_time` LIKE CONCAT('%', ? , '%')";
//	FlowrecordMapper mapper;
//	return sqlSession->executeQuery<FlowrecordDO, FlowrecordMapper>(sql, mapper, "%s", create_time);
//}
//
//list<FlowrecordDO> FlowrecordDAO::selectByCreateuser(const string& create_user)
//{
//	string sql = "SELECT " + column_list + " FROM fin_flow_record WHERE `create_user_id` LIKE CONCAT('%', ? , '%')";
//	FlowrecordMapper mapper;
//	return sqlSession->executeQuery<FlowrecordDO, FlowrecordMapper>(sql, mapper, "%s", create_user);
//}

std::list<FlowrecordDO> FlowrecordDAO::select2export(const oatpp::List<FlowrecordExportDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "SELECT fba.card,ffr.rece_money,ffr.pay_money,ffr.balance,ffr.bus_type,ffr.bus_id,fsu.name,ffr.create_time "
		"FROM fin_bank_account AS fba "
		"LEFT JOIN fin_flow_record AS ffr ON fba.bank_id=ffr.bank_id "
		"LEFT JOIN fly_sys_user AS fsu ON ffr.create_user_id=fsu.id "
		"WHERE card IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	FlowrecordMapper mapper;
	return sqlSession->executeQuery<FlowrecordDO, FlowrecordMapper>(sqlStr, mapper);
}



