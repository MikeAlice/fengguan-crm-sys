#ifndef _DICTMANAGE_SERVICE_
#define _DICTMANAGE_SERVICE_
#include <list>
#include "domain/vo/dictmanage/DictVO.h"
#include "domain/query/dictmanage/DictQuery.h"
#include "domain/dto/dictmanage/DictDTO.h"

/**
 * 服务实现-字典管理
 */
class DictManageService
{
public:
	// 分页查询所有数据
	DictPageDTO::Wrapper listAll(const DictQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const DictDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const DictDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	//获取下拉列表
	oatpp::List<DictTypeListDTO::Wrapper> getPage();
};

#endif // !_DICTMANAGE_SERVICE_
