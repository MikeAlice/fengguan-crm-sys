#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$

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
#ifndef _EXPORTSUPLINKMANQUERYA_H_
#define _EXPORTSUPLINKMANQUERYA_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "../../dto/ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendMessageQuery : public oatpp::DTO
{
	DTO_INIT(SendMessageQuery, DTO);
	API_DTO_FIELD_DEFAULT(oatpp::List<String>, supplier_list, ZH_WORDS_GETTER("supplier-linkman.send-message.field.supplier-list"));
	API_DTO_FIELD_DEFAULT(String, sup_message,ZH_WORDS_GETTER("supplier-linkman.send-message.field.message"));
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("supplier-linkman.send-message.field.type"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTSUPLINKMANQUERY_H_