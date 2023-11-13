#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/10/23 17:09:37

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
#ifndef _BASICDATACONTROLLER_H_
#define _BASICDATACONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "ApiHelper.h"
#include "domain/vo/supplierLinkman/BasicDataVO.h"
#include "domain/dto/supplierLinkman/BasicDataDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ȡ��Ӧ����ϵ�˻�����Ϣ��������Controller
 * ������: ����
 */
class BasicDataController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(BasicDataController);
public: // ����ӿ�
	ENDPOINT_INFO(queryBasicData) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.basic-data.summary"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BasicDataJsonVO);
		// ������Ȩ֧��
		API_DEF_ADD_AUTH();
	}

	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, SUP_LINKMAN(/basic-data), queryBasicData, API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBasicData(authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	BasicDataJsonVO::Wrapper execQueryBasicData(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_BASICDATACONTROLLER_H_