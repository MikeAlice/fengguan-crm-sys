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
#include "AddPayRecordDAO.h"
#include "ContractMapper.h"
#include "SupplierMapper.h"
#include <sstream>
#include <string.h>
#include <time.h>

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


uint64_t AddPayRecordDAO::insert(const AddPayRecordDO & iObj)
{
	time_t t = time(0); // ��ȡ����ʱ��
	std::tm* timinfo = localtime(&t); // ת��Ϊ����ʱ���tm�ṹ��
	std::stringstream ss; // ����һ���ַ���������
	ss << std::put_time(timinfo, "%Y-%m-%d-%H-%M"); // ��tm�ṹ���ʽ��Ϊ�ַ�����
	std::string str = ss.str(); // ���ַ������л�ȡ�ַ���
	string sql = "INSERT INTO `fin_pay_record` (record_id,plan_id, contract_id, contract_name, supplier_id, supplier_name, bank_id, pay_date, money, zero_money, stages, intro, create_time, create_user_id) VALUES (NULL, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%i%i%s%i%s%i%s%s%s%i%s%s%i", iObj.getPlanId(), iObj.getContractId(), iObj.getContractName(), iObj.getSupplierId(), iObj.getSupplierName(), iObj.getBankId(), iObj.getPayDate(), iObj.getMoney(), iObj.getZeroMoney(), iObj.getStages(), iObj.getIntro(), str, iObj.getCreateUserId());
}


std::list<AddPayRecordDO> AddPayRecordDAO ::selectContractNameById(const AddPayRecordDO& iObj) {
	ContractMapper mapper; 
	std :: string sql = "SELECT DISTINCT contract_name FROM `fin_rece_record` WHERE contract_id =  ?;";
	//std :: string sql = "SELECT DISTINCT contract_id FROM `fin_rece_record` WHERE contract_name =  ?;";
	list<AddPayRecordDO> result = sqlSession->executeQuery<AddPayRecordDO, ContractMapper>(sql, mapper, "%i", iObj.getContractId());
	if (result.empty())
	{
		cout << "���б�1" << endl;
	}
	else return result;
}
std::list<AddPayRecordDO> AddPayRecordDAO::selectSupplierNameById(const AddPayRecordDO& iObj) {
	SupplierMapper mapper;
	string sql = "SELECT DISTINCT supplier_name FROM `fin_pay_record`WHERE supplier_id =  ?;";
	//string sql = "SELECT DISTINCT supplier_id FROM `fin_pay_record`WHERE supplier_name =  ?;";
	list<AddPayRecordDO> result = sqlSession->executeQuery<AddPayRecordDO, SupplierMapper>(sql, mapper, "%i", iObj.getSupplierId());
	if (result.empty())
	{
		cout << "���б�2" << endl;
	}
	else return result;
}

std::list<AddPayRecordDO> AddPayRecordDAO::selectContractNameByName(const AddPayRecordDO& iObj) {
	ContractMapper mapper;
	//std :: string sql = "SELECT DISTINCT contract_name FROM `fin_rece_record` WHERE contract_id =  ?;";
	std::string sql = "SELECT DISTINCT contract_id ,contract_name FROM `fin_rece_record` WHERE contract_name LIKE CONCAT('%',?,'%'); ";
	//list<AddPayRecordDO> result = sqlSession->executeQuery<AddPayRecordDO, ContractMapper>(sql, mapper, "%i", iObj.getContractId());
	list<AddPayRecordDO> result = sqlSession->executeQuery<AddPayRecordDO, ContractMapper>(sql, mapper, "%s", iObj.getContractName());
	return result;
}

std::list<AddPayRecordDO> AddPayRecordDAO ::selectSupplierNameByName(const AddPayRecordDO & iObj) {
	SupplierMapper mapper;
//	std::string sql = "SELECT DISTINCT supplier_name FROM `fin_pay_record`WHERE supplier_id =  ?;";
	std::string sql = "SELECT DISTINCT supplier_id,supplier_name FROM `fin_pay_record`WHERE supplier_name LIKE CONCAT('%',?,'%');";
	list<AddPayRecordDO> result = sqlSession->executeQuery<AddPayRecordDO, SupplierMapper>(sql, mapper, "%s",iObj.getSupplierName());
	return result;
}
