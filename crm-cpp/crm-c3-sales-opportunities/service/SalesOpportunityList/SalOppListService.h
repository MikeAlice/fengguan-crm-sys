#pragma once
#include "stdafx.h"
#ifndef _SALOPPLISTSERVICE_H_
#define _SALOPPLISTSERVICE_H_
#include "domain/query/saleopport/SaleopportQuery.h"
#include "domain/dto/saleopport/SaleopportDTO.h"

class querySalOppListService
{
public:
	// ��ҳ��ѯ��������
	SaleopportPgaeDTO::Wrapper listAll(const SaleopportPageQuery::Wrapper& query);
};
#endif