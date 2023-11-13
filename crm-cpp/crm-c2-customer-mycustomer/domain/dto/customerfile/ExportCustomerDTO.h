#pragma once
/*
* 负责人：老菌
*/
#ifndef _EXPORTCUSTOMER_DTO_
#define _EXPORTCUSTOMER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导出客户传输对象
 */
class ExportCustomerDTO : public oatpp::DTO
{
	DTO_INIT(ExportCustomerDTO, DTO);

	// 客户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	// 创建人员
	API_DTO_FIELD_DEFAULT(UInt32, create_user_id, ZH_WORDS_GETTER("customer.field.create_user_id"));

	// 创建人员名称
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("customer.field.create_user_name"));

	// 归属人员
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("customer.field.owner_user_id"));

	// 归属人员名称
	API_DTO_FIELD_DEFAULT(String, owner_user_name, ZH_WORDS_GETTER("customer.field.owner_user_name"));

	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("customer.field.create_time"));

	//下次沟通时间
	API_DTO_FIELD_DEFAULT(String, next_time, ZH_WORDS_GETTER("customer.field.next_time"));

	//最近联系时间
	API_DTO_FIELD_DEFAULT(String, conn_time, ZH_WORDS_GETTER("customer.field.conn_time"));

	//最近沟通内容
	API_DTO_FIELD_DEFAULT(String, conn_body, ZH_WORDS_GETTER("customer.field.conn_body"));

};

/**
 * 导出客户分页传输对象
 */
class ExportCustomerPageDTO : public PageDTO<ExportCustomerDTO::Wrapper>
{
	DTO_INIT(ExportCustomerPageDTO, PageDTO<ExportCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTCUSTOMER_DTO_