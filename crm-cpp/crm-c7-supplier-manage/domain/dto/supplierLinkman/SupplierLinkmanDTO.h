#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: telephone
 @Date: 2023/10/23 18:20:31

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
#ifndef _SUPPLIER_LINK_MAN_DTO_
#define _SUPPLIER_LINK_MAN_DTO_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加供应商联系人传输对象
 * 负责人: telephone
 */
class AddSupplierLinkmanDTO : public oatpp::DTO
{
	DTO_INIT(AddSupplierLinkmanDTO, DTO);
	// 供应商联系人姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("supplier-linkman.query-page.field.name"));
	// 供应商ID
	API_DTO_FIELD_DEFAULT(UInt64, supplier_id, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-id"));
	// 性别
	API_DTO_FIELD_DEFAULT(UInt64, gender, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-gender"));
	// 职位
	API_DTO_FIELD_DEFAULT(String, position, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-position"));
	// 座机
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("supplier-linkman.query-page.field.tel"));
	// 手机号
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("supplier-linkman.query-page.field.mobile"));
	// QQ
	API_DTO_FIELD_DEFAULT(String, qicq, ZH_WORDS_GETTER("supplier-linkman.query-page.field.qq"));
	// 邮箱
	API_DTO_FIELD_DEFAULT(String, email, ZH_WORDS_GETTER("supplier-linkman.query-page.field.email"));
	// 通信地址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("supplier-linkman.query-page.field.address"));
	// 介绍
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("supplier-linkman.query-page.field.intro"));
	// 扩展字段
	API_DTO_FIELD(Fields<String>, ext_fields, ZH_WORDS_GETTER("supplier-linkman.query-page.field.ext-fields"), false, Fields<String>::createShared());
};

class ModifySupplierLinkmanDTO : public AddSupplierLinkmanDTO
{
	DTO_INIT(ModifySupplierLinkmanDTO, AddSupplierLinkmanDTO);
	// 供应商联系人ID
	API_DTO_FIELD_DEFAULT(UInt64, linkman_id, ZH_WORDS_GETTER("supplier-linkman.query-page.field.id"));
};

/**
 * 供应商联系人传输对象
 * 负责人: telephone
 */
class SupplierLinkmanDTO : public ModifySupplierLinkmanDTO
{
	DTO_INIT(SupplierLinkmanDTO, ModifySupplierLinkmanDTO);
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-name"));
	// 邮政编码
	API_DTO_FIELD_DEFAULT(String, zipcode, ZH_WORDS_GETTER("supplier-linkman.query-page.field.zipcode"));
	// 创建用户ID
	API_DTO_FIELD_DEFAULT(UInt64, create_user_id, ZH_WORDS_GETTER("supplier-linkman.query-page.field.create-user-id"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("supplier-linkman.query-page.field.create-time"));
};

/**
 * 供应商联系人分页传输对象
 * 负责人: telephone
 */
class SupplierLinkmanPageDTO : public PageDTO<SupplierLinkmanDTO::Wrapper>
{
	DTO_INIT(SupplierLinkmanPageDTO, PageDTO<SupplierLinkmanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
