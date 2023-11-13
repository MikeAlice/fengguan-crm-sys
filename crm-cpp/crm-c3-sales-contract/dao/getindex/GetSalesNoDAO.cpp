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
#include "GetSalesNoDAO.h"
#include "GetSalesNoMapper.h"
#include <sstream>

std::list<SalesContractDO> GetSalesNoDAO::selectById(uint64_t contract_id)
{
	string sql = "SELECT contract_no FROM sal_contract WHERE `contract_id`=?";
	GetSalesNoMapper mapper;
	return sqlSession->executeQuery<SalesContractDO, GetSalesNoMapper>(sql, mapper, "%ull", contract_id);

}
