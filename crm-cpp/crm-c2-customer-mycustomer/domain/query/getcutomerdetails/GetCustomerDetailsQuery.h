#pragma once
#ifndef _GETCUSTOMERDETAILS_QUERY_
#define _GETCUSTOMERDETAILS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class GetCustomerDetailsQuery :public PageQuery
{
	DTO_INIT(GetCustomerDetailsQuery, PageQuery);
	// �ͻ�����
	DTO_FIELD(UInt32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("customer.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMERDETAILS_QUERY_