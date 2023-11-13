#ifndef _SELECTSALESOPPODTO_H_
#define _SELECTSALESOPPODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取销售机会名称传输对象
 */
class GetSalesOppoDTO : public oatpp::DTO
{
	DTO_INIT(GetSalesOppoDTO, DTO);
	// 销售机会chance_id
	API_DTO_FIELD_DEFAULT(Int32, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
	// 销售机会主题name
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("opportunities.field.cst_chance.name"));
};

/*
获取销售机会列表

*/
class GetSalesOppoNameDTO : public oatpp::DTO
{
	DTO_INIT(GetSalesOppoNameDTO, DTO);
	DTO_FIELD(List<GetSalesOppoDTO::Wrapper>, rows) = {};
	DTO_FIELD_INFO(rows) {
#ifndef LINUX
		info->description = u8"当前页数据列表";
#else
		info->description = "page data list";
#endif
	}
public:
	// 添加一条数据
	void addData(GetSalesOppoDTO::Wrapper one) {
		this->rows->push_back(one);
	}


};




/**
 * 联系人名称分页传输对象
 */
class GetSalesOppoPageDTO : public PageDTO<GetSalesOppoDTO::Wrapper>
{
	DTO_INIT(GetSalesOppoPageDTO, PageDTO<GetSalesOppoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _SELECTSALESOPPODTO_H_

