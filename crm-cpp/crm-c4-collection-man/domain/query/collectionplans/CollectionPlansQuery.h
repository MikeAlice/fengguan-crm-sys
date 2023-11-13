#pragma once

#ifndef _COLLECTIONS_QUERY_
#define _COLLECTIONS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class CollectionPlansQuery : public PageQuery
{
	DTO_INIT(CollectionPlansQuery, PageQuery);
	// һ��4��
	//  ��ѯ�ؿʼ��ʱ��
	DTO_FIELD(String, backdate);
	DTO_FIELD_INFO(backdate) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.backdate");
	}
	//  ��ѯ������ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.begindate");
	}
	//  ��ѯ�Ƿ񸶿�
	DTO_FIELD(String, ifpay);
	DTO_FIELD_INFO(ifpay) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.ifpay");
	}
	//  ��ѯcontract_name
	DTO_FIELD(String, contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("collectionplans.field.contract_name");
	}


};

#include OATPP_CODEGEN_END(DTO)
#endif // !