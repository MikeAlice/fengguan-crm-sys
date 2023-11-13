#pragma once
/*
* @Auther: Glasscat
* @Date: 2023/10/25
*/

#ifndef _SENDINGFILEVO_H
#define _SENDINGFILEVO_H

#include "../../GlobalInclude.h"
#include "../../dto/contractindex/SendingFileDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendingFileVO : public JsonVO<SendingFileDTO::Wrapper>
{
	DTO_INIT(SendingFileVO, JsonVO<SendingFileDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SENDINGFILEVO_H
