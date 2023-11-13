#pragma once
#ifndef EXPENDITURESMAPPER_H__
#define EXPENDITURESMAPPER_H__

#include "Mapper.h"
#include "../../domain/do/other_income_statement/Other_income_statementDO.h"


/*
	 ’æ›◊÷∂Œ∆•≈‰”≥…‰
*/
class Other_income_statementMapper : public Mapper<Other_income_statementDO>
{
public:
	Other_income_statementDO mapper(ResultSet* resultSet) const override {
		Other_income_statementDO data;
		data.setRecordId(resultSet->getInt(1));
		data.setTypeId(resultSet->getString(2));
		data.setMoney(resultSet->getInt(3));
		data.setBankId(resultSet->getString(4));
		data.setHappenDate(resultSet->getString(5));
		data.setCreateUser(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setIntro(resultSet->getString(8));
		return data;
	}
};
//record_id,type_id,money,bank_id,happen_date,create_user_id,create_time,intro
#endif // EXPENDITURESMAPPER_H__

