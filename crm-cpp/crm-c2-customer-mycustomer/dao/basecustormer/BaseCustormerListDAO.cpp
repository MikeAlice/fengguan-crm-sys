#include "stdafx.h"
#include "BaseCustormerListDAO.h"

bool BaseCustormerDAO::deleteByCustormerId(uint64_t id)
{
    string sql = "DELETE FROM `cst_customer` WHERE `customer_id`=?";
    int r = sqlSession->executeUpdate(sql, "%ull", id);

    return r == 0 ? false : true;
}

bool BaseCustormerDAO::hightseaByCustormerId(uint64_t id)
{
    string sql = "UPDATE `cst_customer` SET `owner_user_id` = 0 WHERE `customer_id`=?";
    int r = sqlSession->executeUpdate(sql, "%ull", id);

    return r == 0 ? false : true;
}
