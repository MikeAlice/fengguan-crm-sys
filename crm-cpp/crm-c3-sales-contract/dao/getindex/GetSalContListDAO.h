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
#ifndef _GETSALCONTLIST_DAO_H_
#define _GETSALCONTLIST_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/contractindex/SalesContractDO.h"
#include "../../domain/query/getindex/GetSalContListQuery.h"

/**
 * Cst_chance表数据库操作实现
 */
class GetSalContListDAO : public BaseDAO
{
public:
	// 通过销售机会id查询数据
	list<SalesContractDO> selectByTitle(const GetSalContListQuery::Wrapper& query);
};
#endif // !_GETSALCONTLIST_DAO_H_