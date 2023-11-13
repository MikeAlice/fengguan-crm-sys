#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: y
 @Date: 2023/10/27 21:08:56

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
#ifndef _REMOVE_SUPPLIER_SERVICE_
#define _REMOVE_SUPPLIER_SERVICE_


#include "domain/dto/supplier/RemoveSupplierDTO.h"
#include <list>

class RemoveSupplierService
{
public:
	// 通过ID删除数据
	bool removeSupplierData(const RemoveSupplierDTO::Wrapper& dto);
};

#endif // !_REMOVE_SUPPLIER_SERVICE_

