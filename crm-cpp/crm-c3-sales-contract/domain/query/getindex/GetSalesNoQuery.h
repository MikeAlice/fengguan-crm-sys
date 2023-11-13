#ifndef _GETESALESNO_QUERY_
#define _GETESALESNO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ѯ����
 */
class GetSalesNoQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(GetSalesNoQuery, DTO);
	//���ۻ���id  Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(UInt64, chance_id, ZH_WORDS_GETTER("Opportunity.field.chance_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALESNO_QUERY_
