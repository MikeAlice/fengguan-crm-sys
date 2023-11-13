#ifndef _GETESALESNO_QUERY_
#define _GETESALESNO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例查询对象
 */
class GetSalesNoQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(GetSalesNoQuery, DTO);
	//销售机会id  唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, chance_id, ZH_WORDS_GETTER("Opportunity.field.chance_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALESNO_QUERY_
