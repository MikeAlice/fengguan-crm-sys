#include "stdafx.h"
#include"SalesChartService.h"
#include"../../dao/saleskit/SalesChartDAO.h"

// 查询排行榜数据  const SalesChartQuery::Wrapper& query
SalesChartDTO::Wrapper SalesChartService::listRank(const UInt64 date_id)
{
	auto pages = SalesChartDTO::createShared();

	//查询数据总条数
	SalesChartDAO dao;
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return pages;
	}
	
	// 销售金额排行榜
	list<SalesChartDO> result1 = dao.selectWithAmount(date_id);
	// 订单总数排行榜
	list<SalesChartDO> result2 = dao.selectWithTotal(date_id);

	// 将DO转换成DTO
	for (SalesChartDO sub : result1)
	{
		auto dto = SalesChartDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rank_id,Rank,name, Name, amount, Amount, total, Total);
			//pages->addData(dto);
	}
	
	for (SalesChartDO sub : result2)
	{
		auto dto = SalesChartDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rank_id, Rank, name, Name, amount, Amount, total, Total);
		//pages->addData(dto);
	}
	return pages;
}


// 查询数量统计数据
NumberCountingDTO::Wrapper NumberCountingService::listNumberCount(const UInt64 date_id)
{
	auto pages = NumberCountingDTO::createShared();

	NumberCountingDAO dao;

	list<NumberCountingDO> result = dao.selectByDate(date_id);
	// 将DO转换成DTO
	for (NumberCountingDO sub : result)
	{
		auto dto = NumberCountingDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, newly_add_business_opportunity, Newly_add_business_opportunity, newly_add_contract, Newly_add_contract,
			newly_add_follow_up_records, Newly_add_follow_up_records, newly_add_contact_people, Newly_add_contact_people,
			newly_add_contract_amount, Newly_add_contract_amount, newly_add_collection_amount, Newly_add_collection_amount);
		//pages->addData(dto);
	}
	return pages;
}
