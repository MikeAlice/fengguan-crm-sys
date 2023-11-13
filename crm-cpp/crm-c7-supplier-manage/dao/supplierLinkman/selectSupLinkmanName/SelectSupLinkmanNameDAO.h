#pragma once

#ifndef _SELECTSUPLINKMAN_DAO_
#define _SELECTSUPLINKMAN_DAO_

#include "BaseDAO.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "domain/query/supplierLinkman/LinkmanNameQuery.h"


/**
 * 示例表数据库操作实现
 */
class SelectSupLinkmanNameDAO : public BaseDAO
{
public:
	//关键字搜索
	list<SupplierLinkmanDO> selectSupplierName(const LinkmanNameQuery::Wrapper& query);
	
};
#endif // !_SAMPLE_DAO_
