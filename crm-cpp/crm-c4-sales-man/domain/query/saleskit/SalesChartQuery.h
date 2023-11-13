#pragma once

#ifndef _SALESCAHART_QUERY_
#define _SALESCAHART_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 销售榜查询对象
 */
class SalesChartQuery : public PageQuery
{
	DTO_INIT(SalesChartQuery, PageQuery);
	// 排名
	API_DTO_FIELD_DEFAULT(Int32, rank_id, ZH_WORDS_GETTER("sales-chart.field.rank"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sales-chart.field.name"));
	// 销售金额
	API_DTO_FIELD_DEFAULT(Int32, amount, ZH_WORDS_GETTER("sales-chart.field.amount"));
	// 合同总数
	API_DTO_FIELD_DEFAULT(Int32, total, ZH_WORDS_GETTER("sales-chart.field.total"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCAHART_QUERY_
