#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/11/01 16:19:34

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
#ifndef _AREACONTROLLER_H_
#define _AREACONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/vo/PullListJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AreaController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AreaController)
public: // ����ӿ�
	ENDPOINT_INFO(queryArea) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("common-usage.area.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListArrayJsonVO);
		// ������Ȩ֧��
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, COMMON(/area), queryArea, API_HANDLER_AUTH_PARAME) {
		// �������ִ�к���
		API_HANDLER_RESP_VO(execQueryArea(authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	PullListArrayJsonVO::Wrapper execQueryArea(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_AREACONTROLLER_H_