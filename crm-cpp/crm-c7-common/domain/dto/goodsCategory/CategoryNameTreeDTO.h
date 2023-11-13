#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ·æ
 @Date: 2023/11/07 23:42:17

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
#ifndef _CATEGORYNAMETREEDTO_H_
#define _CATEGORYNAMETREEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CategoryNameTreeDTO : public oatpp::DTO
{
    DTO_INIT(CategoryNameTreeDTO, DTO);
    
	API_DTO_FIELD_DEFAULT(Int32, id, ZH_WORDS_GETTER("goods-manage.goods-category.field.id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("goods-manage.goods-category.field.name"));
    API_DTO_FIELD_DEFAULT(List<CategoryNameTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("goods-manage.goods-category.field.children"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CATEGORYNAMETREEDTO_H_