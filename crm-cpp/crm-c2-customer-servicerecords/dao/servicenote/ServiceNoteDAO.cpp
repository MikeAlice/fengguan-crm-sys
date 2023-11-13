/*
 Copyright Zero One Star. All rights reserved.

 @Author: huipaodeyu
 @Date: 2023/10/25 10:36:07

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
#include "ServiceNoteDAO.h"
#include "ServiceNoteMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->customer_name) { \
		sql << " AND c.name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->customer_name.getValue("")); \
}\
if (query->content) {\
		sql << " AND s.content LIKE CONCAT('%',?,'%')"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->content.getValue("")); \
}
//sql << " AND s.customer_id=c.customer_id ";
//if (query->customer_id) {
//	\
//		sql << "  AND s.customer_id =?"; \
//		SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0)); \
//} \

uint64_t ServiceNoteDAO::count(const ServiceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cst_service s LEFT JOIN cst_customer c on s.customer_id = c.customer_id";
	//sql << "SELECT COUNT(*) FROM cst_service s,cst_customer c";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	//std::cout << sqlStr;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ServiceDO> ServiceNoteDAO::selectWithPage(const ServiceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT s.service_id,s.services,s.customer_id,s.servicesmodel,s.service_time,s.tlen,s.content,c.name \
			FROM cst_service s LEFT JOIN cst_customer c on s.customer_id = c.customer_id";
	/*sql << "SELECT s.customer_id,s.services,s.servicesmodel,s.service_time,s.tlen,s.content,c.name \
	FROM cst_service s,cst_customer c";*/
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ServiceNoteMapper mapper;
	string sqlStr = sql.str();
	std::cout << sqlStr;
	return sqlSession->executeQuery<ServiceDO, ServiceNoteMapper>(sqlStr, mapper, params);
}

