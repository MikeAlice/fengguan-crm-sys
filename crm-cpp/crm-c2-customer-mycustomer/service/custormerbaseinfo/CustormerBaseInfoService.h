#pragma once
#ifndef _CUSTORMERBASEINFO_SERVICE_
#define _CUSTORMERBASEINFO_SERVICE_
#include "domain/dto/custormer/CustormerDTO.h"
#include "dao/custormerinfo/CustormerBaseInfoDAO.h"
class CustormerBaseInfoService
{
public:
	CustormerDTO::Wrapper getCustromerBaseInfo();
};
#endif // !_CUSTORMERBASEINFO_SERVICE_
