#pragma once
#ifndef _EXPORTSERVICENOTE_H_
#define _EXPORTSERVICENOTE_H_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "../../dto/ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���������¼Query
 * ������: ���ܵ���
 */
class ExportServiceNoteQuery :public oatpp::DTO
{
	DTO_INIT(ExportServiceNoteQuery, DTO);

	////�����¼id
	//API_DTO_FIELD_DEFAULT(Int32, service_id, ZH_WORDS_GETTER("service.field.service_id"));
	//�ͻ�id
	API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("service.field.customer_id"));
	// �ͻ�ID�б�
	API_DTO_FIELD_DEFAULT(List<Int32>, service_id_list, ZH_WORDS_GETTER("service.field.service_id_list"));
	////�ͻ�����
	////API_DTO_FIELD_DEFAULT(String, customer_name, ZH_WORDS_GETTER("service.field.customer_name"));
	////��������
	//API_DTO_FIELD_DEFAULT(Int32, services, ZH_WORDS_GETTER("service.field.services"));
	//
	////����ʽ
	//API_DTO_FIELD_DEFAULT(Int32, servicesmodel, ZH_WORDS_GETTER("service.field.servicesmodel"));
	//
	////����ʱ��
	//API_DTO_FIELD_DEFAULT(String, service_time, ZH_WORDS_GETTER("service.field.service_time"));
	//
	////����ʱ��
	//API_DTO_FIELD_DEFAULT(String, tlen, ZH_WORDS_GETTER("service.field.tlen"));
	//
	////��������
	//API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("service.field.content"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTSERVICENOTE_H_
