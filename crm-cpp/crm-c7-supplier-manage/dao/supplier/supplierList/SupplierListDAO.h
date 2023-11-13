#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/10/27 17:05:59

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
#ifndef _SUPPLIERLISTDAO_H_
#define _SUPPLIERLISTDAO_H_

#include "BaseDAO.h"
#include "../../../domain/query/supplier/SupplierQuery.h"
#include "../../../domain/do/supplier/SupplierDO.h"

class SupplierListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SupplierQuery::Wrapper& query);
	// 分页查询数据
	list<SupplierDO> selectWithPage(const SupplierQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const SupplierDO& iObj);
};

#endif // !_SUPPLIERLISTDAO_H_