#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/26 20:28:07

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
#ifndef _GET_SUPPLIER_NAME_SERVICE_
#define _GET_SUPPLIER_NAME_SERVICE_

#include <list>
#include "domain/dto/supplier/SupplierNameDTO.h"
#include "domain/query/supplier/SupplierNameQuery.h"

/**
 * 获取供应商名称列表Service
 * 负责人: Juno
 */
class ListSupplierNameService
{
public:
	SupplierNameListDTO::Wrapper listAll(const SupplierNameQuery::Wrapper& query);
};

#endif // !_GET_SUPPLIER_NAME_SERVICE_
