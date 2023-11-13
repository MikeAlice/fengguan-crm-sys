#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _IMPORTCUSTOMER_MAPPER_
#define _IMPORTCUSTOMER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/fieldext/FieldExtDO.h"

/**
 * ϵͳ�û���Ϣ���ֶ�ƥ��ӳ��
 */
class GetFieldExtMapper : public Mapper<FieldExtDO>
{
public:
	FieldExtDO mapper(ResultSet* resultSet) const override
	{
		FieldExtDO data;
		data.setVisible(resultSet->getInt(1));
		return data;
	}
};

#endif // !_EXPORTCUSTOMER_MAPPER_