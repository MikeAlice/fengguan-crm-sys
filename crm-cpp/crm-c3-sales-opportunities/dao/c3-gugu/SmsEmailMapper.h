#pragma once
#ifndef _SMSEMAIL_MAPPER_
#define _SMSEMAIL_MAPPER_

#include "Mapper.h"
#include"domain/do/c3-gugu/SmsMailDO.h"



class EmailMapper : public Mapper<EmailDO>
{
public:
	EmailDO mapper(ResultSet* resultSet) const override
	{
		EmailDO data;
		data.setRecv_Name(resultSet->getString(1));
		data.setChance_Name(resultSet->getString(3));
		data.setMail(resultSet->getString(2));
		return data;
	}
};

class SmsMapper : public Mapper<SmsDO>
{
public:
	SmsDO mapper(ResultSet* resultSet) const override
	{
		SmsDO data;
		data.setRecv_Name(resultSet->getString(1));
		data.setChance_Name(resultSet->getString(3));
		data.setPhone(resultSet->getString(2));
		return data;
	}
};
#endif // !_SMSEMAIL_MAPPER_