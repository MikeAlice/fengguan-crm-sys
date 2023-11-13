#include "stdafx.h"
#include "QueryBankAccountService.h"
#include "domain/do/fincapitalrecord/BankAccountDO.h"
#include "dao/fincapitalrecord/querybankaccount/QueryBankAccountDAO.h"

BankAccountPageDTO::Wrapper QueryBankAccountService::listAll(const BankAccountPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = BankAccountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QueryBankAccountDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<BankAccountDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (BankAccountDO sub : result)
	{
		auto dto = BankAccountDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			name, Name, card, Card)
			pages->addData(dto);
	}
	return pages;
}
