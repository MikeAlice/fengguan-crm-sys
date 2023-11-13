#ifndef _GETSALCONTLIST_DTO_H_
#define _GETSALCONTLIST_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取销售合同下拉列表传输对象
 */
class GetSalContDTO : public oatpp::DTO
{
	DTO_INIT(GetSalContDTO, DTO);
	// 销售合同contract_id
	API_DTO_FIELD_DEFAULT(Int32, contract_id, ZH_WORDS_GETTER("getindex.field.contract_id"));
	// 销售合同主题title
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("getindex.field.title"));
};

/*
获取销售合同下拉列表

*/
class GetSalContListDTO : public oatpp::DTO
{
	DTO_INIT(GetSalContListDTO, DTO);
	DTO_FIELD(List<GetSalContDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"当前页数据列表";
#else
		info->description = "page data list";
#endif
	}
public:
	// 添加一条数据
	void addData(GetSalContDTO::Wrapper one) {
		this->rows->push_back(one);
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _GETSALCONTLIST_DTO_H_

