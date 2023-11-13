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
 * ����һ��׷�ټ�¼�����ݴ���ģ��
 */
class TraceDTO : public oatpp::DTO
{
	DTO_INIT(TraceDTO, DTO);
		// ���
		API_DTO_FIELD_DEFAULT(UInt64, trace_id, ZH_WORDS_GETTER("trace.field.trace_id"));
		//�����ͻ�
	    API_DTO_FIELD_DEFAULT(String, ACustomer, ZH_WORDS_GETTER("trace.field.AC"))
		//��ϵ�ͻ�
		API_DTO_FIELD_DEFAULT(String, CustomerC, ZH_WORDS_GETTER("trace.field.CC"))
		//������ʽ
		API_DTO_FIELD_DEFAULT(String, FMethod, ZH_WORDS_GETTER("trace.field.FM"))
		//����ʱ��
		API_DTO_FIELD_DEFAULT(String, FTime, ZH_WORDS_GETTER("trace.field.FT"))
		//��ͨ����
		API_DTO_FIELD_DEFAULT(String, CContent, ZH_WORDS_GETTER("trace.field.CContent"))
		//��ǰ�׶�
		API_DTO_FIELD_DEFAULT(String, CStage, ZH_WORDS_GETTER("trace.field.CS"))
		//���ۻ���
		API_DTO_FIELD_DEFAULT(String, SOpportunity, ZH_WORDS_GETTER("trace.field.SO"))
		//�´ι�ͨ
		API_DTO_FIELD_DEFAULT(String, NTime, ZH_WORDS_GETTER("trace.field.NT"))
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TRACEDTO_H_