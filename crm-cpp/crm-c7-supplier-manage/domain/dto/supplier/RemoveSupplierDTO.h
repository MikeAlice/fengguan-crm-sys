#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: y
 @Date: 2023/10/24 16:26:29

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
#ifndef _REMOVE_SUPPLIER_DTO_
#define _REMOVE_SUPPLIER_DTO_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "../ListDTO.h"
#include <oatpp/web/client/ApiClient.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除供应商传输对象
 * 负责人: y
 */

class RemoveSupplierDTO : public ListDTO<oatpp::UInt64>
{
	DTO_INIT(RemoveSupplierDTO, ListDTO<UInt64>);
public:	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
