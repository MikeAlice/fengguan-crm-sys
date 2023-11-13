#pragma once
#ifndef _CONTRACTGOODSDAO_H_
#define _CONTRACTGOODSDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/getindex/ContractGoodsDO.h"
#include "../../domain/query/getindex/ContractGoodsQuery.h"

/**
 * 合同清单操作实现
 */
class ContractGoodsDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ContractGoodsQuery::Wrapper& query);
	// 分页查询数据
	list<ContractGoodsDO> selectWithPage(const ContractGoodsQuery::Wrapper& query);

	//// 通过姓名查询数据
	//list<ContractGoodsDO> selectByName(const string& name);
	//// 插入数据
	//uint64_t insert(const ContractGoodsDO& iObj);
	//// 修改数据
	//int update(const ContractGoodsDO& uObj);
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif 