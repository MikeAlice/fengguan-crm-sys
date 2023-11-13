#pragma once

#ifndef _GETTRACE_DTO_
#define _GETTRACE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */

class GetTraceDTO : public oatpp::DTO
{	

	DTO_INIT(GetTraceDTO, DTO);
	// 客户名称
	DTO_FIELD(String, AC);
	DTO_FIELD_INFO(AC) {
		info->description = ZH_WORDS_GETTER("trace.field.AC");
	}
	// 客户名称id
	DTO_FIELD(Int32, AC_id);
	DTO_FIELD_INFO(AC_id) {
		info->description = ZH_WORDS_GETTER("trace.field.AC_id");
	}
	// 最近联系时间
	DTO_FIELD(String, FT);
	DTO_FIELD_INFO(FT) {
		info->description = ZH_WORDS_GETTER("trace.field.FT");
	}
	// 联系内容
	DTO_FIELD(String, CContent);
	DTO_FIELD_INFO(CContent) {
		info->description = ZH_WORDS_GETTER("trace.field.CContent");
	}


	// 下次联系时间
	DTO_FIELD(String, NT);
	DTO_FIELD_INFO(NT) {
		info->description = ZH_WORDS_GETTER("trace.field.NT");
	}
	// 沟通方式
	DTO_FIELD(String, FM);
	DTO_FIELD_INFO(FM) {
		info->description = ZH_WORDS_GETTER("trace.field.FM");
	}


	// 当前阶段
	DTO_FIELD(String, CS);
	DTO_FIELD_INFO(CS) {
		info->description = ZH_WORDS_GETTER("trace.field.CS");
	}
	// 当前阶段id
	DTO_FIELD(Int32, CS_id);
	DTO_FIELD_INFO(CS_id) {
		info->description = ZH_WORDS_GETTER("trace.field.CS_id");
	}



};

/**
 * 示例分页传输对象
 */
class TracePageDTO : public PageDTO<GetTraceDTO::Wrapper>
{
	DTO_INIT(TracePageDTO, PageDTO<GetTraceDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_