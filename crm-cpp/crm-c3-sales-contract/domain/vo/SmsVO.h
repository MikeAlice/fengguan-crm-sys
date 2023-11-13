#pragma once
#include "domain/GlobalInclude.h"
#include "domain/dto/SmsDTO.h"
#ifndef _Sms_VO_
#define _Sms_VO_

#include OATPP_CODEGEN_BEGIN(DTO)

class SmsJsonVO : public JsonVO<SmsDTO::Wrapper> {
    DTO_INIT(SmsJsonVO, JsonVO<SmsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif