#ifndef _GETSALESNO_SERVICE_
#define _GETSALESNO_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/getindex/GetSalesOppoQuery.h"
#include "domain/dto/getindex/GetSalesContractNoDTO.h"
#include "dao/getindex/GetSalesNoDAO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetSalesNoService
{
public:
	// ��ѯcontract_no
	//String getNo(const UInt64& contract_id);
	GetSalesContractNoDTO::Wrapper getNo(const UInt64 contract_id);
};

#endif // !_GETSALESNO_SERVICE_