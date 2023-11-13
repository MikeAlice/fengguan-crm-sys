#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 21:11:54

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
#ifndef _SALECONTRACTDTO_H_
#define _SALECONTRACTDTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 销售合同名称DTO
 * 负责人: Andrew
 */
class SaleContractDTO : public oatpp::DTO
{
	DTO_INIT(SaleContractDTO, DTO);
	API_DTO_FIELD_DEFAULT(UInt32, contract_id, ZH_WORDS_GETTER("sale-manage.sale-contract.field.contract_id"));
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("sale-manage.sale-contract.field.title"));
};

/**
 * 销售合同名称列表DTO
 * 负责人: Andrew
 */
class SaleContractListDTO : public ListDTO<SaleContractDTO::Wrapper>
{
	DTO_INIT(SaleContractListDTO, ListDTO<SaleContractDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SALECONTRACTDTO_H_