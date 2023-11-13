#include "stdafx.h"
#include "PayrecordsService.h"
#include "domain/do/payrecords/PayrecordsDO.h"
#include "dao/payrecords/PayrecordsDAO.h"
PayrecordsPageDTO::Wrapper PayrecordsService::listAll(const PayrecordsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PayrecordsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PayrecordsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PayrecordsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PayrecordsDO sub : result)
	{
		auto dto = PayrecordsDTO::createShared();
		 		/*dto->supplier_name = sub.getSupplier_name();
		 		dto->contract_name = sub.getContract_name();
		 		dto->pay_date = sub.getPay_date();
		 		dto->create_user_id = sub.getCreate_user_id();
		 		dto->record_id = sub.getRecord_id();
		 		dto->bank_id = sub.getBank_id();
		 		dto->supplier_id = sub.getSupplier_id();*/
		// 14个
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, supplier_name, Supplier_name, contract_name, Contract_name, pay_date, Pay_date, 
			create_user_id, Create_user_id,money, Money,zero_money, Zero_money, stages, Stages,
			create_time, Create_time, intro, Intro,record_id, Record_id, plan_id, Plan_id,
			contract_id, Contract_id, supplier_id, Supplier_id, bank_id, Bank_id)

		pages->addData(dto);

	}
	return pages;
}
