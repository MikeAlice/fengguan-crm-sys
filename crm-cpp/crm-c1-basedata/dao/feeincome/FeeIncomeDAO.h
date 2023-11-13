#ifndef _FeeIncome_DAO_
#define _FeeIncome_DAO_
#include "BaseDAO.h"
#include "../../domain/do/feeincome/FeeIncomeDO.h"
#include "../../domain/query/feeincome/FeeIncomeQuery.h"

/**
 * 示例表数据库操作实现
 */
class FeeIncomeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const FeeIncomeQuery::Wrapper& query);
	// 分页查询数据
	std::list<FeeIncomeDO> selectWithPage(const FeeIncomeQuery::Wrapper& query);
	uint64_t insert(const FeeIncomeDO& iObj);
	// 修改数据
	int update(const FeeIncomeDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	//查询全部
	list<FeeIncomeDO> selectALL();
	//获取名称结构树（指定父节点和查询深度）
	list<FeeIncomeDO> selectTree(const FeeIncomeQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_
