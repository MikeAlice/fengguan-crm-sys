/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/26 21:06:52

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
#include "SelectSupplierNameDAO.h"
#include "dao/mapper/SupplierNameMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
}

#if 0
std::list<SupplierDO> SelectSupplierNameDAO::selectWithPage(const SupplierNameQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT id,name,sex,age FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	SampleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sqlStr, mapper, params);
}
#endif

std::list<SupplierDO> SelectSupplierNameDAO::selectSupplierName(const SupplierNameQuery::Wrapper& query)
{
	string sql = "SELECT supplier_id, name FROM sup_supplier WHERE `name` LIKE CONCAT('%',?,'%')";
	//string sql = "SELECT name FROM sup_supplier WHERE `name` LIKE CONCAT('%',?,'%')";
	SupplierNameMapper mapper;
	return sqlSession->executeQuery<SupplierDO, SupplierNameMapper>(sql, mapper, "%s", query->name.getValue(""));
}
