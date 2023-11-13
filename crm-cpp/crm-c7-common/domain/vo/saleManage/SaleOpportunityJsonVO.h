#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 20:19:37

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
#ifndef _SALEOPPOTUNITYJSONVO_H_
#define _SALEOPPOTUNITYJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/saleManage/SaleOpportunityDTO.h"
#include "domain/vo/JsonVO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 销售机会列表JsonVO
 * 负责人: Andrew
 */
class SaleOpportunityJsonVO : public JsonVO<SaleOpportunityListDTO::Wrapper>
{
	DTO_INIT(SaleOpportunityJsonVO, JsonVO<SaleOpportunityListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SALEOPPOTUNITYJSONVO_H_