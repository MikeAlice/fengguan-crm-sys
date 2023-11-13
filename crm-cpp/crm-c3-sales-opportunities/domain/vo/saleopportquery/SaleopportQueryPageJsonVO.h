#pragma once

#ifndef SALEOPPORTQUERYPAGEJSONVO_H__
#define SALEOPPORTQUERYPAGEJSONVO_H__
#include "../../GlobalInclude.h"
#include "../../dto/saleopport/SaleopportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * saleopport 
 
 */
class SaleopportJsonVO : public JsonVO<SaleopportDTO::Wrapper>
{
	DTO_INIT(SaleopportJsonVO, JsonVO<SaleopportDTO::Wrapper>);
	
};

/**
* SaleopportPage
*/
class SaleopportPageJsonVO : public JsonVO<SaleopportPgaeDTO::Wrapper>
{
	DTO_INIT(SaleopportPageJsonVO, JsonVO<SaleopportPgaeDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // SALEOPPORTQUERYPAGEJSONVO_H__
