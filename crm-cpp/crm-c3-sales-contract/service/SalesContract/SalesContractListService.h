#pragma once
#include "stdafx.h"
#ifndef _SALESCONTRACTLISTSERVICE_H_
#define _SALESCONTRACTLISTSERVICE_H_
#include "domain/query/getindex/SalesContractQuery.h"
#include "domain/dto/getindex/SalesContractListDTO.h"

class querySalesContractListService
{
public:
	// ��ҳ��ѯ��������
	SalesContractListPageDTO::Wrapper listAll(const SalesContractPageQuery::Wrapper& query);
};
#endif