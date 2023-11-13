#ifndef GETCUSTOMERCONTROLLER_H__
#define GETCUSTOMERCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include"domain/dto/getcustomer/GetCustomerDTO.h"
#include "domain/query/getcustomer/GetCustomerQuery.h"
#include "domain/vo/getcustomer/GetCustomerVO.h"
#include "service/getcustomer/GetCustomerService.h"

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ��ȡ�ͻ��б�����ӿ�ʵ��
 */
class GetCustomerController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(GetCustomerController);
	
public: //����ӿ�
	//��ȡ�ͻ��б�
	ENDPOINT_INFO(getCustomer) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getcustomer.controller.get.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetCustomerPageJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "conn_time", ZH_WORDS_GETTER("getcustomer.field.conn_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "next_time", ZH_WORDS_GETTER("getcustomer.field.next_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("getcustomer.field.name"), u8"", false);
		API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("getcustomer.field.mobile"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("getcustomer.field.tel"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("getcustomer.field.address"), u8"", false);
	}
	ENDPOINT(API_M_GET, "/customer-mycustomer/get-customer" , getCustomer, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetCustomerQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetCustomer(userQuery, authObject->getPayload()));
	}
private:
	// �ڻ�ȡ�ͻ��б�
	GetCustomerPageJsonVO::Wrapper execGetCustomer(const GetCustomerQuery::Wrapper& query, const PayloadDTO& payload);
};

//ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) 
#endif // GETCUSTOMERCONTROLLER_H__