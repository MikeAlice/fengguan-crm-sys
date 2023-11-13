#pragma once
#ifndef _BANKACCOUNT_MAPPER_
#define _BANKACCOUNT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/bankaccount/BankAccountDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class BankAccountMapper : public Mapper<BankAccountDO>
{
public:
	BankAccountDO mapper(ResultSet* resultSet) const override
	{
		BankAccountDO data;
		data.setBank_id(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setCard(resultSet->getUInt64(3));
		data.setAddress(resultSet->getString(4));
		data.setHolders(resultSet->getString(5));
		data.setSort(resultSet->getInt64(6));
		data.setVisible(resultSet->getInt64(7));
			
		return data;
	}
};
class BankAccountListMapper : public Mapper<BankAccountListDO>
{
public:
	BankAccountListDO mapper(ResultSet* resultSet) const override
	{
		BankAccountListDO data;
		data.setBank_id(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setCard(resultSet->getUInt64(3));
	

		return data;
	}
};
#endif // !_BANKACCOUNT_MAPPER_