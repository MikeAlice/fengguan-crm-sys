#pragma once
/*
* 地灵殿
*/
#ifndef SMSDTO_H__
#define  SMSDTO_H__
#include "../../GlobalInclude.h"
#include"SmsEmailDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 发短信对象
 */
class SmsDTO : public SmsEmailDTO
{
public:
	DTO_INIT(SmsDTO, SmsEmailDTO);
	//联系电话
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("smsemail.field.mobile");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // SMSDTO_H__