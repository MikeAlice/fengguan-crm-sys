#include "stdafx.h"
#include <sstream>
#include "SmsEmailDAO.h"
#include"SmsEmailMapper.h"

list<EmailDO> SmsEmailDAO::queryEmail(const int& customer_no)
{
    string sql = "SELECT `name`,`email` FROM `cst_linkman` WHERE `customer_id` =?";
    EmailMapper mapper;
    return sqlSession->executeQuery<EmailDO, EmailMapper>(sql,mapper,"%ui", customer_no);
}

list<SmsDO> SmsEmailDAO::queryMobile(const int& customer_no)
{
    string sql = "SELECT `name`,`mobile` FROM `cst_linkman` WHERE `customer_id` =?";
    SmsMapper mapper;
    return sqlSession->executeQuery<SmsDO, SmsMapper>(sql, mapper, "%ui", customer_no);
}
