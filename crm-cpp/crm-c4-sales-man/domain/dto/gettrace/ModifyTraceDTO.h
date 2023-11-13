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
 * ʾ���������
 */
class ModifyTraceDTO : public oatpp::DTO
{
	DTO_INIT(ModifyTraceDTO, DTO);
		//���ټ�¼id
		API_DTO_FIELD_DEFAULT(Int32, trace_id, ZH_WORDS_GETTER("trace.field.TR_id"))
		//�ͻ�����id
		API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("trace.field.AC_id"))
		//��ϵ�ͻ���id
		API_DTO_FIELD_DEFAULT(Int32, linkman_id, ZH_WORDS_GETTER("trace.field.CC_id"))
		//��ͨ��ʽid
		API_DTO_FIELD_DEFAULT(Int32, FMethodid, ZH_WORDS_GETTER("trace.field.FM_id"))
		//��ͨ����
		API_DTO_FIELD_DEFAULT(String, FTime, ZH_WORDS_GETTER("trace.field.FT"))
		//��ϵ����
		API_DTO_FIELD_DEFAULT(String, CContent, ZH_WORDS_GETTER("trace.field.CContent"))
		//��ǰ�׶�id
		API_DTO_FIELD_DEFAULT(Int32, CStageid, ZH_WORDS_GETTER("trace.field.CS_id"))
		//�ͻ����ۻ���id
		API_DTO_FIELD_DEFAULT(Int32, SOid, ZH_WORDS_GETTER("trace.field.SO_id"))
		//�´ι�ͨ����
		API_DTO_FIELD_DEFAULT(String, NTime, ZH_WORDS_GETTER("trace.field.NT"))
};

/**
 * ʾ����ҳ�������
 */

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_