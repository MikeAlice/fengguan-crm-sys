#include "stdafx.h"
#include "domain/dto/finpayrecord/FinpayrecordDTO.h"
#include "service/finpayrecord/FinpayrecordService.h"
#include "dao/finpayrecord/FinpayrecordDAO.h"


uint64_t FinpayrecordService::removeData(const oatpp::List<DelFinpayrecordDTO::Wrapper>& dto)
{
	FinpayrecordDAO dao;
	return dao.removeData(dto);
}