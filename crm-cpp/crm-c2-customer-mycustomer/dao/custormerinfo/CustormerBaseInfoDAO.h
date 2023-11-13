#pragma once
#ifndef _CUSTORMER_BASE_INFO_DAO_
#define _CUSTORMER_BASE_INFO_DAO_
#include "BaseDAO.h"
#include "domain/do/custormerinfo/CustormerBaseInfoDO.h"
class CustormerBaseInfoDAO : public BaseDAO
{
public:
	vector<int> VisibleResult();
};

#endif // !_CUSTORMER_BASE_INFO_DAO_

