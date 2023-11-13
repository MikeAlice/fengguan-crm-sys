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
#include "InvoiceDAO.h"
#include "InvoiceMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define INVOICE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pay_date) { \
	sql << " AND `pay_date`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pay_date.getValue("")); \
} \
if (query->create_time) { \
	sql << " AND create_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
} \
if (query->name) { \
	sql << " AND `contract_name` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} 

uint64_t InvoiceDAO::count(const InvoiceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_invoice_pay";
	INVOICE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<InvoiceDO> InvoiceDAO::selectWithPage(const InvoiceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT contract_name,customer_name,money,pay_date,stages,invoice_no,name,intro,create_user_id FROM fin_invoice_pay";
	INVOICE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	InvoiceMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<InvoiceDO, InvoiceMapper>(sqlStr, mapper, params);
}

std::list<InvoiceDO> InvoiceDAO::selectByName(const string& name)
{
	string sql = "SELECT contract_name,customer_name,money,pay_date,stages,invoice_no,name,intro,create_user_id FROM fin_invoice_pay WHERE `contract_name` LIKE CONCAT('%',?,'%')";
	InvoiceMapper mapper;
	return sqlSession->executeQuery<InvoiceDO, InvoiceMapper>(sql, mapper, "%s", name);
}

uint64_t InvoiceDAO::insert(const InvoiceDO& iObj)
{
	string sql = "INSERT INTO `fin_invoice_pay` ( `contract_id`, `contract_name`, `customer_id`, `customer_name`, `money`, `pay_date`, `stages`, `invoice_no`, `name`, `bus_type`, `intro`, `create_time`, `create_user_id`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ll%s%ll%s%ll%s%ll%s%s%s%s%s%ll", iObj.getContract_id(), iObj.getContract_name(), iObj.getCustomer_id(), iObj.getCustomer_name(), iObj.getMoney(), iObj.getPay_date(), iObj.getStages(), iObj.getInvoice_no(), iObj.getName(), iObj.getBus_type(), iObj.getIntro(), iObj.getCreate_time(), iObj.getCreate_user_id());
}
