#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 11:31:45

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
#ifndef _GETRECEIPTRECORDCONTROLLER_H_
#define _GETRECEIPTRECORDCONTROLLER_H_

#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/query-invoice-receive/FinInvoiceReceivePageJsonVO.h"
#include "domain/query/query-invoice-receive/QueryInvoiceReceiveQuery.h"
#include "service/query-invoice-rece/QueryInvoiceReceiveService.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryInvoiceReceiveController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QueryInvoiceReceiveController);
public:
	// 3 ����ӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryInvoiceReceive){
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_invoice_rece.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FinInvoiceReceivePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��Ʊ���ڡ��������ڡ���ͬ���⡢��Ӧ�����ơ����
		API_DEF_ADD_QUERY_PARAMS(String, "rece_date", ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date"), "2023-10-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("fin_invoice_rece.field.create_time"), "2023-10-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name"), u8"���һ��", false);
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name"), u8"�Ϻ��˴�", false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "money", ZH_WORDS_GETTER("fin_invoice_rece.field.money"), , false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/payment/invoice/query", queryInvoiceReceive, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(invoiceReceiveQuery, QueryInvoiceReceiveQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryInvoiceReceive(invoiceReceiveQuery, authObject->getPayload()));
	}
private:
	FinInvoiceReceivePageJsonVO::Wrapper execQueryInvoiceReceive(const QueryInvoiceReceiveQuery::Wrapper& query, const PayloadDTO& payload)
	{
		// ����һ��service
		QueryInvoiceReceiveService service;
		auto result = service.listAll(query);
		// ��Ӧ���
		auto jvo = FinInvoiceReceivePageJsonVO::createShared();
		jvo->success(result);
		return jvo;
	}
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETRECEIPTRECORDCONTROLLER_H_

