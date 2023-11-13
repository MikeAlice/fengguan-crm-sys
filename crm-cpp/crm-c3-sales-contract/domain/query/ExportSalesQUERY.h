#pragma once
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportSalesQuery : public oatpp::DTO
{
	DTO_INIT(ExportSalesQuery, DTO);
	API_DTO_FIELD_DEFAULT(Int16, contractId, ZH_WORDS_GETTER("SalesContract.field.contract_id"));
	API_DTO_FIELD_DEFAULT(Int16, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));


};

#include OATPP_CODEGEN_END(DTO)

