#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/03 18:40:33

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
#ifndef _BANKACCOUNTJSONVO_H_
#define _BANKACCOUNTJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/financeType/BankAccountDTO.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BankAccountArrayJsonVO : public JsonVO<oatpp::List<BankAccountDTO::Wrapper>>
{
	DTO_INIT(BankAccountArrayJsonVO, JsonVO<oatpp::List<BankAccountDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BANKACCOUNTJSONVO_H_