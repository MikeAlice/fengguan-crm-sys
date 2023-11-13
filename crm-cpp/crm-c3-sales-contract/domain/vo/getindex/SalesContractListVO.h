#pragma once

#ifndef _SALESCONTRACTLISTVO_H_
#define _SALESCONTRACTLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/getindex/SalesContractListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//����һ�����ۺ�ͬ��ʾJsonVO����������Ӧ���ͻ���

class SalesContractListJsonVO : public JsonVO<SalesContractListDTO::Wrapper>
{
	DTO_INIT(SalesContractListJsonVO, JsonVO<SalesContractListDTO::Wrapper>);
};


//����һ�����ۺ�ͬ��ҳ��ʾJsonVO����������Ӧ���ͻ���
class SalesContractListPageJsonVO : public JsonVO<SalesContractListPageDTO::Wrapper>
{
	DTO_INIT(SalesContractListPageJsonVO, JsonVO<SalesContractListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 