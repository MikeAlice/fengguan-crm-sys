#pragma once
/*
* 地灵殿
*/
#ifndef SMSEMAILDTO_H__
#define  SMSEMAILDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 发短信和发邮件基类对象
 */
class SmsEmailDTO : public oatpp::DTO
{
public:
	DTO_INIT(SmsEmailDTO, DTO);
	//发送内容
	DTO_FIELD(String, mess);
	DTO_FIELD_INFO(mess) {
		info->description = ZH_WORDS_GETTER("smsemail.field.content");
	}
	//发送类型
	DTO_FIELD(UInt64, mess_type);
	DTO_FIELD_INFO(mess_type) {
		info->description = ZH_WORDS_GETTER("smsemail.field.ctype");
	}
	//合同名称
	DTO_FIELD(String, contrast_name);
	DTO_FIELD_INFO(contrast_name) {
		info->description = ZH_WORDS_GETTER("smsemail.field.contrast_name");
	}
	//客户名称
	DTO_FIELD(String, recv_name);
	DTO_FIELD_INFO(recv_name) {
		info->description = ZH_WORDS_GETTER("smsemail.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // SMSEMAILDTO_H__