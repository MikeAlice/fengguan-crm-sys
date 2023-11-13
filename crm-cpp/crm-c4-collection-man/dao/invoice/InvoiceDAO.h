#pragma once
#ifndef _INVOICE_DAO_
#define _INVOICE_DAO_
#include "BaseDAO.h"
//#include "../../domain/do/invoice/InvoiceDO.h"
#include "domain/do/invoice/InvoiceDo.h"
#include "domain/query/invoice/InvoiceQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class InvoiceDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const InvoiceQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<InvoiceDO> selectWithPage(const InvoiceQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<InvoiceDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const InvoiceDO& iObj);
};
#endif 