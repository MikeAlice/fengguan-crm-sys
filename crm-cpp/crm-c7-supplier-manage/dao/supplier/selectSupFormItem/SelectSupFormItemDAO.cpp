/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 16:36:30

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
#include "SelectSupFormItemDAO.h"
#include "dao/mapper/CstFieldExtMapper.h"

std::list<CstFieldExtDO> SelectSupFormItemDAO::selectSupFormItem(const SupFormItemQuery::Wrapper& query)
{
	// 构建sql语句
	stringstream sql;
	sql << "SELECT show_name, field_name, field_type, default_value, is_must FROM cst_field_ext";
	sql << " WHERE 1=1 AND `main_table`=? AND `ext_table`=? AND visible=1";
	// 构建mapper
	CstFieldExtMapper mapper;
	std::string sql_str = sql.str();
	// 返回结果, 调用va_list方法静态填充条件
	return sqlSession->executeQuery<CstFieldExtDO, CstFieldExtMapper>(sql_str, mapper, "%s%s", query->main_table.getValue(""), query->main_table.getValue(""));
}
