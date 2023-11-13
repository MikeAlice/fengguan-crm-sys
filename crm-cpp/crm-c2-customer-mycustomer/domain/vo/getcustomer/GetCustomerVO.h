#ifndef _GETCUSTOMER_VO_
#define _GETCUSTOMER_VO_

#include "domain/dto/getcustomer/GetCustomerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�ͻ��б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */

class GetCustomerPageJsonVO : public JsonVO<GetCustomerPageDTO::Wrapper> {
	DTO_INIT(GetCustomerPageJsonVO, JsonVO<GetCustomerPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_GETCUSTOMER_VO_