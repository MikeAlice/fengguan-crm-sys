#include "stdafx.h"
#include "GetSalContListService.h"

GetSalContListDTO::Wrapper GetSalContListService::getTitle(const GetSalContListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetSalContListDTO::createShared();

	GetSalContListDAO dao;
	// ͨ��name��ѯ����
	list<SalesContractDO> result = dao.selectByTitle(query);
	// ��DOת����DTO
	for (SalesContractDO sub : result)
	{
		auto dto = GetSalContDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, title, Title, contract_id, Contract_id)
			pages->addData(dto);
	}
	return pages;
}