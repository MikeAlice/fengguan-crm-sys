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
#ifndef _LISTCUSTOMER_DTO_
#define _LISTCUSTOMER_DTO_
#include "../../GlobalInclude.h"
#include "domain/dto/BaseCustomer/BaseCustomerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ��б������
 */
class ListCustomerDTO : public BaseCustomerDTO
{
	DTO_INIT(ListCustomerDTO, BaseCustomerDTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("customer.field.owner_user_id"));

	// ������Ա����
	API_DTO_FIELD_DEFAULT(String, owner_user_name, ZH_WORDS_GETTER("customer.field.owner_user_name"));

	//�´ι�ͨʱ��
	API_DTO_FIELD_DEFAULT(String, next_time, ZH_WORDS_GETTER("customer.field.next_time"));

	//�����ϵʱ��
	API_DTO_FIELD_DEFAULT(String, conn_time, ZH_WORDS_GETTER("customer.field.conn_time"));

	//�����ͨ����
	API_DTO_FIELD_DEFAULT(String, conn_body, ZH_WORDS_GETTER("customer.field.conn_body"));

};

/**
 * �ͻ��б��ҳ�������
 */
class ListCustomerPageDTO : public PageDTO<ListCustomerDTO::Wrapper>
{
	DTO_INIT(ListCustomerPageDTO, PageDTO<ListCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTCUSTOMER_DTO_