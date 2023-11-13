#pragma once

#ifndef _ADDPAYRECORDCONTROLLER_H_
#define _ADDPAYRECORDCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/add-pay-record/AddPayRecordDTO.h"
#include <ApiHelper.h>
#include <boost/throw_exception.hpp>
#include <service/add-pay-record/AddPayRecordService.h>
//�����Ӹ����¼

#include OATPP_CODEGEN_BEGIN(ApiController)

class AddPayRecordController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(AddPayRecordController);
public: 
	ENDPOINT_INFO(addPayRecord) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addpayrecord.post.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

		info->queryParams.add<UInt64>("plan_id").description = u8"�ƻ�ID";
		info->queryParams["plan_id"].addExample("default", oatpp::UInt64(10));

		info->queryParams.add<UInt64>("contract_id").description = u8"��ͬID";
		info->queryParams["contract_id"].addExample("default", oatpp::UInt64(10));

		info->queryParams.add<UInt64>("supplier_id").description = u8"��Ӧ��ID";
		info->queryParams["supplier_id"].addExample("default", oatpp::UInt64(10));

		info->queryParams.add<UInt64>("bank_id").description = u8"����ID";
		info->queryParams["bank_id"].addExample("default", oatpp::UInt64(10));

		info->queryParams.add<UInt64>("pay_date").description = u8"��������";
		info->queryParams["pay_date"].addExample("default", oatpp:: String("2023-10-24-14-32"));

		info->queryParams.add<UInt64>("money").description = u8"Ǯ��Ŀ";
		info->queryParams["money"].addExample("default", oatpp::String("5000"));

		info->queryParams.add<UInt64>("zero_money").description = u8"����";
		info->queryParams["zero_money"].addExample("default", oatpp::String("0"));

		info->queryParams.add<UInt64>("stages").description = u8"�ڴ�";
		info->queryParams["stages"].addExample("default", oatpp::UInt64(1));

		info->queryParams.add<UInt64>("intro").description = u8"��ע";
		info->queryParams["intro"].addExample("default", oatpp::String(" "));

		info->queryParams.add<UInt64>("create_user_id").description = u8"��¼������ID";
		info->queryParams["create_user_id"].addExample("default", oatpp::UInt64(1));

	}
	ENDPOINT(API_M_POST, "/payment/payrecord", addPayRecord, BODY_DTO(AddPayRecordDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execaddPayRecord(dto));
		//Uint64JsonVO::Wrapper execaddPayRecord(const AddPayRecordDTO::Wrapper & dto);
	}


private: 
	Uint64JsonVO::Wrapper execaddPayRecord(const AddPayRecordDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif