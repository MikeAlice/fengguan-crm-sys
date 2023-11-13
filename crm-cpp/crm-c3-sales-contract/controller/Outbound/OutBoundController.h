#pragma once
#ifndef GETCUSTOMERCONTROLLER_H__
#define GETCUSTOMERCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/outboundindex/OutBoundDTO.h"
#include "domain/vo/OutBoundVO.h"
#include "domain/query/OutBoundQuery.h"

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

class OutBoundController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(OutBoundController);

public: //����ӿ�
	//���ɳ��ⵥ
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, OTC_PRFIX("/get-customer"), getCustomer, BODY_DTO(GetCustomerDTO::Wrapper, dto), execGetCustomer(dto, authObject->getPayload()));
	ENDPOINT_INFO(queryOutBound) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("OutBound.controller.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(OutBoundJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "OutBoundId", ZH_WORDS_GETTER("OutBound.field.owner_user_id"), "a", false);
	}
	ENDPOINT(API_M_GET, "/sales-contract/OutBound", queryOutBound, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, OutBoundQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOutBound(userQuery, authObject->getPayload()));
	}
private:
	// �ڴ���Ӷ���
	OutBoundJsonVO::Wrapper execQueryOutBound(const OutBoundQuery::Wrapper& query, const PayloadDTO& payload);
};

//ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) 
#endif // GETCUSTOMERCONTROLLER_H__