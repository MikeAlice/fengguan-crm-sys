#pragma once
/*
* ������: �Ͼ�
*/
#include "stdafx.h"
#ifndef _GETCUSTOMERDETAILS_DTO_
#define _GETCUSTOMERDETAILS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ����鴫�����
 */
class GetCustomerDetailsDTO : public oatpp::DTO
{
	DTO_INIT(GetCustomerDetailsDTO, DTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, linkman, ZH_WORDS_GETTER("customer.field.linkman"));

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

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMERDETAILS_DTO_