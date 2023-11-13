#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _GETSALESOPPO_DAO_
#define _GETSALESOPPO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contractindex/SalesContractDO.h"
#include "../../domain/dto/getindex/GetSalesContractNoDTO.h"
#include "dao/getindex/GetSalesNoMapper.h"

/**
 * sal_contract表数据库操作实现
 */
class GetSalesNoDAO : public BaseDAO
{
public:
	// 通过销售合同id查询数据
	list<SalesContractDO> selectById(uint64_t contract_id);
};
#endif // !_GETSALESOPPO_DAO_