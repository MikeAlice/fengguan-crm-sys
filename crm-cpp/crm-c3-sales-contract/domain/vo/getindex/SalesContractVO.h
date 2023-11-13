#pragma once
/*
* @Anther: Glasscats
* @Date: 2023/10/24
*/
#ifndef __SalesContract_VO
#define __SalesContract_VO

#include "domain/GlobalInclude.h"
#include "domain/dto/getindex/SalesContractDTO.h"
#include "domain/dto/getindex/SalesContractDetailDTO.h"

#include "../../GlobalInclude.h"
#include "../../dto/getindex/SalesContractDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ۺ�ͬ�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SalesContractJsonVO : public JsonVO<SalesContractDTO::Wrapper> {
	DTO_INIT(SalesContractJsonVO, JsonVO<SalesContractDTO::Wrapper>);
};

/**
* ���ۺ�ͬ��ϸ�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class SalesContractDetailJsonVO : public JsonVO<SalesContractDetailDTO::Wrapper> {
	DTO_INIT(SalesContractDetailJsonVO, JsonVO<SalesContractDetailDTO::Wrapper>);
};

/**
 * ���ۺ�ͬ�б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SalesContractPageJsonVO : public JsonVO<SalesContractPageDTO::Wrapper> {
	DTO_INIT(SalesContractPageJsonVO, JsonVO<SalesContractPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !__SalesContract_VO
