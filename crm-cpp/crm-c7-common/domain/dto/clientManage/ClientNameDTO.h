#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/02 18:43:36

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
#ifndef _CUSTOMERNAMEDTO_H_
#define _CUSTOMERNAMEDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户名称DTO
 * 负责人: Andrew
 */
class ClientNameDTO : public oatpp::DTO
{
	DTO_INIT(ClientNameDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("client-manage.my-client.field.name"));
	API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("client-manage.my-client.field.customer-id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CUSTOMERNAMEDTO_H_