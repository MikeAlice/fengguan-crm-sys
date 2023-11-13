#pragma once
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OutBoundQuery : public PageQuery
{
	DTO_INIT(OutBoundQuery, PageQuery);
	// Sales contract id
	DTO_FIELD(String, OutBoundId);
	DTO_FIELD_INFO(OutBoundId) {
		info->description = "OutBound id";
	}
};

#include OATPP_CODEGEN_END(DTO)

