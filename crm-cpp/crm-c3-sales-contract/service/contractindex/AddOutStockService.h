#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>

#include"domain/dto/contractindex/OutStockDTO.h"
#include"../lib-oatpp/include/domain/vo/BaseJsonVO.h"

class AddOutStockService
{
public:
				
	Int64JsonVO::Wrapper AddOutStock(const OutStockDTO::Wrapper& qdto, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_


