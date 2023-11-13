#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _ADD_PAY_RECORD_
#define _ADD_PAY_RECORD_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UpdatePayPlanDO
{
	// ��¼���
//	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	// �ƻ����
	CC_SYNTHESIZE(uint64_t, plan_id, PlanId);
	// ��ͬ���
	CC_SYNTHESIZE(uint64_t, contract_id, ContractId);
	// ��ͬ����
	CC_SYNTHESIZE(string, contract_name, ContractName);
	// ��Ӧ�̱��
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// ��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	// ���б��
	CC_SYNTHESIZE(uint64_t, band_id, BankId);
	// �ƻ���������
	CC_SYNTHESIZE(string, plan_date, PlanDate);
	// ������
	CC_SYNTHESIZE(string, money, Money);
	//�Ƿ񸶿�
	CC_SYNTHESIZE(string, ifpay, IfPay);
	// �ڴ�
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	// ��ע
	CC_SYNTHESIZE(string, intro, Intro);
	// ������¼ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// �������û�id
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);

public:
	std::string ContracttoString() const {
		std::string result = contract_name + "";
		return result;
	}
	std::string SuppliertoString() const {
		std::string result = supplier_name + "";
		return result;
	}
	UpdatePayPlanDO() {
		//		record_id = 0;
		plan_id = 0;
		contract_id = 0;
		contract_name = "";
		supplier_id = 0;
		supplier_name = "";
		band_id = 0;
		money = -1;
		stages = 0;
		intro = "";
		create_time = "";
		create_user_id = 0;
	}
};

#endif // !_SAMPLE_DO_
