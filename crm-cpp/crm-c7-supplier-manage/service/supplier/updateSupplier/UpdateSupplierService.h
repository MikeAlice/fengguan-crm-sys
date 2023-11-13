#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/25 18:08:56

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
#ifndef _UPDATE_SUPPLIER_SERVICE_
#define _UPDATE_SUPPLIER_SERVICE_
#include "domain/dto/supplier/ModifySupplierDTO.h"

/**
 * 修改供应商服务实现
 */
class UpdateSupplierService
{
public:
	// 修改数据
	bool updateSupplierData(const ModifySupplierDTO::Wrapper& dto);
};

#endif // !_UPDATE_SUPPLIER_SERVICE_


