#pragma once

#ifndef _AWAITCUSTOMERS_VO_
#define _AWAITCUSTOMERS_VO_
#include "../../GlobalInclude.h"
#include "../../dto/await/awaitpayments.h"
// ������Ӧ���ͻ��˵�Json����
#include OATPP_CODEGEN_BEGIN(DTO)
class FINDAWAPAYJsonVO : public JsonVO<FINDAWAPAYDTO::Wrapper> {
	DTO_INIT(FINDAWAPAYJsonVO, JsonVO<FINDAWAPAYDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FINDAWAPAYPAGEJsonVO : public JsonVO<FINDAWAPAYPageDTO::Wrapper> {
	DTO_INIT(FINDAWAPAYPAGEJsonVO, JsonVO<FINDAWAPAYPageDTO::Wrapper>);
};

// ������Ӧ���ͻ��˵�Json����
class FINDAWACUSTJsonVO : public JsonVO<FINDAWACUSTDTO::Wrapper> {
	DTO_INIT(FINDAWACUSTJsonVO, JsonVO<FINDAWACUSTDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FINDAWACUSTPAYPAGEJsonVO : public JsonVO<FINDAWACUSTDTOPageDTO::Wrapper> {
	DTO_INIT(FINDAWACUSTPAYPAGEJsonVO, JsonVO<FINDAWACUSTDTOPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif