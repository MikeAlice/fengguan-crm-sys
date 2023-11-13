#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 19:57:27

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
#ifndef _SUPPLIERLINKMANFORMITEMDTO_H_
#define _SUPPLIERLINKMANFORMITEMDTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 供应商表单数据项DTO
 * 负责人: Andrew
 */
class SupplierLinkmanFormItemDTO : public oatpp::DTO
{
	DTO_INIT(SupplierLinkmanFormItemDTO, DTO);
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.supplier-name"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, sup_name, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.name"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, sup_sex, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.sex"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, work, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.work"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.phone"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, z_phone, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.z-phone"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, QQ, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.QQ"));
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("supplier-linkman.supplier-linkman-form-item.mail"));
public:
	SupplierLinkmanFormItemDTO()
	{

	}
};

/**
 * 供应商表单数据项列表DTO
 * 负责人: Andrew
 */
class SupFormItemListDTO : public ListDTO<SupFormItemDTO::Wrapper>
{
	DTO_INIT(SupFormItemListDTO, ListDTO<SupFormItemDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SUPFORMITEMDTO_H_