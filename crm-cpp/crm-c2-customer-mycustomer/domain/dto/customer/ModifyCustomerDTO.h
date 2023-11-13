#pragma once

#ifndef _M0DIFYSCUSTOMER_DTO_
#define _M0DIFYSCUSTOMER_DTO_
#include "../../GlobalInclude.h"
#include "domain/dto/basecustomer/BaseCustomerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户详情传输对象
 */
class ModifyCustomerDTO : public BaseCustomerDTO
{
	DTO_INIT(ModifyCustomerDTO, BaseCustomerDTO);
	//客户id
	API_DTO_FIELD_DEFAULT(UInt64, customer_id, ZH_WORDS_GETTER("customer.field.customer_id"));

	// 客户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	//客户来源
	API_DTO_FIELD_DEFAULT(String, source, ZH_WORDS_GETTER("customer.field.source"));

	//客户等级
	API_DTO_FIELD_DEFAULT(String, grade, ZH_WORDS_GETTER("customer.field.grade"));

	//客户行业
	API_DTO_FIELD_DEFAULT(String, industry, ZH_WORDS_GETTER("customer.field.industry"));

	//联系手机
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("customer.field.mobile"));

	//联系电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("customer.field.tel"));

	//联系地址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("customer.field.address"));

	//客户介绍
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("customer.field.intro"));

	//客户需求
	API_DTO_FIELD_DEFAULT(String, needs, ZH_WORDS_GETTER("customer.field.needs"));
};

/**
 * 客户详情分页传输对象
 */
class ModifyCustomerPageDTO : public PageDTO<ModifyCustomerDTO::Wrapper>
{
	DTO_INIT(ModifyCustomerPageDTO, PageDTO<ModifyCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DETAILSCUSTOMER_DTO_
