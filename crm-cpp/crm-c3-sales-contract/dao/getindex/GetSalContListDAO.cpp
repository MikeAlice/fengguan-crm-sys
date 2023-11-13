#include "stdafx.h"
#include "GetSalContListDAO.h"
#include "GetSalContListMapper.h"
#include <sstream>


////定义条件解析宏，减少重复代码
//#define SAMPLE_TERAM_PARSE(query, sql) \
//SqlParams params; \
//sql<<" WHERE 1=1"; \
//if (query->title) { \
//	sql << " AND title LIKE CONCAT('%',?,'%')"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->title.getValue("")); \
//} 

list<SalesContractDO> GetSalContListDAO::selectByTitle(const GetSalContListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT title,contract_id FROM sal_contract";
	//SAMPLE_TERAM_PARSE(query, sql);
	SqlParams params;
		sql << " WHERE 1=1";
		if (query->title) {
				sql << " AND title LIKE CONCAT('%',?,'%')"; 
				SQLPARAMS_PUSH(params, "s", std::string, query->title.getValue("")); 
		}
		if (query->customer_id) {
			sql << " AND customer_id=?";
			SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0));
		}
	GetSalContListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SalesContractDO, GetSalContListMapper>(sqlStr, mapper, params);
    return list<SalesContractDO>();
}


