#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/23
 @FileName: AddCapitalRecordDO
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
#ifndef _ADD_CAPITAL_RECORD_DO_
#define _ADD_CAPITAL_RECORD_DO_
#include "../DoInclude.h"

class AddCapitalRecordDO
{
	// ����
	//CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	// ֧������
	CC_SYNTHESIZE(int64_t, type_id, TypeId);
	// �����˺�id
	CC_SYNTHESIZE(int64_t, bank_id, BankId);
	// ������
	CC_SYNTHESIZE(int64_t, create_user_id, CreateUserId);
	// ���
	CC_SYNTHESIZE(int64_t, money, Money);
	// ��ע
	CC_SYNTHESIZE(string, intro, Intro);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ��������
	CC_SYNTHESIZE(string, happen_date, HappenDate);
public:
};
#endif