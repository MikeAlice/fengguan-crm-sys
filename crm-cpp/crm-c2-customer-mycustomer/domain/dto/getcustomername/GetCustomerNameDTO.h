#ifndef GETCUSTOMERNAMEDTO_H__
#define GETCUSTOMERNAMEDTO_H__
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取客户名称列表传输对象
 */
class GetCustomerNameDTO : public oatpp::DTO
{
	DTO_INIT(GetCustomerNameDTO, DTO);
	// 客户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("getcustomername.field.name"));
	// 客户ID
	API_DTO_FIELD_DEFAULT(UInt32, customer_id, ZH_WORDS_GETTER("getcustomername.field.customer_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // GETCUSTOMERNAMEDTO_H__
