#include "stdafx.h"
#include "ContactService.h"
#include "../../dao/contact/ContactDAO.h"

ListContactPageDTO::Wrapper ContactService::listAll(const ContactQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ListContactPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ContactDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ContactDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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

