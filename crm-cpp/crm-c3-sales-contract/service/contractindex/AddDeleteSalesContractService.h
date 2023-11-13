#pragma once
#ifndef _SALESCONTRACTSERVICE_H_
#define _SALESCONTRACTSERVICE_H_

#include "../../domain/dto/contractindex/AddSalesContractDTO.h"
#include "../../domain/do/contractindex/AddSalesContractDO.h"
#include "../../dao/contractindex/AddDeleteSalesContractDAO.h"



class SalesContractService
{
public:
	// 原味的原味包
	// 添加数据
	uint64_t saveData(const AddSalesContractDTO::Wrapper& dto);
	// 原味的原味包
	// 删除数据
	bool removeData(const std::string& contract_no);
};


#endif // !_SALESCONTRACTSERVICE_H_




