#pragma once
#ifndef _FININVOICERECE_SERVICE_
#define _FININVOICERECE_SERVICE_

#include "../../domain/dto/FinInvoiceReceDTO.h"

class FinInvoiceReceService {
public:
	uint64_t saveData(const FinInvoiceReceDTO::Wrapper& dto);

};

#endif