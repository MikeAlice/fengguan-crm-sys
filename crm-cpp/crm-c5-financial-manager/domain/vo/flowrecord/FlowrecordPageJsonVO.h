#pragma once
#ifndef FLOWRECORDPAGEJSONVO_H__
#define FLOWRECORDPAGEJSONVO_H__

#include "../../GlobalInclude.h"
#include "../../dto/flowrecord/FlowrecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FlowrecordPageJsonVO : public JsonVO<FlowrecordPageDTO::Wrapper> {
	DTO_INIT(FlowrecordPageJsonVO, JsonVO<FlowrecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
