#include "stdafx.h"
#include "GetCustormerInfoController.h"
#include "service/custormerbaseinfo/CustormerBaseInfoService.h"
CustomerJsonVO::Wrapper GetCustormerInfoController::execQueryCustormerInfo()
{
    auto vo = CustomerJsonVO::createShared();
    CustormerBaseInfoService service;
    auto dto = service.getCustromerBaseInfo();
    vo->success(dto);
    return vo;
}
