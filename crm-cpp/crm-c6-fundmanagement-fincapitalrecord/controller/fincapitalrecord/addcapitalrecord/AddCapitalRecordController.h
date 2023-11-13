#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/24
 @FileName: AddCapitalRecordController
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
#ifndef _ADD_CAPITAL_RECORD_CONTROLLER_H_
#define _ADD_CAPITAL_RECORD_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/fincapitalrecord/AddCapitalRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AddCapitalRecordController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AddCapitalRecordController);
public:// ����ӿ�
	// ������� �����ˣ�����
	ENDPOINT_INFO(addCapitalRecord)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("fin_capital_record.controller.add.summary");
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/fin-capital-record/add-data",
		addCapitalRecord, BODY_DTO(AddCapitalRecordDTO::Wrapper, dto), execAddCapitalRecord(dto, authObject->getPayload()));
private:
	// ������� �����ˣ�����
	StringJsonVO::Wrapper execAddCapitalRecord(const AddCapitalRecordDTO::Wrapper & dto, const PayloadDTO & payload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif
