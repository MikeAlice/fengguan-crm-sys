#pragma once
#ifndef _GETCUSTOMERDETAILS_CONTROLLER_
#define _GETCUSTOMERDETAILS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/getcutomerdetails/GetCustomerDetailsQuery.h"
#include "domain/vo/getcustomerdetails/GetCustomerDetailsVO.h"
#include "service/getcutomerdetails/GetCustomerDetailsService.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ��ȡ�ͻ���ϸ��Ϣ
 */
class GetCustomerDetailsController : public oatpp::web::server::api::ApiController //�̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(GetCustomerDetailsController);

public: 
	//����ӿ�
	// �����ȡ��ϵ���б�ӿ�	�����ˣ��Ͼ�
	ENDPOINT(API_M_GET, "/customer-mycustomer/query-customer-details", queryCustomerDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(customerQuery, GetCustomerDetailsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCustomerDetails(customerQuery, authObject->getPayload()));
	}
	// �����ȡ��ϵ���б�ӿ�����
	ENDPOINT_INFO(queryCustomerDetails) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.query-contact-details"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetCustomerDetailsJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("customer.field.id"), 1, true);
	}
private:
	// ��ȡ�ͻ������б�
	GetCustomerDetailsJsonVO::Wrapper execQueryCustomerDetails(GetCustomerDetailsQuery::Wrapper query, const PayloadDTO& playload);
};

//ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) 
#endif // _GETCUSTOMERDETAILS_CONTROLLER_