#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/22

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
#ifndef _MODIFYDELIVERSTATUSDTO_H_
#define _MODIFYDELIVERSTATUSDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改交付状态传输数据
 */
class ModifyDeliverStatusDTO : public oatpp::DTO
{
	DTO_INIT(ModifyDeliverStatusDTO, DTO);
	// 合同ID
	API_DTO_FIELD_DEFAULT(Int32, contract_id, ZH_WORDS_GETTER("sal-contract.field.contract-id"));
	// 交付状态
	API_DTO_FIELD_DEFAULT(Int32, deliver_status, ZH_WORDS_GETTER("sal-contract.field.deliver-status"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFYDELIVERSTATUSDTO_H_