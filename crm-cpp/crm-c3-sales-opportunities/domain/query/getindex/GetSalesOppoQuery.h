#ifndef _GETESALESOPPO_QUERY_
#define _GETESALESOPPO_QUERY_

#include "../../GlobalInclude.h"
//#include "../../dto/getindex/GetSalesOppoDTO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例查询对象
 */
class GetSalesOppoQuery : public oatpp::DTO
{
	DTO_INIT(GetSalesOppoQuery, DTO);
		// 客户ID
		DTO_FIELD(Int32, customer_id);
		DTO_FIELD_INFO(customer_id) {
			info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id");
		}
		// 销售主题
		DTO_FIELD(String, name);
		DTO_FIELD_INFO(name) {
			info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
		}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETESALESOPPO_QUERY_
