#pragma once
#ifndef _INVOICE_SERVICE_
#define _INVOICE_SERVICE_
#include <list>
#include "domain/vo/invoice/InvoiceVO.h"
#include "domain/query/invoice/InvoiceQuery.h"
#include "domain/dto/invoice/InvoiceDTO.h"
#include "domain/dto/invoice/InvoiceAddDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class InvoiceService
{
public:
	// 分页查询所有数据
	InvoicePageDTO::Wrapper listAll(const InvoiceQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const InvoiceAddDTO::Wrapper& dto,uint64_t id);
};

#endif 

