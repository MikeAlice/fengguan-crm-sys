#include "stdafx.h"
#include "Out_boundDAO.h"


namespace sqlHelpers {
	/*
	* ���������IN���()
	* ʾ������"SELECT xxx FROM xxx WHERE xxx IN "�ĺ���
	*		���(1,2,3,4)
	* ������sql��䡢dto����
	* ע�⣺out_id��
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->out_id.getValue({});
		}
		sql << ")";
	}
}

uint64_t Out_boundDAO::count(const Out_boundQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	//SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}

// ȷ�ϳ��⣨�޸ĳ���״̬�� �����ˣ�ǧ��
uint64_t Out_boundDAO::update(const Out_boundDO& uObj)
{
	stringstream sql;
	sql << "UPDATE stock_out SET status=1, out_user_id=";
	sql << uObj.getOut_user_id();
	sql << u8", out_time=NOW(), out_type='���۳���'"
		"WHERE out_id =";
	sql << uObj.getOut_id();
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeUpdate(sqlStr);
}

// ɾ�����ⵥ��ͨ�����ⵥIDɾ�����ݣ� �����ˣ�ǧ��
uint64_t Out_boundDAO::removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "DELETE FROM stock_out s_o "
		"WHERE out_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeUpdate(sqlStr);
}
