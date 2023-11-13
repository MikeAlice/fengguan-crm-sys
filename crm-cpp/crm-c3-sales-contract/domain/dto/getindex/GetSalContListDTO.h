#ifndef _GETSALCONTLIST_DTO_H_
#define _GETSALCONTLIST_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���ۺ�ͬ�����б������
 */
class GetSalContDTO : public oatpp::DTO
{
	DTO_INIT(GetSalContDTO, DTO);
	// ���ۺ�ͬcontract_id
	API_DTO_FIELD_DEFAULT(Int32, contract_id, ZH_WORDS_GETTER("getindex.field.contract_id"));
	// ���ۺ�ͬ����title
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("getindex.field.title"));
};

/*
��ȡ���ۺ�ͬ�����б�

*/
class GetSalContListDTO : public oatpp::DTO
{
	DTO_INIT(GetSalContListDTO, DTO);
	DTO_FIELD(List<GetSalContDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"��ǰҳ�����б�";
#else
		info->description = "page data list";
#endif
	}
public:
	// ���һ������
	void addData(GetSalContDTO::Wrapper one) {
		this->rows->push_back(one);
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _GETSALCONTLIST_DTO_H_

