#include "ApiHelper.h"
#include "domain/dto/SmsDTO.h"
#include "domain/vo/SmsVO.h"
#include "Macros.h" // Include the Macros header file

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SmsController : public oatpp::web::server::api::ApiController {
public:
    API_ACCESS_DECLARE(SmsController)
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contract.controller.SmsController"), execSendSms, SmsJsonVO::Wrapper);
    API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-contract/sms", execSendSms, BODY_DTO(SmsDTO::Wrapper, smsDto), execSendSms(smsDto));
    
private:
    SmsDTO::Wrapper execSendSms(const SmsDTO::Wrapper& smsDto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen