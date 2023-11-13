#pragma once
#ifndef _INVOICE_DAO_
#define _INVOICE_DAO_
#include "BaseDAO.h"
//#include "../../domain/do/invoice/InvoiceDO.h"
#include "domain/do/invoice/InvoiceDo.h"
#include "domain/query/invoice/InvoiceQuery.h"

/**
 * 示例表数据库操作实现
 */
class InvoiceDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const InvoiceQuery::Wrapper& query);
	// 分页查询数据
	list<InvoiceDO> selectWithPage(const InvoiceQuery::Wrapper& query);
	// 通过姓名查询数据
	list<InvoiceDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const InvoiceDO& iObj);
};
#endif 