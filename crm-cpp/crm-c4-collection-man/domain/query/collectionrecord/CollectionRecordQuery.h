#pragma once


#ifndef _COLLECTIONRECORD_QUERY_
#define _COLLECTIONRECORD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CollectionRecordQuery : public PageQuery
{
	DTO_INIT(CollectionRecordQuery, PageQuery);
	// 回款编号
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.customer_name");
	}
	// 客户名称
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.start_time");
	}
	// 合同订单
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.end_time");
	}


};



#endif // !1
