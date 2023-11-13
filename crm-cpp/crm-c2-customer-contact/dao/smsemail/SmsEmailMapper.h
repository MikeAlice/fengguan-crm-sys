#ifndef _SMSEMAIL_MAPPER_
#define _SMSEMAIL_MAPPER_

#include "Mapper.h"
#include"domain/do/smsemail/EmailDO.h"
#include"domain/do/smsemail/SmsDO.h"

/**
 * 邮件字段匹配映射
 */
class EmailMapper : public Mapper<EmailDO>
{
public:
	EmailDO mapper(ResultSet* resultSet) const override
	{
		EmailDO data;
		data.setName(resultSet->getString(1));
		data.setEmail(resultSet->getString(2));
		return data;
	}
};
//联系电话
class SmsMapper : public Mapper<SmsDO>
{
public:
	SmsDO mapper(ResultSet* resultSet) const override
	{
		SmsDO data;
		data.setName(resultSet->getString(1));
		data.setMobile(resultSet->getString(2));
		return data;
	}
};
#endif // !_SMSEMAIL_MAPPER_