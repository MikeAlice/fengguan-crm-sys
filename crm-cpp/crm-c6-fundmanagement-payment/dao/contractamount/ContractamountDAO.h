#pragma once
#ifndef _CONTRACTAMOUNT_DAO_
#define _CONTRACTAMOUNT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contractamount/ContractamountDO.h"
#include "../../domain/query/contractamount/ContractamountQuery.h"

/**
 * 示例表数据库操作实现
 */
class ContractamountDAO : public BaseDAO
{
public:
	//查询总金额
	uint64_t getTotal(const ContractamountQuery::Wrapper& query);
	//查询去零金额
	uint64_t getZero(const ContractamountQuery::Wrapper& query);
	//查询已付金额
	uint64_t getPaid(const ContractamountQuery::Wrapper& query);
	//查询已收发票金额
	uint64_t getInvoice(const ContractamountQuery::Wrapper& query);
};
#endif // !_CONTRACTAMOUNT_DAO_