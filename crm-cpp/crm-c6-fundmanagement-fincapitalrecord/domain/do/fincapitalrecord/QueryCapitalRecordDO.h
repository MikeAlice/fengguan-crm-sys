#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/23
 @FileName: QueryCapitalRecordDO
 @version: 1.0

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
#ifndef _QUERY_CAPITAL_RECORD_DO_
#define _QUERY_CAPITAL_RECORD_DO_
#include "../DoInclude.h"

class QueryCapitalRecordDO
{
	// 单号
	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	// 支出类型
	CC_SYNTHESIZE(string, type, Type);
	// 金额
	CC_SYNTHESIZE(int64_t, money, Money);
	// 银行账户id
	CC_SYNTHESIZE(int64_t, bank_id, BankId);
	// 开户银行名称
	CC_SYNTHESIZE(string, bank_name, BankName);
	// 银行卡号
	CC_SYNTHESIZE(string, bank_card, BankCard);
	// 产生日期
	CC_SYNTHESIZE(string, happen_date, HappenDate);
	// 创建人
	CC_SYNTHESIZE(string, create_user, CreateUser);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 备注
	CC_SYNTHESIZE(string, intro, Intro);

public:
};
#endif