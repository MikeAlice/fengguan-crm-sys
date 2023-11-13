#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _PAYRECORDS_CONTROLLER_
#define _PAYRECORDS_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/payrecords/PayrecordsVO.h"
#include "domain/query/payrecords/PayrecordsQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PayrecordsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PayrecordsController);
public:
	ENDPOINT_INFO(queryPayrecords) {
		// ����ӿڱ���
		//info->summary = u8"��ҳ��ѯ�����¼�б�";
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payrecords.controller.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PayrecordsPageJsonVO);
		// �����ҳ��ѯ����
		API_DEF_ADD_PAGE_PARAMS();
		// ����ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "pay_date", ZH_WORDS_GETTER("pay.field.pay_date"), "2023-10-17", false);
		// ����ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("pay.field.create_time"), "2023-10-26", false);
		// �ɹ���ͬ����
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("pay.field.contract_name"), u8"���һ��", false);
		// ��Ӧ������
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("pay.field.supplier_name"), u8"�Ϻ��˴�", false);
		// ���
		API_DEF_ADD_QUERY_PARAMS(UInt64, "money", ZH_WORDS_GETTER("pay.field.money"), 123, false);
		
	}
	ENDPOINT(API_M_GET, "/payment/pay-record/page-query", queryPayrecords, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(payrecordsQuery, PayrecordsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPayrecords(payrecordsQuery, authObject->getPayload()));
	}
private:
	PayrecordsPageJsonVO::Wrapper execQueryPayrecords(const PayrecordsQuery::Wrapper& query, const PayloadDTO& payload); 
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_