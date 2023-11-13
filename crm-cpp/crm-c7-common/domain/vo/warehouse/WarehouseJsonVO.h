#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2023/11/04 18:23:03

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
#ifndef _WAREHOUSEJSONVO_H_
#define _WAREHOUSEJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/warehouse/WarehouseDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WarehouseJsonVO : public JsonVO<List<WarehouseDTO::Wrapper>>
{
	DTO_INIT(WarehouseJsonVO, JsonVO<List<WarehouseDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WAREHOUSEJSONVO_H_