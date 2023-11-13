#ifndef _GETSALESNO_SERVICE_
#define _GETSALESNO_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/getindex/GetSalesOppoQuery.h"
#include "domain/dto/getindex/GetSalesContractNoDTO.h"
#include "dao/getindex/GetSalesNoDAO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetSalesNoService
{
public:
	// 查询contract_no
	//String getNo(const UInt64& contract_id);
	GetSalesContractNoDTO::Wrapper getNo(const UInt64 contract_id);
};

#endif // !_GETSALESNO_SERVICE_