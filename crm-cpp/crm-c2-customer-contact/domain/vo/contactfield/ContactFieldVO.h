#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _CONTACTFIELD_VO_
#define _CONTACTFIELD_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/contactfield/ContactFieldDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ϵ��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ContactFieldJsonVO : public JsonVO<ContactFieldDTO::Wrapper> {
	DTO_INIT(ContactFieldJsonVO, JsonVO<ContactFieldDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTACTFIELD_VO_