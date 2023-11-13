#pragma once
#ifndef INSTORAGESERVICE_H__
#define INSTORAGESERVICE_H__
#include <list>
#include "domain/vo/in_storage/InStorageJsonVO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "dao/in_storage/InStorageDAO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class InStorageService
{
public:
	//是否入库
	bool updateIsStorage(const ModifyByIDStorageDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	//通过id查询数据是否已入库
	bool selectByQuery(const InStorageQuery::Wrapper& query);
	// 分页查询所有数据
	InStoragePageDTO::Wrapper listAll(const InStorageQuery::Wrapper& query);
	// 查询单个数据
	InStorageDTO::Wrapper listOne(uint64_t id);
	// 保存数据
	uint64_t saveData(const AddInStorageDTO::Wrapper& dto);
};

#endif // !INSTORAGESERVICE_H__