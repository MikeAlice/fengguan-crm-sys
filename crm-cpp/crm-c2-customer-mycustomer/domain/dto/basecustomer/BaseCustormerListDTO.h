//��Ƥ�����
//2023��10��25��
//�ͻ�ID�����DTO
#pragma once
#ifndef _BASECUSTOMERLISTDTO_H__
#define  _BASECUSTOMERLISTDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BaseCustomerListDTO : public oatpp::DTO
{
public:
	DTO_INIT(BaseCustomerListDTO, DTO);
	//�ͻ�ID��List
	DTO_FIELD(List<UInt64>, idList);
	DTO_FIELD_INFO(idList) {
		info->description = ZH_WORDS_GETTER("mycustormer.info.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _BASECUSTOMERLISTDTO_H__
