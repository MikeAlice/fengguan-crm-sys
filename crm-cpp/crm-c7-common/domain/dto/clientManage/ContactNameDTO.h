#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/07 17:14:36

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
#ifndef _CONTACTNAMEDTO_H_
#define _CONTACTNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ���ϵ�������б�DTO
 * ������: Andrew
 */
class ContactNameDTO : public oatpp::DTO
{
	DTO_INIT(ContactNameDTO, DTO);
	API_DTO_FIELD_DEFAULT(UInt32, linkman_id, ZH_WORDS_GETTER("client-manage.contact.field.linkman_id"));
	API_DTO_FIELD_DEFAULT(String, linkman_name, ZH_WORDS_GETTER("client-manage.contact.field.name"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTACTNAMEDTO_H_