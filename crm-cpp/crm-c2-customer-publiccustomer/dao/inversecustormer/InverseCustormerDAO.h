//2023��10��23��
//��Ƥ�����
//��ȡ�ͻ���DAO
#pragma once
#ifndef _INVERSE_CUSTORMER_DAO_
#define _INVERSE_CUSTORMER_DAO_
#include "BaseDAO.h"
#include "dao/inversecustormer/InverseCustormerDAO.h"

class InverseCustormerDAO : public BaseDAO
{
public:
	bool InverseCustormerById(uint64_t id, uint64_t linkManID);
};
#endif // !_INVERSE_CUSTORMER_DAO_



