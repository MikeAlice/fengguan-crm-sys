#ifndef _FeeIncome_MAPPER_
#define _FeeIncome_MAPPER_

#include "Mapper.h"
#include "../../domain/do/feeincome/FeeIncomeDO.h"

/**
 * 费用收入类型表字段匹配映射
 */
class FeeIncomeMapper : public Mapper<FeeIncomeDO>
{
public:
	FeeIncomeDO mapper(ResultSet* resultSet) const override
	{
		FeeIncomeDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setParentid(resultSet->getUInt64(3));
		data.setSort(resultSet->getUInt64(4));
		data.setVisible(resultSet->getUInt64(5));
		data.setIntro(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_