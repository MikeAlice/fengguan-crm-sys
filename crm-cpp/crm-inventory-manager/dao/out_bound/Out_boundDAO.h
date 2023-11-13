#pragma once

#ifndef _OUTSTOCK_DAO_
#define _OUTSTOCK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/out_bound/Out_boundDO.h"
#include "../../domain/query/out_bound/Out_boundQuery.h"
#include "../../domain/dto/out_bound/Out_boundDTO.h"

/**
 * 出库单数据库操作实现
 */
class Out_boundDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const Out_boundQuery::Wrapper& query);

	// 确认出库（修改出库状态） 负责人：千亿
	uint64_t update(const Out_boundDO& uObj);
	// 删除出库单（通过出库单ID删除数据） 负责人：千亿
	uint64_t removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto);
};
#endif // !_OUTSTOCK_DAO_