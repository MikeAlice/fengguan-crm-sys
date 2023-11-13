#ifndef _SMSEMAIL_DAO_
#define _SMSEMAIL_DAO_
#include "BaseDAO.h"
#include"domain/do/smsemail/EmailDO.h"
#include"domain/do/smsemail/SmsDO.h"
/**
 * 查询数据库操作实现
 */

class SmsEmailDAO : public BaseDAO
{
public:
	//查询电子邮箱
	list<EmailDO> queryEmail(const int& linkman_id);
	//查询联系手机
	list<SmsDO> queryMobile(const int& linkman_id);
};
#endif // !_SMSEMAIL_DAO_

