#pragma once
/*
* ���ܵ���
*/
#ifndef _SERVICE_QUERY_
#define _SERVICE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * �����¼��ҳ��ѯ����
 */
class ServiceQuery : public PageQuery
{
	DTO_INIT(ServiceQuery, PageQuery);

	// �ͻ�id
	DTO_FIELD(Int32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("service.field.customer_id");
	}
	
	// �ͻ�����
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("service.field.customer_name");
	}
	//��������
	DTO_FIELD(Int32, services);
	DTO_FIELD_INFO(services) {
		info->description = ZH_WORDS_GETTER("service.field.services");
	}
	//����ʽ
	DTO_FIELD(Int32, servicesmodel);
	DTO_FIELD_INFO(servicesmodel) {
		info->description = ZH_WORDS_GETTER("service.field.servicesmodel");
	}
	//����ʱ��
	DTO_FIELD(String, service_time);
	DTO_FIELD_INFO(service_time) {
		info->description = ZH_WORDS_GETTER("service.field.service_time");
	}
	//����ʱ��
	DTO_FIELD(String, tlen);
	DTO_FIELD_INFO(tlen) {
		info->description = ZH_WORDS_GETTER("service.field.tlen");
	}
	//��������
	DTO_FIELD(String, content);
	DTO_FIELD_INFO(content) {
		info->description = ZH_WORDS_GETTER("service.field.content");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SERVICE_QUERY_
