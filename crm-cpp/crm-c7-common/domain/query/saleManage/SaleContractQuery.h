#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 21:09:04

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
#ifndef _SALECONTRACTQUERY_H_
#define _SALECONTRACTQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 销售合同QUERY
 * 负责人: Andrew
 */
class SaleContractQuery : public oatpp::DTO
{
	DTO_INIT(SaleContractQuery, DTO);
	API_DTO_FIELD_DEFAULT(UInt32, customer_id, ZH_WORDS_GETTER("sale-manage.sale-contract.field.customer_id"));
	API_DTO_FIELD(String, title, ZH_WORDS_GETTER("sale-manage.sale-contract.field.title"), false, "");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SALECONTRACTQUERY_H_