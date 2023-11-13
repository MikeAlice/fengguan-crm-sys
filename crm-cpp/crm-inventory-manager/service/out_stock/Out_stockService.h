#pragma once

#ifndef OUT_STOCKSERVICE_H_
#define OUT_STOCKSERVICE_H_

#include "domain/dto/out_stock/Out_stockDTO.h"
#include"domain/query/out_stock/Out_StockQuery.h"
#include"domain/vo/out_stock/Out_StockPageJsonVO.h"
/**
 * 出库单服务实现
 */
class Out_stockService
{
public:
	// 分页查询出库列表		负责人：小彬
	Out_StockPageDTO::Wrapper listAll(const Out_StockQuery::Wrapper& query);
	//查询出库明细			负责人：小彬
	Out_stockDTO::Wrapper queryone(const string& id);
	// 添加出库单			负责人：小彬
	bool addData(const AddOut_stock::Wrapper& dto);

};

#endif // !OUT_STOCKSERVICE_H_