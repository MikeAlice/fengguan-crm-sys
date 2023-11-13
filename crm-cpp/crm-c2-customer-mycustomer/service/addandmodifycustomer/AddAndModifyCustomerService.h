#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/customer/DetailsCustomerDTO.h"	
#include "domain/dto/customer/ModifyCustomerDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AddAndModifyCustomerService
{
public:
	// 保存数据
	uint64_t saveData(const DetailsCustomerDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const ModifyCustomerDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_
