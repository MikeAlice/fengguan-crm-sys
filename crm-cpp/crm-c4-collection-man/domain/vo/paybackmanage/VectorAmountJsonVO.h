#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: 愿你道路悠长
 @Date: 2023/02/20 10:27:42
 @description：这里定义基础数据类型对应的响应JsonVO

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
#ifndef _VECTORINT_VO_H_
#define _VECTORINT_VO_H_
#include "domain/vo/JsonVO.h"
#include "../../query/paybackmanage/SelectAmountInfoDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 包装了SelectAmountInfoQuery
 * SelectAmountInfoQuery包含了四个UInt64
 * 分别为：
 *	总金额
 *	去零金额
 *	已经回款金额
 *	已开发票金额
 */


class VectorAmountJsonVO : public JsonVO<SelectAmountInfoDTO::Wrapper>
{
	DTO_INIT(VectorAmountJsonVO, JsonVO<SelectAmountInfoDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_BASE_JSON_VO_H_