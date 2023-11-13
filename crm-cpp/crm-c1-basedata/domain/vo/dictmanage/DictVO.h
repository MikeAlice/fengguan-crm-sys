#pragma once
#ifndef _DICT_VO_
#define _DICT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/dictmanage/DictDTO.h"
//#include "Message.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictJsonVO : public JsonVO<DictDTO::Wrapper> {
	DTO_INIT(DictJsonVO, JsonVO<DictDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictPageJsonVO : public JsonVO<DictPageDTO::Wrapper> {
	DTO_INIT(DictPageJsonVO, JsonVO<DictPageDTO::Wrapper>);
};

/**
 * �����б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictTypePageJsonVO : public JsonVO<oatpp::List<DictTypeListDTO::Wrapper>>
{
	DTO_INIT(DictTypePageJsonVO, JsonVO<List<DictTypeListDTO::Wrapper>>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DICT_VO_
