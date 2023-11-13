#pragma once

#ifndef _UPDATEPAYPLANCONTROLLER_H_
#define _UPDATEPAYPLANCONTROLLER_H_


#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/update-pay-plan/UpdatePayPlanDTO.h"
#include <boost/throw_exception.hpp>
#include <service/update-pay-plan/UpdatePayPlanService.h>


#include OATPP_CODEGEN_BEGIN(ApiController)

class UpdatePayPlanController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(UpdatePayPlanController);
public:
	ENDPOINT_INFO(updatePayPlan) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("updatepayplan.post.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);


	}
	ENDPOINT(API_M_POST, "/payment/pay-plan/update", updatePayPlan, BODY_DTO(UpdatePayPlanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execupdatePayPlan(dto));
		//Uint64JsonVO::Wrapper execaddPayRecord(const AddPayRecordDTO::Wrapper & dto);
	}


private:
	Uint64JsonVO::Wrapper execupdatePayPlan(const UpdatePayPlanDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif