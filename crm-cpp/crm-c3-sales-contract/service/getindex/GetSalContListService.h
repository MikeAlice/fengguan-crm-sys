#ifndef _GETSALCONTLIST_SERVICE_H_
#define _GETSALCONTLIST_SERVICE_H_
#include <list>
#include "domain/vo/getindex/GetSalContListVO.h"
#include "domain/query/getindex/GetSalContListQuery.h"
#include "domain/dto/getindex/GetSalContListDTO.h"
#include "dao/getindex/GetSalContListDAO.h"
#include "domain/do/SalesContract/sal_contractDO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetSalContListService
{
public:
	// 分页查询所有数据
	GetSalContListDTO::Wrapper getTitle(const GetSalContListQuery::Wrapper& query);

};

#endif // !_GETSALCONTLIST_SERVICE_H_