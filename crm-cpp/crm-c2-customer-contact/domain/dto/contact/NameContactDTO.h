#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _NAMECONTACT_DTO_
#define _NAMECONTACT_DTO_
#include "../../GlobalInclude.h"
#include "domain/dto/contact/BaseContactDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
��ȡ��ϵ�������б�

*/
class GetContactNameDTO : public oatpp::DTO
{
	DTO_INIT(GetContactNameDTO, DTO);
	// ��ϵ������
	API_DTO_FIELD_DEFAULT(String, linkman_name, ZH_WORDS_GETTER("contact.field.name"));
	// ��ϵ��ID
	API_DTO_FIELD_DEFAULT(UInt32, linkman_id, ZH_WORDS_GETTER("contact.field.linkman_id"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_NAMECONTACT_DTO_