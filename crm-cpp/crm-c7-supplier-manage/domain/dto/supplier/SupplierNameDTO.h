#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 22:27:04

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
#ifndef _SUPPLIER_NAME_DTO_
#define _SUPPLIER_NAME_DTO_

#include "../../GlobalInclude.h"
#include "domain/dto/ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 供应商传输对象
 * 负责人: Juno
 */
class SupplierNameDTO : public oatpp::DTO
{
	DTO_INIT(SupplierNameDTO, DTO);
	// 供应商名称
	DTO_FIELD(String, supplierName);
	DTO_FIELD_INFO(supplierName) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.supplierName");
	}
	// 供应商id
	DTO_FIELD(UInt64, supplierId);
	DTO_FIELD_INFO(supplierId) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.supplierId");
	}
};

/**
 * 列表传输对象
 * 负责人: Juno
 */
class SupplierNameListDTO : public ListDTO<SupplierNameDTO::Wrapper>
{
	DTO_INIT(SupplierNameListDTO, ListDTO<SupplierNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_