#ifndef _SELECTSALESOPPODTO_H_
#define _SELECTSALESOPPODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���ۻ������ƴ������
 */
class GetSalesOppoDTO : public oatpp::DTO
{
	DTO_INIT(GetSalesOppoDTO, DTO);
	// ���ۻ���chance_id
	API_DTO_FIELD_DEFAULT(Int32, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
	// ���ۻ�������name
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("opportunities.field.cst_chance.name"));
};

/*
��ȡ���ۻ����б�

*/
class GetSalesOppoNameDTO : public oatpp::DTO
{
	DTO_INIT(GetSalesOppoNameDTO, DTO);
	DTO_FIELD(List<GetSalesOppoDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"��ǰҳ�����б�";
#else
		info->description = "page data list";
#endif
	}
public:
	// ���һ������
	void addData(GetSalesOppoDTO::Wrapper one) {
		this->rows->push_back(one);
	}


};




/**
 * ��ϵ�����Ʒ�ҳ�������
 */
class GetSalesOppoPageDTO : public PageDTO<GetSalesOppoDTO::Wrapper>
{
	DTO_INIT(GetSalesOppoPageDTO, PageDTO<GetSalesOppoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _SELECTSALESOPPODTO_H_

