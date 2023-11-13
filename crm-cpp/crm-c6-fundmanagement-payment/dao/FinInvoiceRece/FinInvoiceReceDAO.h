#pragma once
#ifndef _FININVOICERECE_DAO_
#define _FININVOICERECE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/FinInvoiceRece/FinInvoiceReceDO.h"

class FinInvoiceReceDAO :public BaseDAO {
public:
	uint64_t insert(const FinInvoiceReceDO& iObj);
};

#endif // !_FININVOICERECE_DAO_
