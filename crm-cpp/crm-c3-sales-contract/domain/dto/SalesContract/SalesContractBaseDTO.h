#pragma once
#ifndef _SALESCONTRACTBASE_DTO_H_
#define _SALESCONTRACTBASE_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SalesContractBaseDTO : public oatpp::DTO
{
	DTO_INIT(SalesContractBaseDTO, DTO);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCONTRACTBASE_DTO_H_
