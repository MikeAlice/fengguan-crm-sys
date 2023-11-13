#pragma once
#ifndef _CONTRACTAMOUNT_SERVICE_
#define _CONTRACTAMOUNT_SERVICE_
#include <list>
#include "domain/vo/contractamount/ContractamountVO.h"
#include "domain/query/contractamount/ContractamountQuery.h"
#include "domain/dto/contractamount/ContractamountDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ContractamountService
{
public:
	// 查询合同金额
	ContractamountDTO::Wrapper listAmount(const ContractamountQuery::Wrapper& query);
};

#endif // !_CONTRACTAMOUNT_SERVICE_