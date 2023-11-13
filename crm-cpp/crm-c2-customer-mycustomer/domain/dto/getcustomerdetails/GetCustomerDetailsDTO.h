#pragma once
/*
* 负责人: 老菌
*/
#include "stdafx.h"
#ifndef _GETCUSTOMERDETAILS_DTO_
#define _GETCUSTOMERDETAILS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户详情传输对象
 */
class GetCustomerDetailsDTO : public oatpp::DTO
{
	DTO_INIT(GetCustomerDetailsDTO, DTO);

	// 客户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	//客户代表
	API_DTO_FIELD_DEFAULT(String, linkman, ZH_WORDS_GETTER("customer.field.linkman"));

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

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMERDETAILS_DTO_