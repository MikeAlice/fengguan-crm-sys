#include "stdafx.h"
#include "QueryCapitalRecordService.h"
#include "dao/fincapitalrecord/querycapitalrecord/QueryCapitalRecordDAO.h"
#include "domain/do/fincapitalrecord/CapitalRecordDO.h"

CapitalRecordPageDTO::Wrapper QueryCapitalRecordService::listAll(const CapitalRecordPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CapitalRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QueryCapitalRecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CapitalRecordDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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

