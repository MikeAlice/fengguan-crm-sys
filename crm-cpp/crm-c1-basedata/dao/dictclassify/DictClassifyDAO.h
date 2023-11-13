#ifndef _DICTCLASSIFY_DAO_
#define _DICTCLASSIFY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dictclassify/DictClassifyDO.h"
#include "../../domain/query/dictclassify/DictClassifyQuery.h"
/**
 * 示例表数据库操作实现
 */
class DictClassifyDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const DictClassifyQuery::Wrapper& query);
	// 分页查询数据
	list<DictClassifyDO> selectWithPage(const DictClassifyQuery::Wrapper& query);
	// 通过姓名查询数据
	list<DictClassifyDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const DictClassifyDO& iObj);
	// 修改数据
	int update(const DictClassifyDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	////获取下拉列表
	list<DictClassifyListDO> selectPage();
};
#endif // !_DICTCLASSIFY_DAO_
