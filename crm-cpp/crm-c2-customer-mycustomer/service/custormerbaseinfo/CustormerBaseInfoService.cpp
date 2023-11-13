#include "stdafx.h"
#include "CustormerBaseInfoService.h"

CustormerDTO::Wrapper CustormerBaseInfoService::getCustromerBaseInfo()
{
    auto custromer = CustormerDTO::createShared();
    CustormerBaseInfoDAO dao;
    
    custromer->linkman = dao.VisibleResult()[0] == 0 ? "" : "linkman";
    custromer->source = dao.VisibleResult()[1] == 0 ? "" : "source";
    custromer->grade = dao.VisibleResult()[2] == 0 ? "" : "grade";
    custromer->industry = dao.VisibleResult()[3] == 0 ? "" : "industry";
    custromer->mobile = dao.VisibleResult()[4] == 0 ? "" : "mobile";
    custromer->tel = dao.VisibleResult()[5] == 0 ? "" : "tel";
    custromer->address = dao.VisibleResult()[6] == 0 ? "" : "address";
    custromer->intro = dao.VisibleResult()[7] == 0 ? "" : "intro";
    custromer->needs = dao.VisibleResult()[8] == 0 ? "" : "needs";
    return custromer;
}
