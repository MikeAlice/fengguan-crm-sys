#include "stdafx.h"
#include "GetCustomerService.h"


GetCustomerPageDTO::Wrapper GetCustomerService::getCustomer(const GetCustomerQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetCustomerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetCustomerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<GetCustomerDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (GetCustomerDO sub : result)
	{
		auto dto = GetCustomerDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name,customer_id,Customer_Id,owner_user_id,Owner_User_Id,conn_time,Conn_Time,\
		conn_body,Conn_Body,next_time,Next_Time)
		pages->addData(dto);
	}
	return pages;
}