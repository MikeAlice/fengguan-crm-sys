#include "stdafx.h"
#include "GetSalContListService.h"

GetSalContListDTO::Wrapper GetSalContListService::getTitle(const GetSalContListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetSalContListDTO::createShared();

	GetSalContListDAO dao;
	// 通过name查询数据
	list<SalesContractDO> result = dao.selectByTitle(query);
	// 将DO转换成DTO
	for (SalesContractDO sub : result)
	{
		auto dto = GetSalContDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, title, Title, contract_id, Contract_id)
			pages->addData(dto);
	}
	return pages;
}