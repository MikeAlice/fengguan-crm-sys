#include "stdafx.h"
#include "FinpayrecordDAO.h"

namespace sqlHelpers {

	//lhm copy from yunyin

	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->record_id.getValue({});
		}
		sql << ")";
	}
}

uint64_t FinpayrecordDAO::removeData(const oatpp::List<DelFinpayrecordDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "DELETE FROM fin_pay_record  "
		"WHERE record_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeUpdate(sqlStr);
}
