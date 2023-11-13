#pragma once
/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/24 11:52:21

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
#ifndef _INCOME_DO_
#define _INCOME_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class IncomeDO
{
	// record_id
	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	// type_id
	CC_SYNTHESIZE(uint64_t, type_id, TypeId);
	// bank_id
	CC_SYNTHESIZE(uint64_t, bank_id, BankId);
	// money
	CC_SYNTHESIZE(double, money, Money);
	// intro
	CC_SYNTHESIZE(string, intro, Intro);
	// happen_date
	CC_SYNTHESIZE(string, happen_date, HappenDate);
	// user_id
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	// create_time
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	IncomeDO() {
		record_id = 0;
		type_id = 0;
		bank_id = 0;
		money = 0.00;
		intro = "";
		happen_date = "";
		create_user_id = 0;
		create_time = "";
	}
};

#endif // !_INCOME_DO_