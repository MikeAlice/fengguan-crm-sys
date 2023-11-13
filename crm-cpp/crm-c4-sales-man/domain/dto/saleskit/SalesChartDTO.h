#pragma once

#ifndef _SALESCHARTDTO_H_
#define _SALESCHARTDTO_H_

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 修改销售榜对象传输数据
*/
class SalesChartDTO :public oatpp::DTO
{
	DTO_INIT(SalesChartDTO, DTO);
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
#endif // !_SALESCHARTDTO_H_

