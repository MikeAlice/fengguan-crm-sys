#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customer/CustomerDO.h"

/**
 * 示例表数据库操作实现
 */
class AddAndModifyCustomerDAO : public BaseDAO
{
public:
	// 添加客户
	uint64_t insert(const CustomerDO& iObj);
	// 修改客户信息
	int update(const CustomerDO& uObj);
	
};
#endif // !_SAMPLE_DAO_
