#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _DICTCLASSIFYDTO_VO_
#define _DICTCLASSIFYDTO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/dictclassify/DictClassifyDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictClassifyPageJsonVO : public JsonVO<DictClassifyPageDTO::Wrapper> {
	DTO_INIT(DictClassifyPageJsonVO, JsonVO<DictClassifyPageDTO::Wrapper>);
};
class DictClassifyListJsonVO : public JsonVO<oatpp::List<DictClassifyListDTO::Wrapper>> {
	DTO_INIT(DictClassifyListJsonVO, JsonVO<oatpp::List<DictClassifyListDTO::Wrapper>>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DICTCLASSIFYDTO_VO_