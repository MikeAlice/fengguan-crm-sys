#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chou
 @Date: 2023/10/23 14:21:43

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
#ifndef _ADDCOLLECTIONPLANDTO_H_
#define _ADDCOLLECTIONPLANDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ## 添加回款计划
 */
class AddCollectionPlanDTO : public oatpp::DTO
{
	DTO_INIT(AddCollectionPlanDTO, DTO);
	// 客户id
	API_DTO_FIELD(Int32, customer_id, ZH_WORDS_GETTER("collectionplans.field.customer_id"), true, 1234);
	// 客户名字
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("collectionplans.field.name"));
	// 合同订单名称
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("collectionplans.field.contract_name"));
	// 合同订单编号
	API_DTO_FIELD(Int32, contract_id, ZH_WORDS_GETTER("collectionplans.field.contract_id"), true, 1234);
	// 回款日期
	API_DTO_FIELD(String, backdate, ZH_WORDS_GETTER("collectionplans.field.backdate"), true, "2002-11-11");
	// 期次
	API_DTO_FIELD(Int32, stages, ZH_WORDS_GETTER("collectionplans.field.stages"), true, 1);
	// 总金额
	API_DTO_FIELD(Int32, money, ZH_WORDS_GETTER("collectionplans.field.money"), true, 1234);
	// 当前用户id
	// API_DTO_FIELD_DEFAULT(Int32, create_user_id, ZH_WORDS_GETTER("collectionplans.field.create_user_id"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDCOLLECTIONPLANDTO_H_