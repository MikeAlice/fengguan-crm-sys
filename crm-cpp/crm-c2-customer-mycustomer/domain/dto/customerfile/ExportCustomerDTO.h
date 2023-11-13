#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _EXPORTCUSTOMER_DTO_
#define _EXPORTCUSTOMER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ͻ��������
 */
class ExportCustomerDTO : public oatpp::DTO
{
	DTO_INIT(ExportCustomerDTO, DTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, create_user_id, ZH_WORDS_GETTER("customer.field.create_user_id"));

	// ������Ա����
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("customer.field.create_user_name"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("customer.field.owner_user_id"));

	// ������Ա����
	API_DTO_FIELD_DEFAULT(String, owner_user_name, ZH_WORDS_GETTER("customer.field.owner_user_name"));

	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("customer.field.create_time"));

	//�´ι�ͨʱ��
	API_DTO_FIELD_DEFAULT(String, next_time, ZH_WORDS_GETTER("customer.field.next_time"));

	//�����ϵʱ��
	API_DTO_FIELD_DEFAULT(String, conn_time, ZH_WORDS_GETTER("customer.field.conn_time"));

	//�����ͨ����
	API_DTO_FIELD_DEFAULT(String, conn_body, ZH_WORDS_GETTER("customer.field.conn_body"));

};

/**
 * �����ͻ���ҳ�������
 */
class ExportCustomerPageDTO : public PageDTO<ExportCustomerDTO::Wrapper>
{
	DTO_INIT(ExportCustomerPageDTO, PageDTO<ExportCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTCUSTOMER_DTO_