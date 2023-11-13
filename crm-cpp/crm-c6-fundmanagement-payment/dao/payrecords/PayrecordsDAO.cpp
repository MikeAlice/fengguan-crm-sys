#include "stdafx.h"
#include <sstream>
#include "PayrecordsDAO.h"
#include "domain/query/payrecords/PayrecordsQuery.h"
#include "domain/do/payrecords/PayrecordsDO.h"
#include "PayrecordsMapper.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->contract_name) { \
	sql << " AND contract_name LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->contract_name.getValue("") + "%"); \
} \
if (query->supplier_name) { \
	sql << " AND supplier_name LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->supplier_name.getValue("") + "%"); \
} \
if (query->money) { \
	sql << " AND money=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} \
if (query->pay_date) { \
	sql << " AND pay_date>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pay_date.getValue("")); \
} \
if (query->create_time) { \
	sql << " AND create_time>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
} \
if (query->stages) { \
	sql << " AND stages=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->stages.getValue(0)); \
} \
if (query->zero_money) { \
	sql << " AND zero_money=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->zero_money.getValue(0)); \
} \
if (query->create_user_id) { \
	sql << " AND create_user_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->create_user_id.getValue(0)); \
} \
if (query->intro) { \
	sql << " AND intro>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intro.getValue("")); \
} \
if (query->record_id) { \
	sql << " AND record_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->record_id.getValue(0)); \
} \
if (query->plan_id) { \
	sql << " AND plan_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->plan_id.getValue(0)); \
} \
if (query->contract_id) { \
	sql << " AND contract_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->contract_id.getValue(0)); \
} \
if (query->supplier_id) { \
	sql << " AND supplier_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->supplier_id.getValue(0)); \
} \
if (query->bank_id) { \
	sql << " AND bank_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->bank_id.getValue(0)); \
} \

uint64_t PayrecordsDAO::count(const PayrecordsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_pay_record";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	//cout << query->plan_id.getValue(0)<<endl;
	cout << "sql:" << sqlStr << endl;
	//cout << params.data() << endl;
	//for (auto& param : params) {
	//	cout << "key:"<< param.key << "value:" << param.value << endl;
	//}
	auto result = sqlSession->executeQueryNumerical(sqlStr, params);
	cout << "count:" << result << endl;
	return result;
}

std::list<PayrecordsDO> PayrecordsDAO::selectWithPage(const PayrecordsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM fin_pay_record";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PayrecordsMapper mapper;
	string sqlStr = sql.str();
	cout << "sql:" << sqlStr << endl;
	return sqlSession->executeQuery<PayrecordsDO, PayrecordsMapper>(sqlStr, mapper, params);
}
// 通过付款时间查询数据
std::list<PayrecordsDO> PayrecordsDAO::selectByPay_date(const string& pay_date)
{
	string sql = "SELECT * FROM fin_pay_record WHERE `pay_date` LIKE CONCAT('%',?,'%')";
	PayrecordsMapper mapper;
	return sqlSession->executeQuery<PayrecordsDO, PayrecordsMapper>(sql, mapper, "%s", pay_date);
}
// 通过创建时间查询数据
std::list<PayrecordsDO> PayrecordsDAO::selectByCreate_time(const string& create_time)
{
	string sql = "SELECT * FROM fin_pay_record WHERE `create_time` LIKE CONCAT('%',?,'%')";
	PayrecordsMapper mapper;
	return sqlSession->executeQuery<PayrecordsDO, PayrecordsMapper>(sql, mapper, "%s", create_time);
}
// 通过采购合同名称查询数据
std::list<PayrecordsDO> PayrecordsDAO::selectByContract_name(const string& contract_name)
{
	string sql = "SELECT * FROM fin_pay_record WHERE `pay_date` LIKE CONCAT('%',?,'%')";
	PayrecordsMapper mapper;
	return sqlSession->executeQuery<PayrecordsDO, PayrecordsMapper>(sql, mapper, "%s", contract_name);
}
// 通过供应商名称查询数据
std::list<PayrecordsDO> PayrecordsDAO::selectBySupplier_name(const string& supplier_name)
{
	string sql = "SELECT * FROM fin_pay_record WHERE `supplier_name` LIKE CONCAT('%',?,'%')";
	PayrecordsMapper mapper;
	return sqlSession->executeQuery<PayrecordsDO, PayrecordsMapper>(sql, mapper, "%s", supplier_name);
}
// 通过付款金额查询数据
std::list<PayrecordsDO> PayrecordsDAO::selectByMoney(const uint64_t money)
{
	string sql = "SELECT * FROM fin_pay_record WHERE money = ?";
	PayrecordsMapper mapper;
	return sqlSession->executeQuery<PayrecordsDO, PayrecordsMapper>(sql, mapper, "%i", money);
}