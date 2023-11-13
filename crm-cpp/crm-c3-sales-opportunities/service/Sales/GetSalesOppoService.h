#ifndef _GETSALESOPPO_SERVICE_
#define _GETSALESOPPO_SERVICE_
#include <list>
#include "domain/vo/getindex/GetSalesOppoVo.h"
#include "domain/query/getindex/GetSalesOppoQuery.h"
#include "domain/dto/getindex/GetSalesOppoDTO.h"
#include "dao/Sales/GetSalesOppoDAO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetSalesOppoService
{
public:
	// 分页查询所有数据
	GetSalesOppoNameDTO::Wrapper getName(const GetSalesOppoQuery::Wrapper& query);
	//GetSalesOppoNameDTO::Wrapper getName(const uint32_t& customer_id);

};

#endif // !_GETSALESOPPO_SERVICE_