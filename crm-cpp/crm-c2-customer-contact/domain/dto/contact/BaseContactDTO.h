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
#ifndef _BASECONTACT_DTO_
#define _BASECONTACT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 基础联系人传输对象
 */
class BaseContactDTO : public oatpp::DTO
{
	DTO_INIT(BaseContactDTO, DTO);
	// 联系人ID，主键
	DTO_FIELD(UInt32, linkman_id);
	DTO_FIELD_INFO(linkman_id) {
		info->description = ZH_WORDS_GETTER("contact.field.linkman_id");
	}
};

/**
 * 基础联系人分页传输对象
 */
class BaseContactPageDTO : public PageDTO<BaseContactDTO::Wrapper>
{
	DTO_INIT(BaseContactPageDTO, PageDTO<BaseContactDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASECONTACT_DTO_