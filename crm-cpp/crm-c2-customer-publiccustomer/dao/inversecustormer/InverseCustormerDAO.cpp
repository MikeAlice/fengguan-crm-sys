#include "stdafx.h"
#include "InverseCustormerDAO.h"

bool InverseCustormerDAO::InverseCustormerById(uint64_t id, uint64_t linkManID)
{

    string sql = "UPDATE `cst_customer` SET `owner_user_id`=? WHERE `customer_id`=?";
    int res = sqlSession->executeUpdate(sql, "%ull%ull", linkManID, id);
    return res==0 ? false : true;
}
