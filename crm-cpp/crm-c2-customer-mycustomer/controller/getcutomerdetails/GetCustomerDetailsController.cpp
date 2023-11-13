#include"stdafx.h"
#include "controller/getcutomerdetails/GetCustomerDetailsController.h"

GetCustomerDetailsJsonVO::Wrapper GetCustomerDetailsController::execQueryCustomerDetails(GetCustomerDetailsQuery::Wrapper query, const PayloadDTO& playload)
{
	// ����һ��Service
	GetCustomerDetailsService service;
	// ��ѯ����
	auto result = service.getCustomerDetails(query);
	// ��Ӧ���
	auto jvo = GetCustomerDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
