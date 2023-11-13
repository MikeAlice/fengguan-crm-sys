#ifndef _GETSALCONTLIST_SERVICE_H_
#define _GETSALCONTLIST_SERVICE_H_
#include <list>
#include "domain/vo/getindex/GetSalContListVO.h"
#include "domain/query/getindex/GetSalContListQuery.h"
#include "domain/dto/getindex/GetSalContListDTO.h"
#include "dao/getindex/GetSalContListDAO.h"
#include "domain/do/SalesContract/sal_contractDO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetSalContListService
{
public:
	// ��ҳ��ѯ��������
	GetSalContListDTO::Wrapper getTitle(const GetSalContListQuery::Wrapper& query);

};

#endif // !_GETSALCONTLIST_SERVICE_H_