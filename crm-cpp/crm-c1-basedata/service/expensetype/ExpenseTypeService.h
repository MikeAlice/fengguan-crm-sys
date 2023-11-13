#pragma once
#ifndef _EXPENSETYPE_SERVICE_
#define _EXPENSETYPE_SERVICE_
#include <list>
#include "domain/vo/expensetype/ExpenseTypeVO.h"
#include "domain/query/expensetype/ExpenseTypeQuery.h"
#include "domain/dto/expensetype/ExpenseTypeDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ExpenseTypeService
{
public:
	// 分页查询所有数据
	ExpenseTypePageDTO::Wrapper listAll(const ExpenseTypeQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ExpenseTypeDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ExpenseTypeDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};
/**
 * 费用收入类型服务实现
 */
class ExpenseService
{
public:

	//查询结构树
	ExpenseTreeJsonVO::Wrapper listTree(const ExpenseQuery::Wrapper& query);

};

#endif // !_EXPENSETYPE_SERVICE_