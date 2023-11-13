#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/24
 @FileName: RemoveCapitalRecordController
 @version: 1.0

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
#ifndef _REMOVE_CAPITAL_RECORD_CONTROLLER_H_
#define _REMOVE_CAPITAL_RECORD_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/fincapitalrecord/RemoveCapitalRecoedDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RemoveCapitalRecordController : public oatpp::web::server::api::ApiController //  �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(RemoveCapitalRecordController);
public:// ����ӿ�
	// ����ɾ���ӿ����� �����ˣ�����
	ENDPOINT_INFO(removeCapitalRecords)
	{
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("fin_capital_record.controller.remove.summary"), Uint64JsonVO::Wrapper);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/fin-capital-record/remove-data", removeCapitalRecords, BODY_DTO(List<RemoveCapitalRecordDTO::Wrapper>, dto), execRemoveCapitalRecords(dto, authObject->getPayload()));

private:
	// ɾ�����ݣ�֧������ɾ���� �����ˣ�����
	Uint64JsonVO::Wrapper execRemoveCapitalRecords(const List<RemoveCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif
