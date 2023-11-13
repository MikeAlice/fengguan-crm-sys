#pragma once
/*
* 负责人：老菌
*/
#ifndef _GETCONTACTFIELDEXT_DAO_
#define _GETCONTACTFIELDEXT_DAO_
#include "BaseDAO.h"
#include "dao/getcontactfieldext/GetContactFieldExtMapper.h"

/**
 * 导出客户数据表操作实现
 */
class GetContactFieldExtDAO : public BaseDAO
{
public:

	// 根据字段值查询是否启用
	uint64_t selectVisibleByName(string field_name);

};
#endif // !_GETCONTACTFIELDEXT_DAO_