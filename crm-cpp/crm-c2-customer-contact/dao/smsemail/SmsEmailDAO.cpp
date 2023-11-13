#include "stdafx.h"
#include <sstream>
#include "SmsEmailDAO.h"
#include"SmsEmailMapper.h"

list<EmailDO> SmsEmailDAO::queryEmail(const int& linkman_id)
{
    string sql = "SELECT `name`,`email` FROM `cst_linkman` WHERE `linkman_id` =?";
    EmailMapper mapper;
    return sqlSession->executeQuery<EmailDO, EmailMapper>(sql,mapper,"%ui", linkman_id);
}

list<SmsDO> SmsEmailDAO::queryMobile(const int& linkman_id)
{
    string sql = "SELECT `name`,`mobile` FROM `cst_linkman` WHERE `linkman_id` =?";
    SmsMapper mapper;
    return sqlSession->executeQuery<SmsDO, SmsMapper>(sql, mapper, "%ui", linkman_id);
}
