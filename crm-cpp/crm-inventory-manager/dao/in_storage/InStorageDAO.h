#pragma once
#ifndef INSTORAGEDAO_H_
#define INSTORAGEDAO_H_

#include "BaseDAO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "domain/do/in_storage/InStorageDO.h"
#include "dao/in_storage/InStorageMapper.h"
class InStorageDAO :public BaseDAO {
public:
	//通过id查询数据是否已入库
	bool updateById(const InStorageDO2& uObj);
	//通过id查询相应的入库表明细
	InStorageDO selectById(uint64_t id);
	// 统计符合要求的入库单条数
	uint64_t countInStorageList(const InStorageQuery::Wrapper& query);
	// 分页查询数据
	list<InStorageDO> selectWithPage(const InStorageQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const InStorageDO& iObj);
	// 修改数据
	int update(const InStorageDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};


#endif // !INSTORAGEDAO_H_
