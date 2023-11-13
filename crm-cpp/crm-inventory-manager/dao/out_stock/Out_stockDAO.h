#pragma once

#ifndef _OUTSTOCK_DAO_
#define _OUTSTOCK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/out_stock/Out_stockDO.h"
#include "../../domain/query/out_stock/Out_StockQuery.h"
#include "../../domain/dto/out_stock/Out_stockDTO.h"

/**
 * 出库单数据库操作实现
 */
class Out_stockDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t counts(const Out_StockQuery::Wrapper& query);

	// 分页查询出库单列表 负责人：小彬
	list<Out_StockPagDO> selectWithPage(const Out_StockQuery::Wrapper& query);

	// 通过id查询出库明细 负责人：小彬
	list<Out_StocDetailDO> selectById(const string& id);

	// 添加出库单 负责人：小彬
	uint64_t insert(const AddOut_StockDO& iObj);

};

#endif // !_OUTSTOCK_DAO_