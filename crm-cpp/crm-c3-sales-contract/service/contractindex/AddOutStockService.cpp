#include "stdafx.h"
#include "AddOutStockService.h"
#include"domain/query/contractindex/OutStockQuery.h"
#include"domain/dto/contractindex/OutStockDTO.h"
#include"service/contractindex/AddOutStockApiClient.h"
#include"controller/ApiDeclarativeServicesHelper.h"
#include"../lib-oatpp/include/domain/vo/BaseJsonVO.h"

Int64JsonVO::Wrapper AddOutStockService::AddOutStock(const OutStockDTO::Wrapper& qdto, const PayloadDTO& payload)
{
    API_CLIENT_CREATE(ac, om, AddOutStockApiClient, "addOutStock-api");
    // 构建凭证
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
    Int64JsonVO::Wrapper jvo;
    jvo = ac->AddOutStock(qdto)->readBodyToDto<Int64JsonVO::Wrapper>(om);
 
    return jvo;
}
