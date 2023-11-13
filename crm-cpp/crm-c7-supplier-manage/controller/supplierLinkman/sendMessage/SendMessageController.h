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
#ifndef _SENDMESSAGE_H_
#define _SENDMESSAGE_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/supplierLinkman/SendMessageDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class SendMessageController : public oatpp::web::server::api::ApiController
{
    // 定义控制器访问入口
	API_ACCESS_DECLARE(SendMessageController);

public: // 定义接口
    //定义接口描述
    ENDPOINT_INFO(sendMessage) {
        //定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.send-message.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
		//定义返回类型
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    ENDPOINT(API_M_POST, SUP_LINKMAN(/send-message),sendMessage,BODY_DTO(SendMessageDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execSendMessage(dto, authObject->getPayload()));
    }
private: // 定义接口执行函数
    Uint64JsonVO::Wrapper execSendMessage(const SendMessageDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_$FILE_BASE_UPPER$_H_
