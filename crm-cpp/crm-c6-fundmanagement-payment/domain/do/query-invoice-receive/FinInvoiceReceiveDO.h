#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 15:21:14

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
#ifndef _FININVOICERECEIVEDO_H_
#define _FININVOICERECEIVEDO_H_

class FinInvoiceReceiveDO
{
	//收票记录ID	供应商名称	合同标题	发票内容/编号/金额	收票时间	期次	创建人	备注
	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	CC_SYNTHESIZE(string, contract_name, ContractName);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(uint64_t, invoice_no, InvoiceNo);
	CC_SYNTHESIZE(uint64_t, money, Money);
	CC_SYNTHESIZE(string, rece_date, ReceDate);
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	CC_SYNTHESIZE(string, create_user, CreateUser);
	CC_SYNTHESIZE(string, intro, Intro);
public:
	FinInvoiceReceiveDO() :record_id(0), supplier_name(""), contract_name(""), name(""),
		invoice_no(0), money(0), rece_date(""), stages(0), create_user(""), intro("")
	{}
	
};

#endif // !_FININVOICERECEIVEDO_H_