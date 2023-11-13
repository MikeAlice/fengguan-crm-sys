#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/25 18:23:49

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
#ifndef _UPDATE_SUPPLIER_DAO_
#define _UPDATE_SUPPLIER_DAO_
#include "BaseDAO.h"
#include "domain/do/supplier/SupplierDO.h"
#include "domain/dto/supplier/ModifySupplierDTO.h"

/**
 * 修改供应商数据库操作实现
 */
class UpdateSupplierDAO : public BaseDAO
{
public:
	// 修改数据
	int updateSupplierStatic(const SupplierDO& uObj);//修改静态字段
	int updateSupplierExtFields(const SupplierDO& uObj, const ModifySupplierDTO::Wrapper& dto);//修改扩展字段
	int updateSupplierExtFields(const SupplierDO& uObj);//修改扩展字段
};
#endif // !_UPDATE_SUPPLIER_DAO_

