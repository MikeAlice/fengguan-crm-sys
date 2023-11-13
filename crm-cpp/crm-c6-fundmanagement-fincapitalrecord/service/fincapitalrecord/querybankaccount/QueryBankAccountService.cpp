#include "stdafx.h"
#include "QueryBankAccountService.h"
#include "domain/do/fincapitalrecord/BankAccountDO.h"
#include "dao/fincapitalrecord/querybankaccount/QueryBankAccountDAO.h"

BankAccountPageDTO::Wrapper QueryBankAccountService::listAll(const BankAccountPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = BankAccountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	QueryBankAccountDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<BankAccountDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (BankAccountDO sub : result)
	{
		auto dto = BankAccountDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			name, Name, card, Card)
			pages->addData(dto);
	}
	return pages;
}
