#pragma once

#ifndef EXPENDITURESQUERYPAGEJSONVO_H__
#define EXPENDITURESQUERYPAGEJSONVO_H__
#include "../../GlobalInclude.h"
#include "../../dto/expenditures/ExpendituresDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * expenditures 
 */
class ExpendituresJsonVO : public JsonVO<ExpendituresDTO::Wrapper>
{
	DTO_INIT(ExpendituresJsonVO, JsonVO<ExpendituresDTO::Wrapper>);
	
};

/**
* expendituresPage
*/
class ExpendituresPageJsonVO : public JsonVO<ExpendituresPageDTO::Wrapper>
{
	DTO_INIT(ExpendituresPageJsonVO, JsonVO<ExpendituresPageDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // EXPENDITURESQUERYPAGEJSONVO_H__
