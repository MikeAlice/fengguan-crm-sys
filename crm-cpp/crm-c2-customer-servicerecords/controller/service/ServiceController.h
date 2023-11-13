#pragma once
#ifndef SERVICECONTROLLER_H__
#define SERVICECONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/service/ServiceBaseDTO.h"
#include "domain/dto/service/ServiceDetailDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Code gen

/**
 * Service�����������������¼
 */
class ServiceAddRemoveModifyController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ServiceAddRemoveModifyController);
	// 3 ����ӿ�
public:
	//��ӷ����¼
	ENDPOINT_INFO(addServices) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("service.controller.add.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
		// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(Int32, "customer_id", ZH_WORDS_GETTER("service.field.customer_id"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "linkman_id", ZH_WORDS_GETTER("service.field.linkman_id"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "services", ZH_WORDS_GETTER("service.field.services"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "servicesmodel", ZH_WORDS_GETTER("service.field.servicesmodel"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "price", ZH_WORDS_GETTER("service.field.price"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("service.field.status"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "service_time", ZH_WORDS_GETTER("service.field.service_time"), "2018-10-13 14:50:11", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "tlen", ZH_WORDS_GETTER("service.field.tlen"), "0" , true);
		//API_DEF_ADD_QUERY_PARAMS(String, "content", ZH_WORDS_GETTER("service.field.content"), "fix", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("service.field.intro"), "fix", false);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "create_user_id", ZH_WORDS_GETTER("service.field.create_user_id"), 0, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "service_create_time", ZH_WORDS_GETTER("service.field.service_create_time"), "2018-10-13 14:50:11", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-servicerecords/add-service", addServices, BODY_DTO(ServiceBaseDTO::Wrapper, dto), execAddServices(dto, authObject->getPayload()));


	//�޸ķ����¼
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/customer-servicerecords/modify-service", modifyServices, BODY_DTO(ServiceModifyDTO::Wrapper, dto), execModifyServices(dto, authObject->getPayload()));
	ENDPOINT_INFO(modifyServices) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("service.controller.modify.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ����������ѯ��������
		/*API_DEF_ADD_QUERY_PARAMS(Int32, "customer_id", ZH_WORDS_GETTER("service.field.customer_id"), , false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "linkman_id", ZH_WORDS_GETTER("service.field.linkman_id"), , false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "services", ZH_WORDS_GETTER("service.field.services"), , false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "servicesmodel", ZH_WORDS_GETTER("service.field.servicesmodel"), , false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "price", ZH_WORDS_GETTER("service.field.price"), , false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("service.field.status"), , false);
		API_DEF_ADD_QUERY_PARAMS(String, "service_time", ZH_WORDS_GETTER("service.field.service_time"), , false);
		API_DEF_ADD_QUERY_PARAMS(String, "tlen", ZH_WORDS_GETTER("service.field.tlen"), , false);
		API_DEF_ADD_QUERY_PARAMS(String, "content", ZH_WORDS_GETTER("service.field.content"), , false);
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("service.field.intro"), , false);*/
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeServices) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("service.controller.remove.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(Vector<UInt64>, "service_id_s", ZH_WORDS_GETTER("service.field.service_id_s"), , true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/customer-servicerecords/{service_id_s}", removeServices, BODY_DTO(ServiceIdListDTO::Wrapper, dto), execRemoveServices(dto, authObject->getPayload()));

private:
	// �ڴ���Ӷ���

	//��ӷ����¼
	Uint64JsonVO::Wrapper execAddServices(const ServiceBaseDTO::Wrapper& dto, const PayloadDTO& payload);
	//����ɾ�������¼
	Uint64JsonVO::Wrapper execRemoveServices(const ServiceIdListDTO::Wrapper& dto, const PayloadDTO& payload);
	//�޸ķ����¼
	Uint64JsonVO::Wrapper execModifyServices(const ServiceModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Code gen
#endif // SERVICECONTROLLER_H__