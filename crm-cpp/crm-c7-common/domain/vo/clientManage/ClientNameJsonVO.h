#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/02 18:50:16

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
#ifndef _CLIENTNAMEJSONVO_H_
#define _CLIENTNAMEJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/clientManage/ClientNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取客户名称列表JsonVO
 * 负责人: Andrew
 */
class ClientNameArrayJsonVO : public JsonVO<oatpp::List<ClientNameDTO::Wrapper>>
{
	DTO_INIT(ClientNameArrayJsonVO, JsonVO<oatpp::List<ClientNameDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CLIENTNAMEJSONVO_H_