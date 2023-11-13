#include "stdafx.h"
#include "ContactService.h"
#include "../../dao/contact/ContactDAO.h"

ListContactPageDTO::Wrapper ContactService::listAll(const ContactQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ListContactPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContactDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContactDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContactDO sub : result)
	{
		auto dto =  ListContactDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, customer_id, Customer_Id, name, Name, gender, Gender, postion, Postion, mobile, Mobile, qicq,Qicq,tel,Tel)
			pages->addData(dto);

	}
	return pages;
}

