#pragma once
#ifndef EXPENDITURESMAPPER_H__
#define EXPENDITURESMAPPER_H__

#include "Mapper.h"
#include "../../domain/do/expenditures/ExpendituresDO.h"


/*
	 ’æ›◊÷∂Œ∆•≈‰”≥…‰
*/
class ExpendituresMapper : public Mapper<ExpendituresDO>
{
public:
	ExpendituresDO mapper(ResultSet* resultSet) const override {
		ExpendituresDO data;
		data.setRecordId(resultSet->getInt(1));
		data.setType(resultSet->getString(2));
		data.setMoney(resultSet->getInt(3));
		data.setBank(resultSet->getString(4));
		data.setHappenDate(resultSet->getString(5));
		data.setCreateUser(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setIntro(resultSet->getString(8));
		return data;
	}
};


#endif // EXPENDITURESMAPPER_H__
