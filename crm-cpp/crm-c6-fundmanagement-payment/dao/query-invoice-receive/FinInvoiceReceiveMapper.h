#pragma once
#ifndef _FININVOICERECEIVEMAPPER_H_
#define _FININVOICERECEIVEMAPPER_H_

#include "Mapper.h"
#include "domain/do/query-invoice-receive/FinInvoiceReceiveDO.h"

class FinInvoiceReceiveMapper : public Mapper<FinInvoiceReceiveDO>
{
public:
	FinInvoiceReceiveDO mapper(ResultSet* resultSet) const override
	{
		FinInvoiceReceiveDO data;
		data.setRecordId(resultSet->getUInt64(1));
		data.setSupplierName(resultSet->getString(2));
		data.setContractName(resultSet->getString(3));
		data.setName(resultSet->getString(4));
		data.setInvoiceNo(resultSet->getUInt64(5));
		data.setMoney(resultSet->getUInt64(6));
		data.setReceDate(resultSet->getString(7));
		data.setStages(resultSet->getUInt64(8));
		data.setCreateUser(resultSet->getString(9));
		data.setIntro(resultSet->getString(10));
		return data;
	}
};

#endif // !_FININVOICERECEIVEMAPPER_H_