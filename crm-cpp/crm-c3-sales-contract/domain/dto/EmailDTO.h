#pragma once
#include "domain/GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class EmailDTO : public oatpp::DTO {
    DTO_INIT(EmailDTO, DTO);
    API_DTO_FIELD_DEFAULT(String, subject, ZH_WORDS_GETTER("sendEmail.subject"));
    API_DTO_FIELD_DEFAULT(List<String>, emailAddress, ZH_WORDS_GETTER("sendEmail.emailAddress"));
    API_DTO_FIELD_DEFAULT(List<String>, recipient_name, ZH_WORDS_GETTER("sendEmail.recipient_name"));
    API_DTO_FIELD_DEFAULT(String, message, ZH_WORDS_GETTER("sendEmail.context"));
};

#include OATPP_CODEGEN_END(DTO)