#ifndef _DICTCLASSIFY_SERVICE_
#define _DICTCLASSIFY_SERVICE_
#include <list>
#include "domain/vo/dictclassify/DictClassifyVO.h"
#include "domain/query/dictclassify/DictClassifyQuery.h"
#include "domain/dto/dictclassify/DictClassifyDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DictClassifyService
{
public:

	oatpp::List<DictClassifyListDTO::Wrapper>  getlistAll(const DictClassifyListQuery::Wrapper& query);
	// 分页查询所有数据
	DictClassifyPageDTO::Wrapper listAll(const DictClassifyQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const DictClassifyDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const DictClassifyDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_DICTCLASSIFY_SERVICE_