/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/30 10:43:26

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
#include "SelectContactNameDAO.h"
#include "SelectContactMapper.h"
#include <sstream>


std::list<ContactListDO> SelectContactNameDAO::selectByName(const string& name, const ListContactNameQuery::Wrapper& query)
{
	stringstream sql;
	SqlParams params;
	sql << "SELECT name,linkman_id FROM cst_linkman ";
	sql << " WHERE 1=1"; 
	if (query->customer_id) {			
		sql << " AND customer_id=?"; 
		SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0));
	} 
	sql << " AND `name` LIKE CONCAT('%',?,'%')";
	SQLPARAMS_PUSH(params, "s", std::string, name);
	SelectContactMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<ContactListDO, SelectContactMapper>(sqlStr, mapper, params);
}
