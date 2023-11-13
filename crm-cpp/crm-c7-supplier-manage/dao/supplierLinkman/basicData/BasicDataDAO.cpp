/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2023/10/25 14:23:45

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
#include "BasicDataDAO.h"
#include "../../mapper/BasicDataMapper.h"
#include <sstream>

list<CstFieldExtDO> BasicDataDAO::selectAll()
{
	stringstream sql;
	sql << "SELECT show_name, field_name, field_type, default_value, is_must FROM cst_field_ext";
	sql << " WHERE 1=1 AND `main_table`=sup_linkman AND `ext_table`=cst_field_ext AND visible=1";
	BasicDataMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<CstFieldExtDO, BasicDataMapper>(sqlStr, mapper);
}