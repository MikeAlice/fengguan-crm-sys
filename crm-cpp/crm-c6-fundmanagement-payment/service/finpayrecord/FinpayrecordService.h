#pragma once
#ifndef _FINPAYRECORD_SERVICE_
#define _FINPAYRECORD_SERVICE_

#include "domain/dto/finpayrecord/FinpayrecordDTO.h"

class FinpayrecordService {
public:
	uint64_t removeData(const oatpp::List<DelFinpayrecordDTO::Wrapper>& dto);
};

#endif // !_FINPAYRECORD_SERVICE_
