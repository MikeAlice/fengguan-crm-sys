#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/18 15:01:29

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
#ifndef _FILEDTO_H_
#define _FILEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ټ�¼�б��ļ��������ݶ���
 */
class RecordsFileDTO : public oatpp::DTO
{
	DTO_INIT(RecordsFileDTO, DTO);
	// ���ټ�¼���ӵ�ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.img-href"));
public:
	RecordsFileDTO() {}
	RecordsFileDTO(String url, String alt = "", String href = "")
	{
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_