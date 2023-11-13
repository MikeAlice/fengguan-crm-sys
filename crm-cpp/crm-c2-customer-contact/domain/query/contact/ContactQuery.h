#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ContactQuery : public PageQuery
{
	DTO_INIT(ContactQuery, PageQuery);
	// 客户id
	DTO_FIELD(UInt64, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("sample.field.customer_id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 性别
	DTO_FIELD(UInt32, gender);
	DTO_FIELD_INFO(gender) {
		info->description = ZH_WORDS_GETTER("sample.field.gender");
	}
	//职位
	DTO_FIELD(String, postion);
	DTO_FIELD_INFO(postion) {
		info->description = ZH_WORDS_GETTER("sample.field.postion");
	}
	//手机
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("sample.field.mobile");
	}
	//座机
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("sample.field.tel");
	}
	//QQ
	DTO_FIELD(String, qicq);
	DTO_FIELD_INFO(qicq) {
		info->description = ZH_WORDS_GETTER("sample.field.qicq");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_