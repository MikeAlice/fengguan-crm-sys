#include "stdafx.h"
#include "Out_boundDAO.h"


namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：out_id！
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

// 确认出库（修改出库状态） 负责人：千亿
uint64_t Out_boundDAO::update(const Out_boundDO& uObj)
{
	stringstream sql;
	sql << "UPDATE stock_out SET status=1, out_user_id=";
	sql << uObj.getOut_user_id();
	sql << u8", out_time=NOW(), out_type='销售出库'"
		"WHERE out_id =";
	sql << uObj.getOut_id();
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeUpdate(sqlStr);
}

// 删除出库单（通过出库单ID删除数据） 负责人：千亿
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
