#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/11/09
 @FileName: BankAccountDTO
 @version: 1.0

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
#ifndef _BANK_ACCOUNT_DTO_
#define _BANK_ACCOUNT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BankAccountDTO : public oatpp::DTO
{
	DTO_INIT(BankAccountDTO, DTO);
	// name ������������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("fin_bank_account.field.name"));
	// card �˻���
	API_DTO_FIELD_DEFAULT(String, card, ZH_WORDS_GETTER("fin_bank_account.field.card"));

public:

};

#include OATPP_CODEGEN_END(DTO)

#endif