#pragma once
/*
* ʵ�ַ����ѯVO
*�����ˣ����ܵ���
*/

#ifndef _SERVICE_VO_
#define _SERVICE_VO_
#include "../../GlobalInclude.h"
#include"../../dto/service/ServiceBaseDTO.h"
#include"../../dto/service/ServiceDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * �����¼�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ServiceJsonVO : public JsonVO<ServiceDetailDTO::Wrapper> {
	DTO_INIT(ServiceJsonVO, JsonVO<ServiceDetailDTO::Wrapper>);
};

/**
 * �����¼��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class  ServiceNotePageJsonVO : public JsonVO<ServiceNotePageDTO::Wrapper> {
	DTO_INIT(ServiceNotePageJsonVO, JsonVO<ServiceNotePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SERVICE_VO_
