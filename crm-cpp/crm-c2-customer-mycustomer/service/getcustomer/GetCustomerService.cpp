#include "stdafx.h"
#include "GetCustomerService.h"


GetCustomerPageDTO::Wrapper GetCustomerService::getCustomer(const GetCustomerQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetCustomerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetCustomerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GetCustomerDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GetCustomerDO sub : result)
	{
		auto dto = GetCustomerDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name,customer_id,Customer_Id,owner_user_id,Owner_User_Id,conn_time,Conn_Time,\
		conn_body,Conn_Body,next_time,Next_Time)
		pages->addData(dto);
	}
	return pages;
}