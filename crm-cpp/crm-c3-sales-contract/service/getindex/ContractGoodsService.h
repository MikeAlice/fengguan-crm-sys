#pragma once
#ifndef _CONTRACTGOODSSERVICE_H_
#define _CONTRACTGOODSSERVICE_H_

#include "domain/dto/getindex/ContractGoodsDTO.h"
#include "domain/query/getindex/ContractGoodsQuery.h"

class ContractGoodsService {
public:
	// 原味的原味包
	// 分页查询合同对应的商品
	ContractGoodsPageDTO::Wrapper listAll(const ContractGoodsQuery::Wrapper& query);
};


#endif // !_CONTRACTGOODSSERVICE_H_


