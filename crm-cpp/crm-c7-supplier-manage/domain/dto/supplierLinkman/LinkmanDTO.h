#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Tapioca
 @Date: 2023/10/22 14:06:27

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
#ifndef _LINKMANDTO_H_
#define _LINKMANDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改供应商联系人信息的数据传输模型
 * 负责人: tapioca
 */
class LinkmanDTO : public oatpp::DTO
{
    DTO_INIT(LinkmanDTO, DTO);
	// 联系人ID
	API_DTO_FIELD_DEFAULT(UInt64, linkman_id, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.linkman-id"));
    
    // 姓名
    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.name"));

    // 性别
    API_DTO_FIELD_DEFAULT(UInt64, gender, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.sex"));

    // 电话
    API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.tel"));

    // 职位
    API_DTO_FIELD_DEFAULT(String, position, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.position"));

    // 手机
    API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.mobile"));

    // 邮箱
    API_DTO_FIELD_DEFAULT(String, email, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.e-mail"));

	// QQ
	API_DTO_FIELD_DEFAULT(String, qicq, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.qq"));

    // 通信地址
    API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.address"));

	// 供应商ID
	API_DTO_FIELD_DEFAULT(UInt64, supplier_id, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.supplier-id"));

    // 供应商名称
    //API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.supplier-name"));

    // 扩展字段
    API_DTO_FIELD(Fields<String>, ext_fields, ZH_WORDS_GETTER("supplier-linkman.modify-link-man.field.ext-fields"), false, Fields<String>::createShared());

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LINKMANDTO_H_