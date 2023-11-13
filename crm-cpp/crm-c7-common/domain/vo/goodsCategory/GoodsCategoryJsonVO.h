#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ·æ
 @Date: 2023/11/07 23:59:04

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
#ifndef _GOODSCATEGORYJSONVO_H_
#define _GOODSCATEGORYJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/goodsCategory/CategoryNameTreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GoodsCategoryJsonVO : public JsonVO<List<CategoryNameTreeDTO::Wrapper>>
{
    DTO_INIT(GoodsCategoryJsonVO, JsonVO<List<CategoryNameTreeDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSCATEGORYJSONVO_H_