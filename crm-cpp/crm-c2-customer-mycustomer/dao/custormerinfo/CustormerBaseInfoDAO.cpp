#include "stdafx.h"
#include "CustormerBaseInfoDAO.h"

//sqlSession无法输入中文，所以只能写死
vector<int> CustormerBaseInfoDAO::VisibleResult()
{
	vector<int> result;

	string sql1 = "SELECT visible FROM cst_field_ext LIMIT 1";
	result.push_back(sqlSession->executeQueryNumerical(sql1));
	
	string sql2 = "SELECT visible FROM cst_field_ext LIMIT 1,2";
	result.push_back(sqlSession->executeQueryNumerical(sql2));

	string sql3 = "SELECT visible FROM cst_field_ext LIMIT 2,3";
	result.push_back(sqlSession->executeQueryNumerical(sql3));

	string sql4 = "SELECT visible FROM cst_field_ext LIMIT 3,4";
	result.push_back(sqlSession->executeQueryNumerical(sql4));

	string sql5 = "SELECT visible FROM cst_field_ext LIMIT 4,5";
	result.push_back(sqlSession->executeQueryNumerical(sql5));

	string sql6 = "SELECT visible FROM cst_field_ext LIMIT 5,6";
	result.push_back(sqlSession->executeQueryNumerical(sql6));

	string sql7 = "SELECT visible FROM cst_field_ext LIMIT 6,7";
	result.push_back(sqlSession->executeQueryNumerical(sql7));

	string sql8 = "SELECT visible FROM cst_field_ext LIMIT 7,8";
	result.push_back(sqlSession->executeQueryNumerical(sql8));

	string sql9 = "SELECT visible FROM cst_field_ext LIMIT 8,9";
	result.push_back(sqlSession->executeQueryNumerical(sql9));

	return result;
}

