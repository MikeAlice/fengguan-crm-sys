#pragma once
#include "domain/GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class SmsDTO : public oatpp::DTO {
    DTO_INIT(SmsDTO, DTO);
    API_DTO_FIELD_DEFAULT(List<String>, phoneNumber, ZH_WORDS_GETTER("sendSms.phoneNumber"));
    API_DTO_FIELD_DEFAULT(String, message, ZH_WORDS_GETTER("sendSms.message"));
};

#include OATPP_CODEGEN_END(DTO)