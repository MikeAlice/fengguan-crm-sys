#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _EXPORT_CONTROLLER_
#define _EXPORT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/customer/DetailsCustomerDTO.h"
#include "domain/query/customerfile/ExportCustomerQuery.h"
#include "service/customerfile/ExportCustomerService.h"
#include "ApiHelper.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �����ͻ�������
 */
class ExportController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExportController);
	// 3 ����ӿ�
public:
	// ���嵼���ͻ��ӿ�	�����ˣ��Ͼ�
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/customer-mycustomer/export-customer", queryCustomerFile, BODY_DTO(ExportCustomerDTO::Wrapper, dto), execExportCustomer(dto, authObject->getPayload()));
	// ����ɾ���ͻ��ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/export-customer", queryCustomerFile, BODY_DTO(ExportCustomerQuery::Wrapper, query), execExportCustomer(query, authObject->getPayload()));
	/*ENDPOINT(API_M_GET, "/customer-mycustomer/export-customer", queryCustomerFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(customerQuery, ExportCustomerQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execExportCustomer(customerQuery, authObject->getPayload()));
	}*/
	// ���嵼���ͻ��ӿ�����
	ENDPOINT_INFO(queryCustomerFile) {
		// ����ɾ���ͻ�����ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("customer.controller.export"), StringJsonVO::Wrapper);
	}
	/*ENDPOINT_INFO(queryCustomerFile) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.export"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(List<Int32>, "customer_id_list", ZH_WORDS_GETTER("customer.field.customer_id_list"),{1}, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_user_id", ZH_WORDS_GETTER("customer.field.create_user_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "owner_user_id", ZH_WORDS_GETTER("customer.field.owner_user_id"), 1, false);
	}*/



private:
	/*
	* �����ˣ� �Ͼ�
	* ���������������������Ŀͻ����ݱ���ΪExcel�ļ����ϴ����ļ�������������·�����͵�ǰ��
	* @param�� ExportCustomerDTO   ɸѡ����
	*			PayloadDTO&   
	* @return�� StringJsonVO  �����ļ�·��
	*/
	StringJsonVO::Wrapper execExportCustomer(ExportCustomerQuery::Wrapper query, const PayloadDTO& playload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORT_CONTROLLER