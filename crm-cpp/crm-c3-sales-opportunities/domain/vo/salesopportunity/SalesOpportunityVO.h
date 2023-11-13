#pragma once
#ifndef _SALES_OPPORTUNITY_VO_
#define _SALES_OPPORTUNITY_VO_
#include "../../GlobalInclude.h"
#include "../crm-c3-sales-opportunities/domain/dto/salesopportunityinfo/DeleteSalesOpDTO.h"
#include "../crm-c3-sales-opportunities/domain/dto/salesopportunityinfo/UpdateSalesOpDTO.h"
#include "../crm-c3-sales-opportunities/domain/dto/salesopportunityinfo/InsertSalesOpDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class UpdateSalesOpportunityJsonVO : public JsonVO<UpdateSalesOpDTO::Wrapper> {
	DTO_INIT(UpdateSalesOpportunityJsonVO, JsonVO<UpdateSalesOpDTO::Wrapper>);
};
class DeleteSalesOpportunityJsonVO : public JsonVO<DeleteSalesOpDTO::Wrapper> {
	DTO_INIT(DeleteSalesOpportunityJsonVO, JsonVO<DeleteSalesOpDTO::Wrapper>);
};
class InsertSalesOpportunityJsonVO : public JsonVO<InsertSalesOpDTO::Wrapper> {
	DTO_INIT(InsertSalesOpportunityJsonVO, JsonVO<InsertSalesOpDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SALES_OPPORTUNITY_VO_