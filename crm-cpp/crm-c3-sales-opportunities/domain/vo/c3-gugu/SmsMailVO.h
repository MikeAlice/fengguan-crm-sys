#pragma once
#ifndef _MailVO_H_
#define _MailVO_H_
#include"../../GlobalInclude.h"
#include"../../dto/c3-gugu/SmsMailDTO.h"
#include"stdafx.h"


#include OATPP_CODEGEN_BEGIN(DTO)

class MailVO :public JsonVO<MailDTO::Wrapper>
{
	DTO_INIT(MailVO, JsonVO<MailDTO::Wrapper>);

};

class SmsVO :public JsonVO<SmsDTO::Wrapper>
{
	DTO_INIT(SmsVO, JsonVO<SmsDTO::Wrapper>);

};


#include OATPP_CODEGEN_END(DTO)


#endif // !_MODIFYPWDDTO_H_