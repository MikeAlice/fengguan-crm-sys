#include "stdafx.h"
#include "BaseCustormerService.h"
#include "dao/basecustormer/BaseCustormerListDAO.h"

bool BaseCustormerService::delecteCustormer(uint64_t custormerId)
{
    BaseCustormerDAO dao;

    return dao.deleteByCustormerId(custormerId);
}

bool BaseCustormerService::hightSeaCustormer(uint64_t custormerId)
{
    BaseCustormerDAO dao;

    return dao.hightseaByCustormerId(custormerId);
}
