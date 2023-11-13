/*
 Copyright Zero One Star. All rights reserved.


 @Author: awei
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
#include "ConfirmRemovePayDAO.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

int ConfirmRemovePayDAO::update(uint64_t id)
{
	string sql = "UPDATE `fin_pay_plan` SET `ifpay`=1 WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ConfirmRemovePayDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `fin_pay_plan` WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
