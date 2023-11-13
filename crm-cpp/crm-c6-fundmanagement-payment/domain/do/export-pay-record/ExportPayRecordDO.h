#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/27 19:02:01

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
#ifndef _EXPORTPAYRECORDDO_H_
#define _EXPORTPAYRECORDDO_H_

#include "../DoInclude.h"

/**
 * 导出付款记录
 */
class ExportPayRecordDO
{
	//付款记录ID	供应商名称	采购合同	付款时间	期次	金额	去零	创建人	创建时间	备注
	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	CC_SYNTHESIZE(string, contract_name, ContractnName);
	CC_SYNTHESIZE(string, pay_date, PayDate);
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	CC_SYNTHESIZE(uint64_t, money, Money);
	CC_SYNTHESIZE(uint64_t, zero_money, ZeroMoney);
	//CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	CC_SYNTHESIZE(string, create_user, CreateUser);
	CC_SYNTHESIZE(string, create_time, CreateTime);
	CC_SYNTHESIZE(string, intro, Intro);
	/*CC_SYNTHESIZE(string, record_id, RecordId);*/

public:
	ExportPayRecordDO():record_id(0), supplier_name(""), contract_name(""), pay_date(""), 
		stages(0), money(0), zero_money(0), create_user(""), create_time(""), intro("")
	{}
	/*ExportPayRecordDO() :record_id("") {}*/
};

#endif // !_EXPORTPAYRECORDDO_H_