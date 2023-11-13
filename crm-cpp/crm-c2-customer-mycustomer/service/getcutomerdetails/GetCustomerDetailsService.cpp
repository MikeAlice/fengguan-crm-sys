/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#include "GetCustomerDetailsService.h"
#include "dao/getcustomerdetails/GetCustomerDetailsDAO.h"

GetCustomerDetailsDTO::Wrapper GetCustomerDetailsService::getCustomerDetails(GetCustomerDetailsQuery::Wrapper query)
{
	// �������ض���,���ؿͻ���Ϣ
	auto data = GetCustomerDetailsDTO::createShared();

	GetCustomerDetailsDAO dao;

	list<CustomerDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (CustomerDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, name, Name, linkman, Linkman, source, Source, grade, Grade, \
			industry, Industry, mobile, Mobile, tel, Tel, address, Address, intro, Intro, needs, Needs);
		break;
	}
	return data;
}
