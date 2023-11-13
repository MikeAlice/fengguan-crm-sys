#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 柏下微雨
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
#ifndef _SENDMESSAGE_DTO_
#define _SENDMESSAGE_DTO_
#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 发送邮件的DTO
 */
class SendMessageDTO : public oatpp::DTO {
	DTO_INIT(SendMessageDTO, DTO);
	// 供应商联系人ID列表
	API_DTO_FIELD_DEFAULT(oatpp::List<UInt64>, supplier_list, ZH_WORDS_GETTER("supplier-linkman.send-message.field.supplier-list"));
	// 短信类型
	API_DTO_FIELD_DEFAULT(UInt64, type, ZH_WORDS_GETTER("supplier-linkman.send-message.field.type"));
	// 短信扩展内容
	API_DTO_FIELD_DEFAULT(String, message, ZH_WORDS_GETTER("supplier-linkman.send-message.field.message"));

};
#include OATPP_CODEGEN_END(DTO)

#endif