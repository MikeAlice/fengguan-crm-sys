#pragma once
#ifndef _INVOICE_MAPPER_
#define _INVOICE_MAPPER_

#include "Mapper.h"
//#include "../../domain/do/invoice/InvoiceDO.h"
#include "domain/do/invoice/InvoiceDo.h"
/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class InvoiceMapper : public Mapper<InvoiceDO>
{
public:
	InvoiceDO mapper(ResultSet* resultSet) const override
	{
		InvoiceDO data;
		data.setContract_name(resultSet->getString(1));
		data.setCustomer_name(resultSet->getString(2));
		data.setMoney(resultSet->getUInt64(3));
		data.setPay_date(resultSet->getString(4));
		data.setStages(resultSet->getUInt64(5));
		data.setInvoice_no(resultSet->getString(6));
		data.setName(resultSet->getString(7));
		data.setIntro(resultSet->getString(8));
		data.setCreate_user_id(resultSet->getUInt64(9));
		return data;
	}
};

#endif