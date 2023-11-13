#ifndef _GETSALCONTLIST_MAPPER_H_
#define _GETSALCONTLIST_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/SalesContract/sal_contractDO.h"

/**
 * ���ۻ�����ֶ�ƥ��ӳ��
 */
class GetSalContListMapper : public Mapper<SalesContractDO>
{
public:
	SalesContractDO mapper(ResultSet* resultSet) const override
	{
		SalesContractDO data;
		data.setTitle(resultSet->getString(1));
		data.setContract_id(resultSet->getInt(2));
		return data;
	}
};

#endif // !_GETSALCONTLIST_MAPPER_H_
