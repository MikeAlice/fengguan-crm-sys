#pragma once
#ifndef SERVICEBASEDTO_H__
#define SERVICEBASEDTO_H__
#include "../../GlobalInclude.h"

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
	���������¼�������
	�̳й�ϵ����
	�����ˣ���ˮ��
	��;����ӷ����¼
*/
class ServiceBaseDTO : public oatpp::DTO
{
	DTO_INIT(ServiceBaseDTO, DTO);
	// �ͻ�id
	API_DTO_FIELD(Int32, customer_id, ZH_WORDS_GETTER("service.field.customer_id"), false, 1);
	// ��ϵ��idlinkman_id linkman_name
	API_DTO_FIELD(Int32, linkman_id, ZH_WORDS_GETTER("service.field.linkman_id"), false, 1);
	// ��������service_type 
	API_DTO_FIELD(Int32, services, ZH_WORDS_GETTER("service.field.services"), false, 1);
	// ����ʽservicesmodel
	API_DTO_FIELD(Int32, servicesmodel, ZH_WORDS_GETTER("service.field.servicesmodel"), false, 1);
	// �۸�
	API_DTO_FIELD(Int32, price, ZH_WORDS_GETTER("service.field.price"), false, 1);
	// ״̬ 1=���账��2δ����3=�����У�4�������
	API_DTO_FIELD(Int32, status, ZH_WORDS_GETTER("service.field.status"), false, 1);
	// ��������
	API_DTO_FIELD(String, service_time, ZH_WORDS_GETTER("service.field.service_time"), false, "2018-10-13 14:50:11");
	// ʱ��
	API_DTO_FIELD(String, tlen, ZH_WORDS_GETTER("service.field.tlen"), false, "60");
	// ��������
	API_DTO_FIELD(String, content, ZH_WORDS_GETTER("service.field.content"), false, "fix a computer");
	// ��ע
	API_DTO_FIELD(String, intro, ZH_WORDS_GETTER("service.field.intro"), false, "phone call");
	// ������id
	//API_DTO_FIELD(Int32, create_user_id, ZH_WORDS_GETTER("service.field.create_user_id"), false, 1);
	// ����ʱ��
	//API_DTO_FIELD(String, service_create_time, ZH_WORDS_GETTER("service.field.service_create_time"), false, "2018-10-13 14:50:11");

};
/*
	ID�б�����¼�������
	�̳й�ϵ����
	�����ˣ���ˮ��
	��;��ɾ�������¼��������
*/
class ServiceIdListDTO : public oatpp::DTO
{
	DTO_INIT(ServiceIdListDTO, DTO);

	// �����¼id(����)
	API_DTO_FIELD(Vector<UInt64>, service_id_s, ZH_WORDS_GETTER("service.field.service_id_s"), true, { 1 })


};
#include OATPP_CODEGEN_END(DTO)
#endif // SERVICEBASEDTO_H__