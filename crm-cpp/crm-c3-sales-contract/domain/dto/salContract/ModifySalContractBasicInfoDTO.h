#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
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
#ifndef _MODIFYSALCONTRACTBASICINFODTO_H_
#define _MODIFYSALCONTRACTBASICINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸����ۺ�ͬ������Ϣ��������
 */
class ModifySalContractBasicInfoDTO : public oatpp::DTO
{
	DTO_INIT(ModifySalContractBasicInfoDTO, DTO);
	// ��ͬID
	API_DTO_FIELD_DEFAULT(Int32, contract_id, ZH_WORDS_GETTER("sal-contract.field.contract-id"));
	//// ��ͬ���
	//API_DTO_FIELD_DEFAULT(String, contract_no, ZH_WORDS_GETTER("sal-contract.field.contract-no"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("sal-contract.field.title"));
	// �ͻ�ID
	API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("sal-contract.field.customer-id"));
	// ��ϵ��ID
	API_DTO_FIELD_DEFAULT(Int32, linkman_id, ZH_WORDS_GETTER("sal-contract.field.linkman-id"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("sal-contract.field.start-date"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("sal-contract.field.end-date"));
	// ��ͬ���
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("sal-contract.field.money"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("sal-contract.field.intro"));
	// �ҷ���ϵ��
	API_DTO_FIELD_DEFAULT(Int32, our_user_id, ZH_WORDS_GETTER("sal-contract.field.our-user-id"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFYSALCONTRACTBASICINFODTO_H_