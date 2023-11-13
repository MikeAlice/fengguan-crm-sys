#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TRACEDTO_H_
#define _TRACEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个追踪记录的数据传输模型
 */
class TraceDTO : public oatpp::DTO
{
	DTO_INIT(TraceDTO, DTO);
		// 编号
		API_DTO_FIELD_DEFAULT(UInt64, trace_id, ZH_WORDS_GETTER("trace.field.trace_id"));
		//关联客户
	    API_DTO_FIELD_DEFAULT(String, ACustomer, ZH_WORDS_GETTER("trace.field.AC"))
		//联系客户
		API_DTO_FIELD_DEFAULT(String, CustomerC, ZH_WORDS_GETTER("trace.field.CC"))
		//跟进方式
		API_DTO_FIELD_DEFAULT(String, FMethod, ZH_WORDS_GETTER("trace.field.FM"))
		//跟进时间
		API_DTO_FIELD_DEFAULT(String, FTime, ZH_WORDS_GETTER("trace.field.FT"))
		//沟通内容
		API_DTO_FIELD_DEFAULT(String, CContent, ZH_WORDS_GETTER("trace.field.CContent"))
		//当前阶段
		API_DTO_FIELD_DEFAULT(String, CStage, ZH_WORDS_GETTER("trace.field.CS"))
		//销售机会
		API_DTO_FIELD_DEFAULT(String, SOpportunity, ZH_WORDS_GETTER("trace.field.SO"))
		//下次沟通
		API_DTO_FIELD_DEFAULT(String, NTime, ZH_WORDS_GETTER("trace.field.NT"))
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TRACEDTO_H_