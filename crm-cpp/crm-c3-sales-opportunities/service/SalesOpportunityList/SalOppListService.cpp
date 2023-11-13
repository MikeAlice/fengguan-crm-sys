#include "stdafx.h"
#include "SalOppListService.h"
#include "SnowFlake.h"
#include "dao/SalesOpportunityList/SalOppListDAO.h"
#include "domain/do/Sales/Cst_chanceDO.h"

SaleopportPgaeDTO::Wrapper querySalOppListService::listAll(const SaleopportPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SaleopportPgaeDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	querySalOppListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<Cst_chanceDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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

