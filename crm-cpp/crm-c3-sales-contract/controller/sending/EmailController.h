#pragma once

#include "ApiHelper.h"
#include "domain/dto/EmailDTO.h"
#include "domain/vo/EmailVO.h"
#include "Macros.h" // Include the Macros header file

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class EmailController : public oatpp::web::server::api::ApiController
{
public:
    API_ACCESS_DECLARE(EmailController)
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("contract.controller.sendEmail"), sendEmail, EmailJsonVO::Wrapper);
    API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-contract/email", sendEmail, BODY_DTO(EmailDTO::Wrapper, EmailDto), sendEmail(EmailDto));
private:
    EmailDTO::Wrapper sendEmail(const EmailDTO::Wrapper& smsDto);
};

