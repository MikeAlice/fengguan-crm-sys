
#ifndef _DICTMANAGE_DAO_
#define _DICTMANAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dictmanage/DictDO.h"
#include "../../domain/do/dictmanage/DictTypeDO.h"
#include "../../domain/query/dictmanage/DictQuery.h"

/**
 * 数据库操作实现-字典管理
 */
class DictDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const DictQuery::Wrapper& query);
	// 分页查询数据
	list<DictDO> selectWithPage(const DictQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const DictDO& iObj);
	// 修改数据
	int update(const DictDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	//查询分类名称
	list<DictTypeDO> selectPage();
};
#endif // !_DICTMANAGE_DAO_
