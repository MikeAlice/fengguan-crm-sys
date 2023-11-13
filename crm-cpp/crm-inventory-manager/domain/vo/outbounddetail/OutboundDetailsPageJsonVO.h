#pragma once
#ifndef OUTBOUNDDETAILSPAGEJSONVO_H__
#define OUTBOUNDDETAILSPAGEJSONVO_H__
#include "../../GlobalInclude.h"
#include "../../dto/outbounddetail/OutboundDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * outbound
 */
class OutboundDetailJsonVO : public JsonVO<OutboundDetailDTO::Wrapper>
{
	DTO_INIT(OutboundDetailJsonVO, JsonVO<OutboundDetailDTO::Wrapper>);
	
};

/**
* outboundPage
*/
class OutboundDetailPageJsonVO : public JsonVO<OutboundDetailPageDTO::Wrapper>
{
	DTO_INIT(OutboundDetailPageJsonVO, JsonVO<OutboundDetailPageDTO::Wrapper>);

};


#include OATPP_CODEGEN_END(DTO)
#endif // OUTBOUNDDETAILSPAGEJSONVO_H__
