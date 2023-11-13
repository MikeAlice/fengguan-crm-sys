#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/23 22:26:29

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
#ifndef _DELSUPLINKMANDTO_H_
#define _DELSUPLINKMANDTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除供应商联系人DTO
 * 负责人: ll
 */
class RemoveSupLinkmanDTO : public ListDTO<oatpp::UInt64>
{
	DTO_INIT(RemoveSupLinkmanDTO, ListDTO<oatpp::UInt64>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELSUPLINKMANDTO_H_