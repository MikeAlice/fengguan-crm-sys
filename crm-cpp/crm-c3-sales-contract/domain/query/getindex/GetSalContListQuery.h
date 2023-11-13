#ifndef _GETESALCONTLIST_QUERY_H_
#define _GETESALCONTLIST_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class GetSalContListQuery : public oatpp::DTO
{
	DTO_INIT(GetSalContListQuery, DTO);
	// ���ۺ�ͬ����
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("getindex.field.title");
	}
	// �ͻ�ID
	DTO_FIELD(Int32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("getindex.field.customer_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALCONTLIST_QUERY_H_
