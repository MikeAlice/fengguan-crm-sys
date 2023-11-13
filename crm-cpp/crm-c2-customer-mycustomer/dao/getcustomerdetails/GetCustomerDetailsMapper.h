#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _GETCUSTOMERDETAILS_MAPPER_
#define _GETCUSTOMERDETAILS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/customer/CustomerDO.h"

/**
 * ��ȡ�ͻ���ϸ��Ϣ�ֶ�ƥ��ӳ��
 */
class GetCustomerDetailsMapper : public Mapper<CustomerDO>
{
public:
	CustomerDO mapper(ResultSet* resultSet) const override
	{
		CustomerDO data;
		data.setName(resultSet->getString(1));
		data.setLinkman(resultSet->getString(2));
		data.setSource(resultSet->getString(3));
		data.setGrade(resultSet->getString(4));
		data.setIndustry(resultSet->getString(5));
		data.setMobile(resultSet->getString(6));
		data.setTel(resultSet->getString(7));
		data.setAddress(resultSet->getString(8));
		data.setIntro(resultSet->getString(9));
		data.setNeeds(resultSet->getString(10));
		return data;
	}
};

#endif // !_GETCUSTOMERDETAILS_MAPPER_
