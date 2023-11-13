#pragma once
/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/21 21:36:25

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
#ifndef _INCOMEPAGEJSON_VO_
#define _INCOMEPAGEJSON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/other_income_statement/IncomeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class IncomePageJsonVO : public JsonVO<IncomePageDTO::Wrapper> {
	DTO_INIT(IncomePageJsonVO, JsonVO<IncomePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
