#pragma once

#ifndef _AC_CONTROLLER_
#define _AC_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/await/awaitpaymentsQuery.h"
#include "domain/vo/await/awaitpaymentsVO.h"

#include "domain/dto/await/awaitpayments.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 


class ACController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ACController);
	// 3 ����ӿ�
public:
	ENDPOINT_INFO(querySample) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("awaiting_.query.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(FINDAWAPAYPAGEJsonVO);
	}
	ENDPOINT(API_M_GET, "/crm-c4-sales-man/await/query", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ACQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}

	ENDPOINT_INFO(query_C)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("awaiting_.fieled.cust_name"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(FINDAWACUSTPAYPAGEJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "cust_time", 
		 ZH_WORDS_GETTER("awaiting_.field.cust_time"), "1", false);
	}
	ENDPOINT(API_M_GET, "/crm-c4-sales-man/await/queryC", query_C, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ACQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}

private:
	FINDAWAPAYJsonVO::Wrapper execQuerySample(const ACQuery::Wrapper& query, const PayloadDTO& payload);

	FINDAWAPAYJsonVO::Wrapper execQuerySample1(const ACQuery_C::Wrapper& query, const PayloadDTO& payload);
};



#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_