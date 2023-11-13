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
#include "UpdatePayPlanDAO.h"
#include "ContractMapper.h"
#include "SupplierMapper.h"
#include <sstream>
#include <string.h>
#include <time.h>

//定义条件解析宏，减少重复代码
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


uint64_t UpdatePayPlanDAO::update(const UpdatePayPlanDO& iObj)
{
	string sql = "UPDATE `fin_pay_plan`SET contract_id = ?, contract_name = ?, supplier_id =?, supplier_name = ?, plan_date = ?, money = ?, stages =? where plan_id = ?";
	return sqlSession->executeUpdate(sql, "%i%s%i%s%s%s%i%i", iObj.getContractId(), iObj.getContractName(), iObj.getSupplierId(), iObj.getSupplierName(),iObj.getPlanDate(), iObj.getMoney(),iObj.getStages(),iObj.getPlanId());
}


std::list<UpdatePayPlanDO> UpdatePayPlanDAO::selectContractNameById(const UpdatePayPlanDO& iObj) {
	ContractMapper mapper;
	std::string sql = "SELECT DISTINCT contract_name FROM `fin_rece_record` WHERE contract_id =  ?;";
	//std :: string sql = "SELECT DISTINCT contract_id FROM `fin_rece_record` WHERE contract_name =  ?;";
	list<UpdatePayPlanDO> result = sqlSession->executeQuery<UpdatePayPlanDO, ContractMapper>(sql, mapper, "%i", iObj.getContractId());
	if (result.empty())
	{
		cout << "空列表1" << endl;
	}
	else return result;
}
std::list<UpdatePayPlanDO> UpdatePayPlanDAO::selectSupplierNameById(const UpdatePayPlanDO& iObj) {
	SupplierMapper mapper;
	string sql = "SELECT DISTINCT supplier_name FROM `fin_pay_record`WHERE supplier_id =  ?;";
	//string sql = "SELECT DISTINCT supplier_id FROM `fin_pay_record`WHERE supplier_name =  ?;";
	list<UpdatePayPlanDO> result = sqlSession->executeQuery<UpdatePayPlanDO, SupplierMapper>(sql, mapper, "%i", iObj.getSupplierId());
	if (result.empty())
	{
		cout << "空列表2" << endl;
	}
	else return result;
}

std::list<UpdatePayPlanDO> UpdatePayPlanDAO::selectContractNameByName(const UpdatePayPlanDO& iObj) {
	ContractMapper mapper;
	//std :: string sql = "SELECT DISTINCT contract_name FROM `fin_rece_record` WHERE contract_id =  ?;";
	std::string sql = "SELECT DISTINCT contract_id ,contract_name FROM `fin_rece_record` WHERE contract_name LIKE CONCAT('%',?,'%'); ";
	//list<AddPayRecordDO> result = sqlSession->executeQuery<AddPayRecordDO, ContractMapper>(sql, mapper, "%i", iObj.getContractId());
	list<UpdatePayPlanDO> result = sqlSession->executeQuery<UpdatePayPlanDO, ContractMapper>(sql, mapper, "%s", iObj.getContractName());
	return result;
}

std::list<UpdatePayPlanDO> UpdatePayPlanDAO::selectSupplierNameByName(const UpdatePayPlanDO& iObj) {
	SupplierMapper mapper;
	//	std::string sql = "SELECT DISTINCT supplier_name FROM `fin_pay_record`WHERE supplier_id =  ?;";
	std::string sql = "SELECT DISTINCT supplier_id,supplier_name FROM `fin_pay_record`WHERE supplier_name LIKE CONCAT('%',?,'%');";
	list<UpdatePayPlanDO> result = sqlSession->executeQuery<UpdatePayPlanDO, SupplierMapper>(sql, mapper, "%s", iObj.getSupplierName());
	return result;
}
