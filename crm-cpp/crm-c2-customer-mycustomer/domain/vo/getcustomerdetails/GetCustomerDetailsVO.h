#pragma once
#ifndef _GETCUSTOMERDETAILS_VO_
#define _GETCUSTOMERDETAILS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/getcustomerdetails/GetCustomerDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ���ϸ��Ϣ���ض���
 */

class GetCustomerDetailsJsonVO : public JsonVO<GetCustomerDetailsDTO::Wrapper> {
	DTO_INIT(GetCustomerDetailsJsonVO, JsonVO<GetCustomerDetailsDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_GETCUSTOMERDETAILS_VO_