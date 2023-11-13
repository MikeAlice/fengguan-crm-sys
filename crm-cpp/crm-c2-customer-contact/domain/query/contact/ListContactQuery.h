#pragma once
/*
* 负责人：老菌
*/
#ifndef _LISTCONTACTQUERY_QUERY_
#define _LISTCONTACTQUERY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ListContactQuery :public PageQuery
{
	DTO_INIT(ListContactQuery, PageQuery);
	// 查询关键词 
	DTO_FIELD(String, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("contact.controller.query-contact-key");
	}
	// 客户名称
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("customer.field.name");
	}
	// 通信地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("contact.field.address");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTCONTACTQUERY_QUERY_