#ifndef _GETCUSTOMER_DAO_
#define _GETCUSTOMER_DAO_
#include "BaseDAO.h"
#include "domain/do/getcustomer/GetCustomerDO.h"
#include "domain/query/getcustomer/GetCustomerQuery.h"

/**
 * cst_customer表数据库操作实现
 */
class GetCustomerDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GetCustomerQuery::Wrapper& query);
	// 分页查询数据
	list<GetCustomerDO> selectWithPage(const GetCustomerQuery::Wrapper& query);
};
#endif // !_GETCUSTOMER_DAO_

