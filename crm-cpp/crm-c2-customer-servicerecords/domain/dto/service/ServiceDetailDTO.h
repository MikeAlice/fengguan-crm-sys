#pragma once
#ifndef _SERBICEDETAILDTO_H_
#define _SERBICEDETAILDTO_H_
#include "../../GlobalInclude.h"
#include "../ListDTO.h"
#include"ServiceBaseDTO.h"
#include"ServiceListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

///*
// * ServiceDetail�������
// */
//class ServiceDetailDTO : public oatpp::DTO
//{
//	DTO_INIT(ServiceDetailDTO, ServiceBaseDTO);
//	
//	// �ͻ�id
//	DTO_FIELD(Int32, customer_id);
//	DTO_FIELD_INFO(customer_id) {
//		info->description = ZH_WORDS_GETTER("service.field.customer_id");
//	}
//	// �ͻ�����
//	DTO_FIELD(String, customer_name);
//	DTO_FIELD_INFO(customer_name) {
//		info->description = ZH_WORDS_GETTER("service.field.customer_name");
//	}
//
//	// ��ϵ��id
//	DTO_FIELD(Int32, linkman_id);
//	DTO_FIELD_INFO(linkman_id) {
//		info->description = ZH_WORDS_GETTER("service.field.linkman_id");
//	}
//	// ��ϵ������
//	DTO_FIELD(String, linkmain_name);
//	DTO_FIELD_INFO(linkmain_name) {
//		info->description = ZH_WORDS_GETTER("service.field.linkmain_name");
//	}
//	// ��������
//	DTO_FIELD(Int32, service_type);
//	DTO_FIELD_INFO(service_type) {
//		info->description = ZH_WORDS_GETTER("service.field.service_type");
//	}
//	// ����ʽ
//	DTO_FIELD(Int32, service_model);
//	DTO_FIELD_INFO(service_model) {
//		info->description = ZH_WORDS_GETTER("service.field.service_model");
//	}
//	// �۸�
//	DTO_FIELD(Int32, price);
//	DTO_FIELD_INFO(price) {
//		info->description = ZH_WORDS_GETTER("service.field.price");
//	}
//	// ״̬ 1=���账��2δ����3=�����У�4�������
//	DTO_FIELD(Int32, status);
//	DTO_FIELD_INFO(status) {
//		info->description = ZH_WORDS_GETTER("service.field.service_status");
//	}
//	// ��������
//	DTO_FIELD(String, service_time);
//	DTO_FIELD_INFO(service_time) {
//		info->description = ZH_WORDS_GETTER("service.field.service_datetime");
//	}
//	// ʱ��
//	DTO_FIELD(String, tlen);
//	DTO_FIELD_INFO(tlen) {
//		info->description = ZH_WORDS_GETTER("service.field.tlen");
//	}
//	// ��������
//	DTO_FIELD(String, content);
//	DTO_FIELD_INFO(content) {
//		info->description = ZH_WORDS_GETTER("service.field.service_content");
//	}
//	//// ��������
//	//DTO_FIELD(String, service_content);
//	//DTO_FIELD_INFO(service_content) {
//	//	info->description = ZH_WORDS_GETTER("service.field.service_content");
//	//}
//	// ��ע
//	DTO_FIELD(String, intro);
//	DTO_FIELD_INFO(intro) {
//		info->description = ZH_WORDS_GETTER("service.field.intro");
//	}
//	// ������id
//	DTO_FIELD(Int32, create_user_id);
//	DTO_FIELD_INFO(create_user_id) {
//		info->description = ZH_WORDS_GETTER("service.field.create_user_id");
//	}
//	// ����ʱ��
//	DTO_FIELD(String, service_create_time);
//	DTO_FIELD_INFO(service_create_time) {
//		info->description = ZH_WORDS_GETTER("service.field.service_create_time");
//	}
//};
///*
// * �����¼��ҳ�������
// * ������: ���ܵ���
// */
//class ServiceNotePageDTO : public PageDTO<ServiceDetailDTO::Wrapper>
//{
//	DTO_INIT(ServiceNotePageDTO, PageDTO<ServiceDetailDTO::Wrapper>);
//	//�����¼��ҳ
//	DTO_FIELD(String, service_note_page);
//	DTO_FIELD_INFO(service_note_page) {
//		info->description = ZH_WORDS_GETTER("service.field.service_note_page");
//	}
//};
///**
// * �����¼���������б�DTO������������
// * ������: ���ܵ���
// */
//class ServiceNoteListDTO : public ListDTO<ServiceDetailDTO::Wrapper>
//{
//	DTO_INIT(ServiceNoteListDTO, ListDTO<ServiceDetailDTO::Wrapper>);
//	//�����¼����
//	DTO_FIELD(String, export_service_note);
//	DTO_FIELD_INFO(export_service_note) {
//		info->description = ZH_WORDS_GETTER("service.field.export_service_note");
//	}
//};


/*
	��������¼�������
	�̳й�ϵ��base->detail
	�����ˣ���ˮ��
	��;����ѯ�����¼
*/
class ServiceDetailDTO : public ServiceBaseDTO
{
	DTO_INIT(ServiceDetailDTO, ServiceBaseDTO);
	// �ͻ�����
	API_DTO_FIELD(String, customer_name, ZH_WORDS_GETTER("service.field.customer_name"), false, "");
	// ��ϵ������
	API_DTO_FIELD(String, linkman_id, ZH_WORDS_GETTER("service.field.linkman_id"), false, "dong dong");

};
/*
	�޸ķ����¼�������
	�̳й�ϵ��base->modify
	�����ˣ���ˮ��
	��;���޸ķ����¼
*/
class ServiceModifyDTO : public ServiceBaseDTO
{
	DTO_INIT(ServiceModifyDTO, ServiceBaseDTO);
	// �����¼id
	API_DTO_FIELD(UInt64, service_id, ZH_WORDS_GETTER("service.field.service_id"), true, 1)
};

/*
 * �����¼��ҳ�������
 * ������: ���ܵ���
 */
class ServiceNotePageDTO : public PageDTO<ServiceListDTO::Wrapper>
{
	DTO_INIT(ServiceNotePageDTO, PageDTO<ServiceListDTO::Wrapper>);
	//�����¼��ҳ
	DTO_FIELD(String, service_note_page);
	DTO_FIELD_INFO(service_note_page) {
		info->description = ZH_WORDS_GETTER("service.field.service_note_page");
	}
};
/**
 * �����¼���������б�DTO������������
 * ������: ���ܵ���
 */
class ServiceNoteListDTO : public ListDTO<ServiceDetailDTO::Wrapper>
{
	DTO_INIT(ServiceNoteListDTO, ListDTO<ServiceDetailDTO::Wrapper>);
	//�����¼����
	DTO_FIELD(String, export_service_note);
	DTO_FIELD_INFO(export_service_note) {
		info->description = ZH_WORDS_GETTER("service.field.export_service_note");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SERBICEDTO_H_
