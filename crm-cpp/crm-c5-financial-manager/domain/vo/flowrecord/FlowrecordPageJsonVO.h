#pragma once
#ifndef FLOWRECORDPAGEJSONVO_H__
#define FLOWRECORDPAGEJSONVO_H__

#include "../../GlobalInclude.h"
#include "../../dto/flowrecord/FlowrecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class FlowrecordPageJsonVO : public JsonVO<FlowrecordPageDTO::Wrapper> {
	DTO_INIT(FlowrecordPageJsonVO, JsonVO<FlowrecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
