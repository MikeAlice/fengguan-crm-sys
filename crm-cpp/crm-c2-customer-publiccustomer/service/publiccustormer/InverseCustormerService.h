//2023��10��27��
//��Ƥ�����
//��ȡ�ͻ���service
#pragma once
#ifndef _INVERSE_CUSTORMER_
#include "dao/inversecustormer/InverseCustormerDAO.h"
#include "ApiHelper.h"
class InverseCustormerService
{
public:
	bool inverseCustormer(uint64_t custormerId, uint64_t linkManID);
};



#endif // !_INVERSE_CUSTORMER_