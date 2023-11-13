#include "stdafx.h"
#include "GetCustomerNameService.h"


GetCustomerNameJsonVO::Wrapper GetCustomerNameService::getName(const GetCustomerNameQuery::Wrapper& query)
{
	// 构建返回对象
	auto vo = GetCustomerNameJsonVO::createShared();

	GetCustomerNameDAO dao;
	// 通过name查询数据
	list<GetCustomerNameDO> result = dao.selectByName(query);
	// 将DO转换成DTO
	for (GetCustomerNameDO sub : result)
	{
		auto dto = GetCustomerNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, customer_id, Customer_Id)
		vo->data->push_back(dto);
	}
	if (vo->data->size() == 0) {
		vo->message = u8"查询结果为空";
	}
	else {
		vo->message = u8"查询结果不为空";
	}
	return vo;
}