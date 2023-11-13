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
#include "Other_income_statementDAO.h"
#include "Other_income_statementMapper.h"

namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：record_id！
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->record_id.getValue({});
		}
		sql << ")";
	}
	/*
	* In C++20:
	* #define insertIdList(sql, dto, varname) \
	* []<typename T>(stringstream &sql, T &dto){ \
	* sql << "("; \
	*	for (auto i = dto->begin(); i != dto->end(); i++) \
	*	{ \
	*		if (i != dto->begin())	sql << ","; \
	*		sql << (*i)->varname.getValue({}); \
	*	} \
	*	sql << ")"; \
	* }()
	*/
}

std::list<Other_income_statementDO> Other_income_statementDAO::selectWithIdList(const oatpp::List<ExpOisDTO::Wrapper>&dto)
{
	stringstream sql;
	sql << "SELECT record_id,type_id,money,bank_id,happen_date,create_user_id,create_time,intro "
		"FROM fin_income_record "
		"WHERE record_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	Other_income_statementMapper mapper;
	return sqlSession->executeQuery<Other_income_statementDO, Other_income_statementMapper>(sqlStr, mapper);
}

uint64_t Other_income_statementDAO::removeData(const oatpp::List<DelOisDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "DELETE * FROM fin_income_record "
		"WHERE record_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeUpdate(sqlStr);
}