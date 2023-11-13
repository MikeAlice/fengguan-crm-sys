#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/21 16:11:19

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
#ifndef _EXPORTSUPLINKMANQUERY_H_
#define _EXPORTSUPLINKMANQUERY_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "../../dto/ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ӧ����ϵ��Query
 * ������: Andrew
 */
class ExportSupLinkmanQuery : public oatpp::DTO
{
	DTO_INIT(ExportSupLinkmanQuery, DTO);
	// �ؼ�������(��ƥ������/�ֻ���/����/QQ)
	API_DTO_FIELD_DEFAULT(String, keywords, ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.field.keywords"));
	// ��ַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.field.address"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.field.supplier_name"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTSUPLINKMANQUERY_H_