#pragma once
#ifndef _PAYRECORDS_SERVICE_
#define _PAYRECORDS_SERVICE_

#include <list>
#include "domain/vo/payrecords/PayrecordsVO.h"
#include "domain/dto/payrecords/PayrecordsDTO.h"
#include "domain/query/payrecords/PayrecordsQuery.h"


class PayrecordsService
{
public:
	// 分页查询所有付款记录信息(分页)
	PayrecordsPageDTO::Wrapper listAll(const PayrecordsQuery::Wrapper& query);

};

#endif // !_PAYRECORDSSERVICE_H_