#pragma once
/*
* 地灵殿
*/
#ifndef BASECUSTOMERDTO_H__
#define  BASECUSTOMERDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户基类传输对象
 */
class BaseCustomerDTO : public oatpp::DTO
{
//public:
	DTO_INIT(BaseCustomerDTO, DTO);
	// 客户ID
	DTO_FIELD(UInt32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("customer.field.customer_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // BASECUSTOMERDTO_H__