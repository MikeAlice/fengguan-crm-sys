#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: telephone
 @Date: 2023/10/23 18:20:31

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
#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../GlobalInclude.h"
#include "domain/vo/JsonVO.h"
#include "../../dto/supplierLinkman/SupplierLinkmanDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页显示供应商联系人列表JsonVO，用于响应给客户端的Json对象
 * 负责人: telephone
 */
class SupplierLinkmanPageJsonVO : public JsonVO<SupplierLinkmanPageDTO::Wrapper> {
	DTO_INIT(SupplierLinkmanPageJsonVO, JsonVO<SupplierLinkmanPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
