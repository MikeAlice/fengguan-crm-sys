#pragma once

#ifndef _EXPENSETYPEMAPPER_
#define _EXPENSETYPEMAPPER_

#include "Mapper.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ExpenseTypeMapper : public Mapper<ExpenseTypeDO>
{
public:
	ExpenseTypeDO mapper(ResultSet* resultSet) const override
	{
		ExpenseTypeDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSort(resultSet->getInt(3));
		data.setParentID(resultSet->getUInt64(4));
		data.setVisible(resultSet->getInt(5));
		data.setIntro(resultSet->getString(6));
		
		return data;
	}
};
class ExpenseMapper : public Mapper<ExpenseDO>
{
public:
	ExpenseDO mapper(ResultSet* resultSet) const override
	{
		ExpenseDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setParentid(resultSet->getUInt64(3));
		data.setSort(resultSet->getUInt64(4));
		data.setVisible(resultSet->getUInt64(5));
		data.setIntro(resultSet->getString(6));
		return data;
	}
};
#endif // !_EXPENSETYPEMAPPER_