#pragma once

#ifndef _M0DIFYSCUSTOMER_DTO_
#define _M0DIFYSCUSTOMER_DTO_
#include "../../GlobalInclude.h"
#include "domain/dto/basecustomer/BaseCustomerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ����鴫�����
 */
class ModifyCustomerDTO : public BaseCustomerDTO
{
	DTO_INIT(ModifyCustomerDTO, BaseCustomerDTO);
	//�ͻ�id
	API_DTO_FIELD_DEFAULT(UInt64, customer_id, ZH_WORDS_GETTER("customer.field.customer_id"));

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	//�ͻ���Դ
	API_DTO_FIELD_DEFAULT(String, source, ZH_WORDS_GETTER("customer.field.source"));

	//�ͻ��ȼ�
	API_DTO_FIELD_DEFAULT(String, grade, ZH_WORDS_GETTER("customer.field.grade"));

	//�ͻ���ҵ
	API_DTO_FIELD_DEFAULT(String, industry, ZH_WORDS_GETTER("customer.field.industry"));

	//��ϵ�ֻ�
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("customer.field.mobile"));

	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("customer.field.tel"));

	//��ϵ��ַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("customer.field.address"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("customer.field.intro"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, needs, ZH_WORDS_GETTER("customer.field.needs"));
};

/**
 * �ͻ������ҳ�������
 */
class ModifyCustomerPageDTO : public PageDTO<ModifyCustomerDTO::Wrapper>
{
	DTO_INIT(ModifyCustomerPageDTO, PageDTO<ModifyCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DETAILSCUSTOMER_DTO_
