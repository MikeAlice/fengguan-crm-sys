#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/26 20:40:49

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
#ifndef _SELECT_SUPPLIER_NAME_DAO_
#define _SELECT_SUPPLIER_NAME_DAO_
#include "BaseDAO.h"
#include "domain/do/supplier/SupplierDO.h"
#include "domain/query/supplier/SupplierNameQuery.h"

/**
 * 示例表数据库操作实现
 */
class SelectSupplierNameDAO : public BaseDAO
{
public:
#if 0
	// 分页查询数据
	list<SupplierDO> selectWithPage(const SupplierNameQuery::Wrapper& query);
#endif
	// 通过姓名查询数据
	list<SupplierDO> selectSupplierName(const SupplierNameQuery::Wrapper& query);
};
#endif // !_SELECT_SUPPLIER_NAME_DAO_
