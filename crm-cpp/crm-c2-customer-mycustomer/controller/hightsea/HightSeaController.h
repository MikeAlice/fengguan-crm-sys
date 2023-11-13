//时间：2023年10月19日
//作者：狗皮电耗子
//内容：投入公海接口
#pragma once
#ifndef _HIGHTSEACONTROLLER_
#define _HIGHTSEACONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include <domain/dto/basecustomer/BaseCustomerDTO.h>

#include OATPP_CODEGEN_BEGIN(ApiController) 

class HightSeaController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(HightSeaController);
public:
	ENDPOINT_INFO(investhightsea) {
		// 定义投入公海接口描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("mycustormer.hightsea.summary"), Uint64JsonVO::Wrapper);
	}
	// 定义投入公海接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/customer-mycustomer/inves-hightsea", investhightsea, BODY_DTO(List<UInt64>, idArray), execInvestHightSea(idArray));

private:
	Uint64JsonVO::Wrapper execInvestHightSea(const List<UInt64> idArray);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_HIGHTSEACONTROLLER_
