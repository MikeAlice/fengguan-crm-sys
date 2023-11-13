/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/24 11:52:21

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
#include "IncomeDAO.h"
#include "IncomeMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define INCOME_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->record_id) { \
	sql << " AND `record_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->record_id.getValue(0)); \
} \
if (query->type_id) { \
	sql << " AND `type_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->type_id.getValue(0)); \
} \
if (query->bank_id) { \
	sql << " AND `bank_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->bank_id.getValue(0)); \
} \
if (query->money) { \
	sql << " AND `money`=?"; \
	SQLPARAMS_PUSH(params, "d", double, query->money.getValue(0)); \
} \
if (query->intro) { \
	sql << " AND intro=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intro.getValue("")); \
} \
if (query->happen_date) { \
	sql << " AND happen_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->happen_date.getValue("")); \
} \
if (query->create_user_id) { \
	sql << " AND `create_user_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->create_user_id.getValue(0)); \
}\
if (query->create_time) { \
	sql << " AND create_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
}




uint64_t IncomeDAO::count(const IncomePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_income_record";
	INCOME_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
std::list<IncomeDO> IncomeDAO::selectWithPage(const IncomePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT record_id,type_id,bank_id,money,intro,happen_date,create_user_id,create_time FROM fin_income_record";
	INCOME_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	IncomeMapper mapper;
	string sqlStr = sql.str();
	
	return sqlSession->executeQuery<IncomeDO, IncomeMapper>(sqlStr, mapper, params);
}
/*
std::list<IncomeDO> IncomeDAO::selectByName(const string& name)
{
	string sql = "SELECT record_id,type_id,bank_id,money,intro,happen_date,create_user_id,create_time FROM fin_income_record WHERE `name` LIKE CONCAT('%',?,'%')";
	IncomeMapper mapper;
	return sqlSession->executeQuery<IncomeDO, IncomeMapper>(sql, mapper, "%s", name);
}
*/
uint64_t IncomeDAO::insert(const IncomeDO& iObj)
{
	string sql = "INSERT INTO `fin_income_record` (`record_id`,`type_id`,`bank_id`,`money`,`intro`,`happen_date`,`create_user_id`,`create_time`) VALUES(?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%ull%ull%d%s%dt%ull%dt", iObj.getRecordId(), iObj.getTypeId(), iObj.getBankId(), iObj.getMoney(), iObj.getIntro(), iObj.getHappenDate(), iObj.getCreateUserId(),iObj.getCreateTime());
}

int IncomeDAO::update(const IncomeDO& uObj)
{
	//string sql = "UPDATE `fin_income_record` SET `money`=?, `intro`=? WHERE `record_id`=?";
	//return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getMoney(), uObj.getIntro(), uObj.getRecordId());
	return 0;
}

int IncomeDAO::deleteById(uint64_t record_id)
{
	//string sql = "DELETE FROM `fin_income_record` WHERE `record_id`=?";
	//return sqlSession->executeUpdate(sql, "%ull", record_id);
	return 0;
}