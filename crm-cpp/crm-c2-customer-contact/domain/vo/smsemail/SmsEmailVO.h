#ifndef _SMSEMAIL_VO_
#define _SMSEMAIL_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/smsemail/EmailDTO.h"
#include "domain/dto/smsemail/SmsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 发短信JsonVO，用于响应给客户端的Json对象
 */
class SmsJsonVO : public JsonVO<SmsDTO::Wrapper> {
	DTO_INIT(SmsJsonVO, JsonVO<SmsDTO::Wrapper>);
};

/**
 * 发邮件JsonVO，用于响应给客户端的Json对象
 */
class EmailJsonVO : public JsonVO<EmailDTO::Wrapper> {
	DTO_INIT(EmailJsonVO, JsonVO<EmailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SMSEMAIL_VO_ 
