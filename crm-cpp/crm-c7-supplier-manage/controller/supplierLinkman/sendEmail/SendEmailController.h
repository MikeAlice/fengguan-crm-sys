#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/23 20:09:25

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
#ifndef _SENDEMAILCONTROLLER_H_
#define _SENDEMAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "ApiHelper.h"
#include "domain/dto/supplierLinkman/SendEmailDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 发邮件Controller
 * 负责人: 。好
 */
class SendEmailController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SendEmailController)
public: // 定义接口
	ENDPOINT_INFO(sendEmail) {
		// 定义标题接口
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.send-email.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);;
		// 定义授权支持
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_POST, SUP_LINKMAN(/send-email), sendEmail, BODY_DTO(SendEmailRecvDTO::Wrapper, recvDTO), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execSendEmailById(recvDTO, authObject->getPayload()));
	}
private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execSendEmailById(const SendEmailRecvDTO::Wrapper& recvDTO, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_SENDEMAILCONTROLLER_H_