
#ifndef EMAILDTO_H__
#define  EMAILDTO_H__
#include "../../GlobalInclude.h"
#include"SmsEmailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 负责人：地灵殿
 * 发邮件对象
 */
class EmailDTO : public SmsEmailDTO
{
public:
	DTO_INIT(EmailDTO, SmsEmailDTO);
	//电子邮箱
	DTO_FIELD(String, mail);
	DTO_FIELD_INFO(mail) {
		info->description = ZH_WORDS_GETTER("smsemail.field.email");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // EMAILDTO_H__