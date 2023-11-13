#pragma once
#ifndef _SALESCONTRACTDAO_H_
#define _SALESCONTRACTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/contractindex/AddSalesContractDO.h"


/**
 * 销售合同数据库操作实现
 */
class SalesContractDAO : public BaseDAO
{
public:

	// 原味的原味包
	// 插入数据
	uint64_t insert(const AddSalesContractDO& iObj);

	// 原味的原味包
	// 通过合同编号删除数据
	int deleteByNo(string contract_no);
};
#endif // !_SAMPLE_DAO_
