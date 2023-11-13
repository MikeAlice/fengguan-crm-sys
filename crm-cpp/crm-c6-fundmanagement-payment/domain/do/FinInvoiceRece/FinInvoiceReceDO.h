#pragma once
#ifndef _FININVOICERECE_DO_
#define _FININVOICERECE_DO_

#include "../../../Macros.h"
#include<string>

using namespace std;

class FinInvoiceReceDO {
	//记录编号
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	//关联采购号
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	//供应商号
	CC_SYNTHESIZE(uint64_t, supplier_id, Supplier_id);
	//关联采购名
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	//供应商名
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//金额
	CC_SYNTHESIZE(uint64_t, money, Money);
	//收票时间
	CC_SYNTHESIZE(string, rece_date, Rece_date);
	//期次
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	//发票内容
	CC_SYNTHESIZE(string, name, Name);
	//发票编号
	CC_SYNTHESIZE(string, invoice_no, Invoice_no);
	//备注
	CC_SYNTHESIZE(string, intro, Intro);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//创建人id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
public:
	FinInvoiceReceDO() {
		record_id = 0;
		contract_id = 0;
		supplier_id = 0;
		contract_name = "";
		supplier_name = "";
		money = 0;
		rece_date = "";
		stages = 0;
		name = "";
		invoice_no = "";
		intro = "";
		create_time = "";
		create_user_id = 0;
	}
};


#endif
