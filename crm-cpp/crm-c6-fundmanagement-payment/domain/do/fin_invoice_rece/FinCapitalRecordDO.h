#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/23
 @FileName: FinCapitalRecordDO
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
#ifndef _FIN_CAPITAL_RECORD_DO_
#define _FIN_CAPITAL_RECORD_DO_
#include "../DoInclude.h"
class FinCapitalRecordDO 
{
	/*// ����
	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	// ֧������
	CC_SYNTHESIZE(int64_t, type_id, TypeId);
	// ������
	CC_SYNTHESIZE(int64_t, create_user_id, CreateUserId);
	// �����˺�
	CC_SYNTHESIZE(uint64_t, bank_id, BankId);
	// ���
	CC_SYNTHESIZE(int64_t, money, Money);
	// ��ע
	CC_SYNTHESIZE(string, intro, Intro);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ��������
	CC_SYNTHESIZE(string, happen_date, HappenDate);*/

	// ����
	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	//�����ɹ���
	CC_SYNTHESIZE(uint64_t, contract_id, ContractId);
	//��Ӧ�̺�
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// �ɹ�������
	CC_SYNTHESIZE(string, contract_name, ContractName);
	//��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	// ���
	CC_SYNTHESIZE(int64_t, money, Money);
	// ��Ʊ����
	CC_SYNTHESIZE(string, rece_date, ReceDate);
	// �ڴ�
	CC_SYNTHESIZE(int64_t, stages, Stages);
	//��Ʊ����
	CC_SYNTHESIZE(string, name, Name);
	//��Ʊ���
	CC_SYNTHESIZE(uint64_t, invoice_no, InvoiceNo);
	//��ע
	CC_SYNTHESIZE(string, intro, Intro);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//������id
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
public:
	FinCapitalRecordDO()
	{
		/*record_id = 1;
		type_id = 1;
		money = 100;
		bank_id = 123456;
		happen_date = "2023-10-24";
		create_user_id = 1024;
		create_time = "2023-10-24 00:00:00";
		intro = "Hello";*/
		record_id = 1;
		contract_id = 1;
		supplier_id = 1;
		contract_name = "";
		supplier_name = "";
		money = 100;
		rece_date = "2023 - 10 - 24";
		stages = 1;
		name = "";
		invoice_no = 1;
		intro = "";
		create_time = "2023-10-24 00:00:00";
		create_user_id = 1;
	}
};
#endif