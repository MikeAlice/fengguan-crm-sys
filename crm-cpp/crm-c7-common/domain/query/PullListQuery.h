#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/31 23:11:15

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
#ifndef _PULLLISTQUERY_H_
#define _PULLLISTQUERY_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下拉列表公用Query
 * 负责人: Andrew
 */
class PullListQuery : public oatpp::DTO
{
	DTO_INIT(PullListQuery, DTO);
	API_DTO_FIELD(String, keywords, ZH_WORDS_GETTER("common-usage.field.keywords"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PULLLISTQUERY_H_