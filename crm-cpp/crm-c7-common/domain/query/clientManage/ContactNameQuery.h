#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/07 16:57:23

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
#ifndef _CONTACTNAMEQUERY_H_
#define _CONTACTNAMEQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户联系人下拉列表Query
 * 负责人: Andrew
 */
class ContactNameQuery : public oatpp::DTO
{
	DTO_INIT(ContactNameQuery, DTO);
	API_DTO_FIELD(UInt32, customer_id, ZH_WORDS_GETTER("client-manage.contact.field.id"), true, -1);
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("client-manage.contact.field.name"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTACTNAMEQUERY_H_