#pragma once
/*
* 负责人：老菌
*/
#ifndef _CONTACTFIELD_VO_
#define _CONTACTFIELD_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/contactfield/ContactFieldDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 联系人名称显示JsonVO，用于响应给客户端的Json对象
 */
class ContactFieldJsonVO : public JsonVO<ContactFieldDTO::Wrapper> {
	DTO_INIT(ContactFieldJsonVO, JsonVO<ContactFieldDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTACTFIELD_VO_