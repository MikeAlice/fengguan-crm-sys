#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 11:34:14

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
#ifndef _SUPPLIER_NAME_VO_
#define _SUPPLIER_NAME_VO_

#include "../../GlobalInclude.h"
#include "../../dto/supplierManage/SupplierNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 供应商名称列表JsonVO，用于响应给客户端的Json对象
 * 负责人: Juno
 */
class SupplierNameJsonVO : public JsonVO<SupplierNameListDTO::Wrapper> {
	DTO_INIT(SupplierNameJsonVO, JsonVO<SupplierNameListDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
