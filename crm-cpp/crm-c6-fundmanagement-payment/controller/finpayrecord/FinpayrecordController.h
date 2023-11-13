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
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_pay_record.delete.summary"));	
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
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