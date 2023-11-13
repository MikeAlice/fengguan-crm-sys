#pragma once
#ifndef _FINPAYRECORD_DAO_
#define _FINPAYRECORD_DAO_

#include "BaseDAO.h"
#include "domain/do/finpayrecord/FinpayrecordDO.h"
#include "domain/dto/finpayrecord/FinpayrecordDTO.h"

class FinpayrecordDAO : public BaseDAO {
public:
	uint64_t removeData(const oatpp::List<DelFinpayrecordDTO::Wrapper>& dto);
};


#endif // !_FINPAYRECORD_DAO_
