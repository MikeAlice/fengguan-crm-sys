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
#ifndef _NAMECUSTOMER_DTO_
#define _NAMECUSTOMER_DTO_
#include "../../GlobalInclude.h"
#include "domain/dto/BaseCustomer/BaseCustomerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ����ƴ������
 */
class NameCustomerDTO : public BaseCustomerDTO
{
	DTO_INIT(NameCustomerDTO, BaseCustomerDTO);

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

};

/**
 * �ͻ����Ʒ�ҳ�������
 */
class NameCustomerPageDTO : public PageDTO<NameCustomerDTO::Wrapper>
{
	DTO_INIT(NameCustomerPageDTO, PageDTO<NameCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NAMECUSTOMER_DTO_