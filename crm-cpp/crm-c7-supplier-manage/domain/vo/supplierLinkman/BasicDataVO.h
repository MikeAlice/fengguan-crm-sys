#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/23 17:31:18

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
#ifndef _BASICDATAVO_H_
#define _BASICDATAVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/supplierLinkman/BasicDataDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 供应商联系人表单数据项JsonVO
 * 负责人: 。好
 */
class BasicDataJsonVO : public JsonVO<BasicDataListDTO::Wrapper>
{
	DTO_INIT(BasicDataJsonVO, JsonVO<BasicDataListDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BASICDATAVO_H_