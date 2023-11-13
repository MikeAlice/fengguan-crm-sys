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
#ifndef _USERQUERY_H_
#define _USERQUERY_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询供应商联系人列表的的数据传输模型
 * 负责人: telephone
 */
class SupplierLinkmanQuery : public PageQuery
{
	DTO_INIT(SupplierLinkmanQuery, PageQuery);
	// 关键字搜索(姓名/手机号/座机/QQ)
	API_DTO_FIELD_DEFAULT(String, keywords, ZH_WORDS_GETTER("supplier-linkman.query-page.field.keywords"));
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-name"));
	// 通信地址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("supplier-linkman.query-page.field.address"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
