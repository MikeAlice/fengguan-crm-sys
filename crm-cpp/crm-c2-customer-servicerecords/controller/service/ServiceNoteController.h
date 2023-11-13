#pragma once
#ifndef _SERVICENOTE_CONTROLLER_H_
#define _SERVICENOTE_CONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/service/ServiceQuery.h"
#include "domain/dto/service/ServiceBaseDTO.h"
#include "domain/dto/service/ServiceListDTO.h"
#include "domain/dto/service/ServiceDetailDTO.h"
#include "domain/vo/service/ServiceVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Code gen

/**
 * Service�����������������¼
 * �����ˣ����ܵ���
 */
class ServiceNoteController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ServiceNoteController);
	// 3 ����ӿ�
public:

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryServiceNote) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("service.controller.getList.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ServiceNotePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "customer_name", ZH_WORDS_GETTER("service.field.customer_name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "services", ZH_WORDS_GETTER("service.field.services"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "servicesmodel", ZH_WORDS_GETTER("service.field.servicesmodel"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "service_time", ZH_WORDS_GETTER("service.field.service_time"), "xxxx-xx-xx", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "tlen", ZH_WORDS_GETTER("service.field.tlen"), "0", true);
		API_DEF_ADD_QUERY_PARAMS(String, "content", ZH_WORDS_GETTER("service.field.content"), "fix", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET,"/customer-servicerecords/service-note", queryServiceNote, BODY_DTO(ServiceDetailDTO::Wrapper, dto), execQueryServiceNote(dto, authObject->getPayload()));
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/customer-servicerecords/service-note", queryServiceNote, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ServiceQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryServiceNote(userQuery, authObject->getPayload()));
	}
private:
	ServiceNotePageJsonVO::Wrapper execQueryServiceNote(const ServiceQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 �����¼��ҳ��ѯ����
	//ServiceNotePageJsonVO::Wrapper execQueryServiceNote(const ServiceDetailDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Code gen
#endif // SERVICENOTECONTROLLER_H__
