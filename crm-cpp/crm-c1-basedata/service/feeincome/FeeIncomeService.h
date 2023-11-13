#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/feeincome/FeeIncomeTreeVO.h"
#include "domain/query/feeincome/FeeIncomeQuery.h"
#include "domain/dto/feeincome/FeeIncomeDTO.h"


/**
 * 费用收入类型服务实现
 */
class FeeIncomeService
{
public:
	// 分页查询所有数据
	FeeIncomePageDTO::Wrapper listAll(const FeeIncomeQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const FeeIncomeDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const FeeIncomeDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	//查询结构树
	FeeIncomeTreeJsonVO::Wrapper listTree(const FeeIncomeQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_

