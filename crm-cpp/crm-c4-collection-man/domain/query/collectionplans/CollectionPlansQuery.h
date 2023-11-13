#pragma once

#ifndef _COLLECTIONS_QUERY_
#define _COLLECTIONS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class CollectionPlansQuery : public PageQuery
{
	DTO_INIT(CollectionPlansQuery, PageQuery);
	// 一共4个
	//  查询回款开始的时间
	DTO_FIELD(String, backdate);
	DTO_FIELD_INFO(backdate) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.backdate");
	}
	//  查询创建的时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.begindate");
	}
	//  查询是否付款
	DTO_FIELD(String, ifpay);
	DTO_FIELD_INFO(ifpay) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.ifpay");
	}
	//  查询contract_name
	DTO_FIELD(String, contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.contract_name");
	}


};

#include OATPP_CODEGEN_END(DTO)
#endif // !