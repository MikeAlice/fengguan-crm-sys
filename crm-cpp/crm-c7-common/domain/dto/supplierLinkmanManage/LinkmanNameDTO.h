#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/24 4:04:01

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
#ifndef _LINKMANNAMEDTO_H_
#define _LINKMANNAMEDTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LinkmanNameDTO : public oatpp::DTO
{
	DTO_INIT(LinkmanNameDTO, DTO);
	API_DTO_FIELD_DEFAULT(UInt64, linkman_id, ZH_WORDS_GETTER("supplier-linkman.query-linkman-name-list.field.linkman-id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("supplier-linkman.query-linkman-name-list.field.name"));
};

class LinkmanNameListDTO : public ListDTO<LinkmanNameDTO::Wrapper>
{
	DTO_INIT(LinkmanNameListDTO, ListDTO<LinkmanNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LINKMANNAMEDTO_H_