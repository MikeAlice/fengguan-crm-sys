#include "stdafx.h"
#include "SalOppListService.h"
#include "SnowFlake.h"
#include "dao/SalesOpportunityList/SalOppListDAO.h"
#include "domain/do/Sales/Cst_chanceDO.h"

SaleopportPgaeDTO::Wrapper querySalOppListService::listAll(const SaleopportPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = SaleopportPgaeDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	querySalOppListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<Cst_chanceDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (Cst_chanceDO sub : result)
	{
		auto dto = SaleopportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			name, Name, customer_id, Customer_id, find_date, Find_date, bill_date, Bill_date,
			money, Money, salestage, Salestage, intro, Intro, create_time, Create_time, 
			customer_name, Customer_name, linkman_name, Linkman_name, chance_id, Chance_id)
			pages->addData(dto);
	}
	return pages;
}

