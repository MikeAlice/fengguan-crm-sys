#pragma once
#ifndef _FINPAYRECORD_CONTROLLER_
#define _FINPAYRECORD_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/finpayrecord/FinpayrecordDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FinpayrecordController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(FinpayrecordController);
public:
	ENDPOINT_INFO(removeFinpayrecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_pay_record.delete.summary"));	
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/payment/pay-record/delete", removeFinpayrecord,
		BODY_DTO(List<DelFinpayrecordDTO::Wrapper>, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveFinpayrecord(dto));
	}
private:
	Uint64JsonVO::Wrapper execRemoveFinpayrecord(const List<DelFinpayrecordDTO::Wrapper>&);
};


#include OATPP_CODEGEN_END(ApiController)

#endif