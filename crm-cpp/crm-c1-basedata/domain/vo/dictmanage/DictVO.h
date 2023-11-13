#pragma once
#ifndef _DICT_VO_
#define _DICT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/dictmanage/DictDTO.h"
//#include "Message.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class DictJsonVO : public JsonVO<DictDTO::Wrapper> {
	DTO_INIT(DictJsonVO, JsonVO<DictDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class DictPageJsonVO : public JsonVO<DictPageDTO::Wrapper> {
	DTO_INIT(DictPageJsonVO, JsonVO<DictPageDTO::Wrapper>);
};

/**
 * 下拉列表显示JsonVO，用于响应给客户端的Json对象
 */
class DictTypePageJsonVO : public JsonVO<oatpp::List<DictTypeListDTO::Wrapper>>
{
	DTO_INIT(DictTypePageJsonVO, JsonVO<List<DictTypeListDTO::Wrapper>>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DICT_VO_
