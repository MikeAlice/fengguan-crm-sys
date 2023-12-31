#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/11/04 18:21:36

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
#ifndef _WAREHOUSEDTO_H_
#define _WAREHOUSEDTO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取仓库名称列表传输对象
 * 负责人：。好
 */
class WarehouseDTO : public oatpp::DTO
{
	DTO_INIT(WarehouseDTO, DTO)
	// 仓库名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("common-usage.warehouse.field.name"))
	// 仓库Id
	API_DTO_FIELD_DEFAULT(UInt32, storeId, ZH_WORDS_GETTER("common-usage.warehouse.field.id"))
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WAREHOUSEDTO_H_