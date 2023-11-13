#ifndef _EXPENSETYPEDAO_
#define _EXPENSETYPEDAO_
#include "BaseDAO.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"

/**
 * 示例表数据库操作实现
 */
class ExpenseTypeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ExpenseTypeQuery::Wrapper& query);
	// 分页查询数据
	list<ExpenseTypeDO> selectWithPage(const ExpenseTypeQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ExpenseTypeDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ExpenseTypeDO& iObj);
	// 修改数据
	int update(const ExpenseTypeDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
/**
 * 费用支出类型数据库操作实现
 */
class ExpenseDAO : public BaseDAO
{
public:

	//查询全部
	list<ExpenseDO> selectALL();
	//获取名称结构树（指定父节点和查询深度）
	list<ExpenseDO> selectTree(const ExpenseQuery::Wrapper& query);
};
#endif // !_EXPENSETYPEDAO_
