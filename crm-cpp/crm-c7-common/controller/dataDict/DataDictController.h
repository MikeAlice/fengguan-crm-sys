#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/06 17:37:00

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
#ifndef _DATADICTCONTROLLER_H_
#define _DATADICTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/dataDict/DataDictJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �����ֵ�ģ������ʽ����Controller
 * ������: Andrew
 */
class DataDictController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DataDictController);
public: // ����ӿ�
	ENDPOINT_INFO(queryDictType) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data-dict.dict-type.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataDictArrayJsonVO);
	}
	ENDPOINT(API_M_GET, COMMON(/data-dict-name-list), queryDictType, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryDictType(authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	DataDictArrayJsonVO::Wrapper execQueryDictType(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DATADICTCONTROLLER_H_