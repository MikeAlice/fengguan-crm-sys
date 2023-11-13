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
#include "ExportServiceNoteDAO.h"
#include "ExportServiceNoteMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->customer_id) { \
	sql << " AND s.customer_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0)); \
} \
//if (query->service_id) { \
//	sql << " AND s.service_id=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->service_id.getValue(0)); \
//}
//sql << " AND s.customer_id=c.customer_id";
//if (query->sex) { \
//	sql << " AND sex=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
//} \
//if (query->age) { \
//	sql << " AND age=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
//}
//SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0)); \
//SQLPARAMS_PUSH(params, "ull", uint64_t, query->create_user_id.getValue(0)); \

std::list<ServiceDO> ExportServiceNoteDAO::selectAll(const ExportServiceNoteQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT s.customer_id,s.services,s.servicesmodel,s.service_time,s.tlen,s.content,c.name FROM cst_service s,cst_customer c";
	sql << "SELECT s.customer_id,s.services,s.servicesmodel,s.service_time,s.tlen,s.content,c.name,c1.name\
			FROM cst_service s\
			LEFT JOIN cst_customer c ON s.customer_id = c.customer_id \
			LEFT JOIN cst_customer c1 ON s.customer_id = c1.customer_id";
	SAMPLE_TERAM_PARSE(query, sql);
	/*if (query->service_id_list) {
		auto it = query->service_id_list.getPtr()->begin();
		while (*it) {
			sql << " OR s.service_id=?";
			SQLPARAMS_PUSH(params, "i", int, it->getValue(0));
			it++;
		}
	}*/
	if (query->service_id_list) {
		for (auto id : *(query->service_id_list.getPtr())) {
			sql << " OR s.service_id=?";
			SQLPARAMS_PUSH(params, "i", int, id);
		}
	}
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ExportServiceNoteMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ServiceDO, ExportServiceNoteMapper>(sqlStr, mapper, params);
}

