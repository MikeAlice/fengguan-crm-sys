#pragma once
#ifndef _BASECUSTORMER_SERVICE_
#define _BASECUSTORMER_SERVICE_

#include "domain/dto/basecustomer/BaseCustormerListDTO.h"


class BaseCustormerService
{
public:
	bool delecteCustormer(uint64_t custormerId);
	bool hightSeaCustormer(uint64_t custormerId);
};

#endif // !_BASECUSTORMER_SERVICE_