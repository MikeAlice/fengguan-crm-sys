#include "stdafx.h"
#include "CollectionPlansService.h"
#include "domain/do/collectionplans/GetCollectionPlanListDO.h"
#include <dao/collectionplans/CollectionPlansDAO.h>
#include "SimpleDateTimeFormat.h"

GetCollectionPlanListPageDTO::Wrapper CollectionPlansService::listAll(const CollectionPlansQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetCollectionPlanListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CollectionPlansDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	// 计算总页数
	pages->calcPages();
	list<GetCollectionPlanListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GetCollectionPlanListDO sub : result)
	{
		auto dto = GetCollectionPlanListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Customer_name, contract_name, Contract_name, backdate, Plan_date, stages, Stages, money, Money, create_user_id, Create_user_id, create_time, Create_time, ifpay, Ifpay)
			pages->addData(dto);

	}
	return pages;
}

uint64_t CollectionPlansService::saveData(const AddCollectionPlanDTO::Wrapper& dto, const int32_t create_user_id)
{
	// 组装DO数据
	GetCollectionPlanListDO data;
	data.setCreate_user_id(create_user_id);
	SimpleDateTimeFormat create_time;
	data.setCreate_time(create_time.format());
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Customer_name, name, Contract_name, contract_name, Contract_id, contract_id, Customer_id, customer_id, Plan_date, backdate, Stages, stages, Money, money)
		// 执行数据添加
		CollectionPlansDAO dao;
	return dao.insert(data);

	return 0;
}
