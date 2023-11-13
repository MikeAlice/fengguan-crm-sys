#pragma once

#ifndef _SELECTSUPLINKMAN_DAO_
#define _SELECTSUPLINKMAN_DAO_

#include "BaseDAO.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "domain/query/supplierLinkman/LinkmanNameQuery.h"


/**
 * ʾ�������ݿ����ʵ��
 */
class SelectSupLinkmanNameDAO : public BaseDAO
{
public:
	//�ؼ�������
	list<SupplierLinkmanDO> selectSupplierName(const LinkmanNameQuery::Wrapper& query);
	
};
#endif // !_SAMPLE_DAO_
