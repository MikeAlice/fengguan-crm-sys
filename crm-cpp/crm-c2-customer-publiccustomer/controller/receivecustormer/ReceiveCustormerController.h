//2023年10月22日
//作者：狗皮电耗子
//内容：领取客户
#pragma once
#ifndef _RECEIVE_CUSTORMER_
#define _RECEIVE_CUSTORMER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/BaseCustomer/BaseCustomerDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ReceiveCustormerController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ReceiveCustormerController);
public:
	ENDPOINT_INFO(receivecustormer) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mycustormer.recevicecustormer.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义领取客户接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/crm-c2-customer-publiccustomer/receive-custormer", receivecustormer, BODY_DTO(List<UInt64>, idArray), execReceiveCustormer(idArray, authObject->getPayload()));

private:
	Uint64JsonVO::Wrapper execReceiveCustormer(const List<UInt64>& idArray, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_RECEIVE_CUSTORMER_;
