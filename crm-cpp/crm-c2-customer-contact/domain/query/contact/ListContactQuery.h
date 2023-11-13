#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _LISTCONTACTQUERY_QUERY_
#define _LISTCONTACTQUERY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ListContactQuery :public PageQuery
{
	DTO_INIT(ListContactQuery, PageQuery);
	// ��ѯ�ؼ��� 
	DTO_FIELD(String, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("contact.controller.query-contact-key");
	}
	// �ͻ�����
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("customer.field.name");
	}
	// ͨ�ŵ�ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("contact.field.address");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTCONTACTQUERY_QUERY_