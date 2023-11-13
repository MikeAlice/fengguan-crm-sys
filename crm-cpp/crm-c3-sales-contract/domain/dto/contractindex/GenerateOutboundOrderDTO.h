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
#ifndef _DETAILSCUSTOMER_DTO_
#define _DETAILSCUSTOMER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户详情传输对象
 */
class GenerateOutboundOrderDTO : public oatpp::DTO
{
	DTO_INIT(GenerateOutboundOrderDTO, DTO);
	// 客户ID
	DTO_FIELD(UInt32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("customer.field.customer_id");
	}
	// 客户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	// 客户编号
	API_DTO_FIELD_DEFAULT(UInt32, customer_no, ZH_WORDS_GETTER("customer.field.customer_no"));

	// 创建人员
	API_DTO_FIELD_DEFAULT(UInt32, create_user_id, ZH_WORDS_GETTER("customer.field.create_user_id"));

	// 创建人员名称
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("customer.field.create_user_name"));

	// 归属人员
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("customer.field.owner_user_id"));

	// 归属人员名称
	API_DTO_FIELD_DEFAULT(String, owner_user_name, ZH_WORDS_GETTER("customer.field.owner_user_name"));

	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("customer.field.create_time"));

	//下次沟通时间
	API_DTO_FIELD_DEFAULT(String, next_time, ZH_WORDS_GETTER("customer.field.next_time"));

	//最近联系时间
	API_DTO_FIELD_DEFAULT(String, conn_time, ZH_WORDS_GETTER("customer.field.conn_time"));

	//最近沟通内容
	API_DTO_FIELD_DEFAULT(String, conn_body, ZH_WORDS_GETTER("customer.field.conn_body"));

	//客户代表
	API_DTO_FIELD_DEFAULT(String, linkman, ZH_WORDS_GETTER("customer.field.linkman"));

	//客户来源
	API_DTO_FIELD_DEFAULT(String, source, ZH_WORDS_GETTER("customer.field.source"));

	//客户等级
	API_DTO_FIELD_DEFAULT(String, grade, ZH_WORDS_GETTER("customer.field.grade"));

	//客户行业
	API_DTO_FIELD_DEFAULT(String, industry, ZH_WORDS_GETTER("customer.field.industry"));

	//联系手机
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("customer.field.mobile"));

	//联系电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("customer.field.tel"));

	//联系地址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("customer.field.address"));

	//客户介绍
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("customer.field.intro"));

	//客户需求
	API_DTO_FIELD_DEFAULT(String, needs, ZH_WORDS_GETTER("customer.field.needs"));
};

/**
 * 客户详情分页传输对象
 */
class GenerateOutboundOrderPageDTO : public PageDTO<GenerateOutboundOrderDTO::Wrapper>
{
	DTO_INIT(GenerateOutboundOrderPageDTO, PageDTO<GenerateOutboundOrderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DETAILSCUSTOMER_DTO_