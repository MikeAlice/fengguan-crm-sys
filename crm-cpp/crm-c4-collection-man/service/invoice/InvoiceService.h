#pragma once
#ifndef _INVOICE_SERVICE_
#define _INVOICE_SERVICE_
#include <list>
#include "domain/vo/invoice/InvoiceVO.h"
#include "domain/query/invoice/InvoiceQuery.h"
#include "domain/dto/invoice/InvoiceDTO.h"
#include "domain/dto/invoice/InvoiceAddDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class InvoiceService
{
public:
	// ��ҳ��ѯ��������
	InvoicePageDTO::Wrapper listAll(const InvoiceQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const InvoiceAddDTO::Wrapper& dto,uint64_t id);
};

#endif 

