#ifndef _GETCUSTOMERNAME_QUERY_
#define _GETCUSTOMERNAME_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取客户名称列表查询对象
 */
class GetCustomerNameQuery : public PageQuery
{
	DTO_INIT(GetCustomerNameQuery, PageQuery);
	// 客户名称关键词
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("getcustomername.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMERNAME_QUERY_