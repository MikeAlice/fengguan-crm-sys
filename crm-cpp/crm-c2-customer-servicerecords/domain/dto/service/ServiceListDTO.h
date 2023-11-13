#pragma once
#ifndef SERVICELISTDTO_H__
#define SERVICELISTDTO_H__
#include "../../GlobalInclude.h"
#include "../ListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

///**
// * ServiceBase�������
// */
//class ServiceBaseDTO : public oatpp::DTO
//{
//	DTO_INIT(ServiceBaseDTO, DTO);
//	// �����¼id
//	DTO_FIELD(UInt64, service_id);
//	DTO_FIELD_INFO(service_id) {
//		info->description = ZH_WORDS_GETTER("service.field.service_id");
//	}
//	// �����¼id(����)
//	DTO_FIELD(Vector<UInt64>, service_id_s);
//	DTO_FIELD_INFO(service_id_s) {
//		info->description = ZH_WORDS_GETTER("service.field.service_id_s");
//	}
//};

/*
	��ѯ�����¼�������
	�̳й�ϵ����
	�����ˣ����ܵ���
	��;����ѯ�����¼
*/
class ServiceListDTO : public oatpp::DTO
{
	DTO_INIT(ServiceListDTO, DTO);
	// �ͻ�id
	API_DTO_FIELD(Int32, customer_id, ZH_WORDS_GETTER("service.field.customer_id"), false, 1);
	// �����¼id
	API_DTO_FIELD(Int32, service_id, ZH_WORDS_GETTER("service.field.service_id"), false, 1);
	// ��������
	API_DTO_FIELD(Int32, services, ZH_WORDS_GETTER("service.field.services"), false, 1);
	// ����ʽ
	API_DTO_FIELD(Int32, servicesmodel, ZH_WORDS_GETTER("service.field.servicesmodel"), false, 1);
	// ��������
	API_DTO_FIELD(String, service_time, ZH_WORDS_GETTER("service.field.service_time"), false, "2018-10-13 14:50:11");
	// ʱ��
	API_DTO_FIELD(String, tlen, ZH_WORDS_GETTER("service.field.tlen"), false, "60");
	// ��������
	API_DTO_FIELD(String, content, ZH_WORDS_GETTER("service.field.content"), false, "fix a computer");
	// �ͻ�����
	API_DTO_FIELD(String, customer_name, ZH_WORDS_GETTER("service.field.customer_name"), false, "");



};
#include OATPP_CODEGEN_END(DTO)
#endif // SERVICELISTDTO_H__