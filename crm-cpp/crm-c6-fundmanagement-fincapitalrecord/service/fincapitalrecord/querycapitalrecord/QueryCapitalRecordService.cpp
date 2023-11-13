#include "stdafx.h"
#include "QueryCapitalRecordService.h"
#include "dao/fincapitalrecord/querycapitalrecord/QueryCapitalRecordDAO.h"
#include "domain/do/fincapitalrecord/CapitalRecordDO.h"

CapitalRecordPageDTO::Wrapper QueryCapitalRecordService::listAll(const CapitalRecordPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CapitalRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	QueryCapitalRecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CapitalRecordDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CapitalRecordDO sub : result)
	{
		auto dto = CapitalRecordDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			record_id, RecordId, type, Type, create_user, CreateUser,
			bank_id, BankId, bank_name, BankName, bank_card, BankCard, 
			money, Money, intro, Intro,create_time, CreateTime, happen_date, HappenDate)
			pages->addData(dto);
	}
	return pages;
}

