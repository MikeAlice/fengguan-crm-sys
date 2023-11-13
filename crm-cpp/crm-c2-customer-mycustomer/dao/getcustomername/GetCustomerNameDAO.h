#ifndef _GETCUSTOMERNAME_DAO_
#define _GETCUSTOMERNAME_DAO_
#include "BaseDAO.h"
#include "../../domain/do/getcustomername/GetCustomerNameDO.h"
#include "../../domain/query/getcustomername/GetCustomerNameQuery.h"


/**
 * cst_customer表数据库操作实现
 */
class GetCustomerNameDAO : public BaseDAO
{
public:
	// 通过客户id查询数据
	list<GetCustomerNameDO> selectByName(const GetCustomerNameQuery::Wrapper& query);
};
#endif // !_GETCUSTOMERNAME_DAO_
