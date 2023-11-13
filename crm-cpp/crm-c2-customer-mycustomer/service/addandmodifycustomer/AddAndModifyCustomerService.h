#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/customer/DetailsCustomerDTO.h"	
#include "domain/dto/customer/ModifyCustomerDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class AddAndModifyCustomerService
{
public:
	// ��������
	uint64_t saveData(const DetailsCustomerDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const ModifyCustomerDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_
