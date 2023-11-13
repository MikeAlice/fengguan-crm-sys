#include "stdafx.h"
#include "RemoveCapitalRecordService.h"
#include "dao/fincapitalrecord/removecapitalrecord/RemoveCapitalRecordDAO.h"

bool RemoveCapitalRecordService::removeData(uint64_t id)
{
	RemoveCapitalRecordDAO dao;
	return dao.deleteById(id);
}

