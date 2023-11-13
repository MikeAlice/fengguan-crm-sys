#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/28 17:58:40

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
#ifndef _SENDEMAILAPICLIENT_H_
#define _SENDEMAILAPICLIENT_H_

#include "domain/dto/supplierLinkman/SendEmailDTO.h"
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"
#include "Macros.h"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class SendEmailApiClient : public oatpp::web::client::ApiClient
{
	// 初始化ApiClient
	API_CLIENT_INIT(SendEmailApiClient)
	// 
	API_CALL(API_M_POST, "message/mails", sendEmail, API_HANDLER_AUTN_HEADER, BODY_DTO(List<SendEmailSendDTO::Wrapper>, listSendDTO));
};

// 定义ApiClient控制器使用结束宏
#include OATPP_CODEGEN_END(ApiClient)

#endif // !_SENDEMAILAPICLIENT_H_