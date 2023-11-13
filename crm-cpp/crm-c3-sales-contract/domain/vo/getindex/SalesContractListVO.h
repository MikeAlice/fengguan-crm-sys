#pragma once

#ifndef _SALESCONTRACTLISTVO_H_
#define _SALESCONTRACTLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/getindex/SalesContractListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//定义一个销售合同显示JsonVO对象，用于响应给客户端

class SalesContractListJsonVO : public JsonVO<SalesContractListDTO::Wrapper>
{
	DTO_INIT(SalesContractListJsonVO, JsonVO<SalesContractListDTO::Wrapper>);
};


//定义一个销售合同分页显示JsonVO对象，用于响应给客户端
class SalesContractListPageJsonVO : public JsonVO<SalesContractListPageDTO::Wrapper>
{
	DTO_INIT(SalesContractListPageJsonVO, JsonVO<SalesContractListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 