#ifndef _GETCUSTOMER_QUERY_
#define _GETCUSTOMER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取客户列表分页查询对象
 */
class GetCustomerQuery : public PageQuery
{
	DTO_INIT(GetCustomerQuery, PageQuery);
	// 最近联系时间
	DTO_FIELD(String, conn_time);
	DTO_FIELD_INFO(conn_time) {
		info->description = ZH_WORDS_GETTER("getcustomer.field.conn_time");
	}
	// 下次联系时间
	DTO_FIELD(String, next_time);
	DTO_FIELD_INFO(next_time) {
		info->description = ZH_WORDS_GETTER("getcustomer.field.next_time");
	}
	// 客户名称关键词
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("getcustomer.field.name");
	}
	// 电话
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("getcustomer.field.mobile");
	}
	// 手机号
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("getcustomer.field.tel");
	}
	// 联系地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("getcustomer.field.address");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMER_QUERY_
