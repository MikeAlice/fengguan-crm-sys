/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#include "GetContactListService.h"

ListContactPageDTO::Wrapper GetContactListService::getContactList(const ListContactQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ListContactPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetContactListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ListContactDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ListContactDO sub : result)
	{
		auto dto = ListContactDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, linkman_id, Linkman_Id, customer_name, Customer_Name, link_name, Name, \
			gender, Gender, postion, Postion, tel, Tel, mobile, Mobile, qicq, Qicq);
			pages->addData(dto);
	}
	return pages;
}
