#ifndef _BANKACCOUNT_SERVICE_
#define _BANKACCOUNT_SERVICE_
#include <list>
#include "domain/vo/bankaccount/BankAccountVO.h"
#include "domain/query/bankaccount/BankAccountQuery.h"
#include "domain/dto/bankaccount/BankAccountDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class BankAccountService
{
public:

	// 将查询到的数据导出为文件
	std::string exportData(const oatpp::List<BankAccountExportDTO::Wrapper>& dto);	// 获取下拉列表
	/*BankAccountDropListDTO::Wrapper getlistAll(const BankAccountListQuery::Wrapper& query);*/
	oatpp::List<BankAccountListDTO::Wrapper> getlistAll(const BankAccountListQuery::Wrapper& query);
	// 分页查询所有数据
	BankAccountPageDTO::Wrapper listAll(const BankAccountQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const BankAccountDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const BankAccountDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_BANKACCOUNT_SERVICE_
