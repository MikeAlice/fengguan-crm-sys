#pragma once
/*
* 实现服务查询VO
*负责人：会跑的鱼
*/

#ifndef _SERVICE_VO_
#define _SERVICE_VO_
#include "../../GlobalInclude.h"
#include"../../dto/service/ServiceBaseDTO.h"
#include"../../dto/service/ServiceDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 服务记录列表显示JsonVO，用于响应给客户端的Json对象
 */
class ServiceJsonVO : public JsonVO<ServiceDetailDTO::Wrapper> {
	DTO_INIT(ServiceJsonVO, JsonVO<ServiceDetailDTO::Wrapper>);
};

/**
 * 服务记录分页显示JsonVO，用于响应给客户端的Json对象
 */
class  ServiceNotePageJsonVO : public JsonVO<ServiceNotePageDTO::Wrapper> {
	DTO_INIT(ServiceNotePageJsonVO, JsonVO<ServiceNotePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SERVICE_VO_
