#ifndef _BANKACCOUNT_DAO_
#define _BANKACCOUNT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/bankaccount/BankAccountDO.h"
#include "../../domain/query/bankaccount/BankAccountQuery.h"
#include"../../domain/dto/bankaccount/BankAccountDTO.h"
/**
 * 示例表数据库操作实现
 */
class BankAccountDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const BankAccountQuery::Wrapper& query);
	// 分页查询数据
	list<BankAccountDO> selectWithPage(const BankAccountQuery::Wrapper& query);
	////获取下拉列表
	list<BankAccountListDO> selectWithList(const BankAccountListQuery::Wrapper& query);
	// 通过姓名查询数据
	list<BankAccountDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const BankAccountDO& iObj);
	// 修改数据
	int update(const BankAccountDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	// 导出数据
	std::list<BankAccountDO> selectexport(const oatpp::List<BankAccountExportDTO::Wrapper>& dto);
	list<BankAccountListDO> selectPage();

};
#endif // !_BANKACCOUNT_DAO_
