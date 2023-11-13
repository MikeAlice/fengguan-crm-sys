/*
 @Author: linglan
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include <sstream>
#include "PaymentPlanDAO.h"
#include "domain/query/payment_plan/PaymentPlanQuery.h"
#include "domain/do/payment_plan/PaymentPlanDO.h"
#include "PaymentPlanMapper.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_id) { \
	sql << " AND `plan_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->plan_id.getValue(0)); \
} \
if (query->contract_name) { \
	sql << " AND contract_name LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->contract_name.getValue("") + "%"); \
} \
if (query->supplier_id) { \
	sql << " AND supplier_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->supplier_id.getValue(0)); \
} \
if (query->supplier_name) { \
	sql << " AND supplier_name LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->supplier_name.getValue("") + "%"); \
} \
if (query->money) { \
	sql << " AND money=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} \
if (query->plan_date) { \
	sql << " AND plan_date>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->plan_date.getValue("")); \
} \
if (query->ifpay) { \
	sql << " AND ifpay=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ifpay.getValue("")); \
} \
if (query->create_time) { \
	sql << " AND create_time>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
} 

uint64_t PaymentPlanDAO::count(const PaymentPlanQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_pay_plan";
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

std::list<PaymentPlanDO> PaymentPlanDAO::selectWithPage(const PaymentPlanQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM fin_pay_plan";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PaymentPlanMapper mapper;
	string sqlStr = sql.str();
	cout << "sql:" << sqlStr << endl;
	return sqlSession->executeQuery<PaymentPlanDO, PaymentPlanMapper>(sqlStr, mapper, params);
}

