#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/06 17:47:16

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
#ifndef _DATADICTJSONVO_H_
#define _DATADICTJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/dataDict/DataDictDTO.h"
#include "domain/vo/JsonVO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取指定字典分类对应字典列表JsonVO
 * 负责人: Andrew
 */
class DataDictArrayJsonVO : public JsonVO<oatpp::List<DataDictDTO::Wrapper>>
{
	DTO_INIT(DataDictArrayJsonVO, JsonVO<oatpp::List<DataDictDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DATADICTJSONVO_H_