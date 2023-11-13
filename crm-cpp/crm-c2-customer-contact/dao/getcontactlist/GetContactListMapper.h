#pragma once
/*
* ������: �Ͼ�
*/
#ifndef _GETCONTACTLIST_MAPPER_
#define _GETCONTACTLIST_MAPPER_

#include "Mapper.h"
#include "domain/do/contact/ListContactDO.h"

/**
 * ��ȡ��ϵ�˷�ҳ�б�ƥ��ӳ��
 */
class GetContactListMapper : public Mapper<ListContactDO>
{
public:
	ListContactDO mapper(ResultSet* resultSet) const override
	{
		ListContactDO data;
		data.setLinkman_Id(resultSet->getInt(1));
		data.setCustomer_Name(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setGender(resultSet->getInt(4));
		data.setPostion(resultSet->getString(5));
		data.setTel(resultSet->getString(6));
		data.setMobile(resultSet->getString(7));
		data.setQicq(resultSet->getString(8));
		return data;
	}
};

#endif // !_GETCONTACTLIST_MAPPER_