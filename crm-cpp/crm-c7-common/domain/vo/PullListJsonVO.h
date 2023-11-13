#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/31 22:59:48

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
#ifndef _PULLLISTJSONVO_H_
#define _PULLLISTJSONVO_H_

#include "../GlobalInclude.h"
#include "domain/vo/JsonVO.h"
#include "../dto/PullListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б���JsonVO
 * ������: Andrew
 */
class PullListJsonVO : public JsonVO<PullListDTO::Wrapper>
{
	DTO_INIT(PullListJsonVO, JsonVO<PullListDTO::Wrapper>);
};

class PullListArrayJsonVO : public JsonVO<List<PullListItemDTO::Wrapper>>
{
	DTO_INIT(PullListArrayJsonVO, JsonVO<List<PullListItemDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PULLLISTJSONVO_H_