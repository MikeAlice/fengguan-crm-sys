#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MODIFYTRACE_DTO_
#define _MODIFYTRACE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ModifyTraceDTO : public oatpp::DTO
{
	DTO_INIT(ModifyTraceDTO, DTO);
		//跟踪记录id
		API_DTO_FIELD_DEFAULT(Int32, trace_id, ZH_WORDS_GETTER("trace.field.TR_id"))
		//客户名称id
		API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("trace.field.AC_id"))
		//联系客户人id
		API_DTO_FIELD_DEFAULT(Int32, linkman_id, ZH_WORDS_GETTER("trace.field.CC_id"))
		//沟通方式id
		API_DTO_FIELD_DEFAULT(Int32, FMethodid, ZH_WORDS_GETTER("trace.field.FM_id"))
		//沟通日期
		API_DTO_FIELD_DEFAULT(String, FTime, ZH_WORDS_GETTER("trace.field.FT"))
		//联系内容
		API_DTO_FIELD_DEFAULT(String, CContent, ZH_WORDS_GETTER("trace.field.CContent"))
		//当前阶段id
		API_DTO_FIELD_DEFAULT(Int32, CStageid, ZH_WORDS_GETTER("trace.field.CS_id"))
		//客户销售机会id
		API_DTO_FIELD_DEFAULT(Int32, SOid, ZH_WORDS_GETTER("trace.field.SO_id"))
		//下次沟通日期
		API_DTO_FIELD_DEFAULT(String, NTime, ZH_WORDS_GETTER("trace.field.NT"))
};

/**
 * 示例分页传输对象
 */

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_