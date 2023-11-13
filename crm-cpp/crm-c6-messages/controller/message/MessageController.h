#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/22 19:50:14

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
#ifndef _MESSAGECONTROLLER_H_
#define _MESSAGECONTROLLER_H_

#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/message/MessageDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MessageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(MessageController);
public: // 定义接口
	ENDPOINT_INFO(mailPost)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("message.field.sendmail"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST,"/message/mail", mailPost,BODY_DTO(MailDTO::Wrapper, dto), execAddMail(dto))
	ENDPOINT_INFO(smsPost)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("message.field.sendsms"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/message/sms", smsPost, BODY_DTO(SMSDTO::Wrapper, dto), execAddSMS(dto))
	ENDPOINT_INFO(mailsPost)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("message.field.sendmails"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/message/mails", mailsPost, BODY_DTO(List<MailDTO::Wrapper>, dto), execAddMails(dto))
	ENDPOINT_INFO(smssPost)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("message.field.sendsmss"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/message/smss", smssPost, BODY_DTO(List<SMSDTO::Wrapper>, dto), execAddSMSs(dto))
private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execAddMail(const MailDTO::Wrapper& dto); 
	Uint64JsonVO::Wrapper execAddMails(const List<MailDTO::Wrapper>& dto);
	Uint64JsonVO::Wrapper execAddSMS(const SMSDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execAddSMSs(const List<SMSDTO::Wrapper>& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MESSAGECONTROLLER_H_