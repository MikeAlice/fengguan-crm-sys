/*
* 负责人：老菌
*/
#include "stdafx.h"
#include "GetCustomerDetailsService.h"
#include "dao/getcustomerdetails/GetCustomerDetailsDAO.h"

GetCustomerDetailsDTO::Wrapper GetCustomerDetailsService::getCustomerDetails(GetCustomerDetailsQuery::Wrapper query)
{
	// 构建返回对象,返回客户信息
	auto data = GetCustomerDetailsDTO::createShared();

	GetCustomerDetailsDAO dao;

	list<CustomerDO> result = dao.selectAll(query);
	// 将DO转换成DTO
	for (CustomerDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, name, Name, linkman, Linkman, source, Source, grade, Grade, \
			industry, Industry, mobile, Mobile, tel, Tel, address, Address, intro, Intro, needs, Needs);
		break;
	}
	return data;
}
