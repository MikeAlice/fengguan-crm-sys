#pragma once
/*
* 负责人：老菌
*/
#ifndef _EXPORTCUSTOMER_DAO_
#define _EXPORTCUSTOMER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/systemuser/SystemUserDO.h"
#include "dao/customerfile/ImportCustomerMapper.h"

/**
 * 导入客户数据表操作实现
 */
class ImportCustomerDAO : public BaseDAO
{
public:

	// 根据归属人姓名查询归属人ID
	uint64_t selectUserIdByName(string user_name);

	// 将导入的客户信息插入客户表
	uint64_t insert(const CustomerDO& iObj);

};
#endif // !_EXPORTCUSTOMER_DAO_