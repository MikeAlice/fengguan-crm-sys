//2023��10��19��
//���ߣ���Ƥ�����
//���ݣ��ͻ�������Ϣ��DTO

#pragma once
#ifndef _CUSTORMER_H_
#define _CUSTORMER_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CustormerDTO : public oatpp::DTO
{
	DTO_INIT(CustormerDTO, DTO);
	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, linkman, ZH_WORDS_GETTER("mycustormer.info.linkman"));
	// �ͻ���Դ
	API_DTO_FIELD_DEFAULT(String, source, ZH_WORDS_GETTER("mycustormer.info.source"));
	// �ͻ��ȼ�
	API_DTO_FIELD_DEFAULT(String, grade, ZH_WORDS_GETTER("mycustormer.info.grade"));
	// �ͻ���ҵ
	API_DTO_FIELD_DEFAULT(String, industry, ZH_WORDS_GETTER("mycustormer.info.indusry"));
	// ��ϵ�ֻ�
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("mycustormer.info.mobile"));
	// ��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("mycustormer.info.tel"));
	// ��ϵ��ַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("mycustormer.info.address"));
	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("mycustormer.info.intro"));
	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, needs, ZH_WORDS_GETTER("mycustormer.info.needs"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CUSTORMER_H_
