#include "stdafx.h"
#include "sstream"
#include "RemoveCapitalRecordDAO.h"

int RemoveCapitalRecordDAO::deleteById(uint64_t id)
{
	stringstream sql1;
    sql1 << "DELETE FROM `fin_flow_record` "
        "WHERE `create_time` IN("
        "SELECT `create_time` "
        "FROM `fin_capital_record` "
        "WHERE `record_id` = ?"
        ") "
        "AND `create_user_id` IN( "
        "SELECT `create_user_id` "
        "FROM `fin_capital_record` "
        "WHERE `record_id` = ?"
        ");";
	std::string sqlStr = sql1.str();
	sqlSession->executeUpdate(sqlStr, "%ull%ull", id, id);
    std::string sql2 = "DELETE FROM `fin_capital_record` WHERE record_id =?";
    return sqlSession->executeUpdate(sql2, "%ull", id);
}