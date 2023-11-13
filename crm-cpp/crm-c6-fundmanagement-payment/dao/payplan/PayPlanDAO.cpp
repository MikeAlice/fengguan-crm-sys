/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/29 14:48:13

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
#include "PayPlanDAO.h"
uint64_t PayPlanDAO::insertPayPlan(const PayPlanDTO::Wrapper dto, std::string t, uint64_t usr)
{
	std::string sql = "INSERT INTO `fin_pay_plan`(`contract_id`, `contract_name`, `supplier_id`,"
		" `supplier_name`, `money`, `plan_date`, `stages`, `create_user_id`, `create_time`)"
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%s%ull%s%ull%s%ull%ull%s", dto->contract_id.getValue({}), dto->contract_name.getValue({}),
		dto->suplier_id.getValue({}), dto->suplier_name.getValue({}),dto->money.getValue({}), dto->datee.getValue({}),dto->stage.getValue({}),usr,t);
}
