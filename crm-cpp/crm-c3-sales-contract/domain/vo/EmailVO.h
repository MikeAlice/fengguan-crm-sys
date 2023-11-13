#pragma once
#include "domain/GlobalInclude.h"
#include "domain/dto/EmailDTO.h"
#ifndef _Email_VO_
#define _Email_VO_

#include OATPP_CODEGEN_BEGIN(DTO)

class EmailJsonVO : public JsonVO<EmailDTO::Wrapper> {
    DTO_INIT(EmailJsonVO, JsonVO<EmailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif