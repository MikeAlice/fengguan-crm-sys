#pragma once
#ifndef _INVOICE_DO_
#define _INVOICE_DO_
#include "Macros.h"
#include <string>
#include <list>
using namespace std;

/**
 * 示例数据库实体类
 */
class InvoiceDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// 合同id
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// 合同名字
	CC_SYNTHESIZE(string, contract_name ,Contract_name);
	//顾客id
	CC_SYNTHESIZE(uint64_t, customer_id, Customer_id);
	// 顾客名字
	CC_SYNTHESIZE(string,customer_name, Customer_name);
	//金额
	CC_SYNTHESIZE(uint64_t, money, Money);
	//开票日期
	CC_SYNTHESIZE(string,pay_date, Pay_date);
	//开票期次
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	//发票编号
	CC_SYNTHESIZE(string, invoice_no, Invoice_no);
	//经手人员
	CC_SYNTHESIZE(string,name ,Name );
	//开票类型
	CC_SYNTHESIZE(string,bus_type ,Bus_type );
	//备注
	CC_SYNTHESIZE(string,intro ,Intro );
	//创建时间
	CC_SYNTHESIZE(string,create_time ,Create_time);
	//创建人id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);

public:
	InvoiceDO() {
		record_id = 0;
		contract_id = 1;
		contract_name = "";
		customer_id = 0;
		customer_name = "";
		money = 0;
		pay_date = "";
		stages = 0;
		invoice_no = "";
		name = "";
		bus_type = "";
		intro = "";
		create_time = "";
		create_user_id = 0;
	}
};

#endif 