#include "stdafx.h"
#include "InverseCustormerService.h"

bool InverseCustormerService::inverseCustormer(uint64_t custormerId, uint64_t linkManID)
{
	InverseCustormerDAO dao;
	
	return dao.InverseCustormerById(custormerId, linkManID);;
}
