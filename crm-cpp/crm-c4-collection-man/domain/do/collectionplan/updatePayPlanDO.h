#pragma once
#ifndef _UPDATEPAYPLAN_DO_
#define _UPDATEPAYPLAN_DO_
#include "../DoInclude.h"


class updatePayPlanDO
{
	// 客户名称
	CC_SYNTHESIZE(string, clientName, ClientName);
	// 客户名称编号
	CC_SYNTHESIZE(int, clientNameId, ClientNameId);
	// 销售合同
	CC_SYNTHESIZE(string, saleContract, SaleContract);
	// 销售合同编号
	CC_SYNTHESIZE(int, saleContractId, SaleContractId);
	// 总金额
	CC_SYNTHESIZE(double, totalAmount, TotalAmount);
	// 去零金额
	CC_SYNTHESIZE(double, noZeroAmount, NoZeroAmount);
	// 已回款金额
	CC_SYNTHESIZE(double, backAmount, BackAmount);
	// 已开发票金额
	CC_SYNTHESIZE(double, invoiceAmount, InvoiceAmount);
	// 计划回款日期
	CC_SYNTHESIZE(string, planBackDate, PlanBackDate);
	// 期次
	CC_SYNTHESIZE(int, period, Period);
	// 计划回款金额
	CC_SYNTHESIZE(double, planBackAmount, PlanBackAmount);
	// 计划汇款编号
	CC_SYNTHESIZE(int, id, Id);

public:
	updatePayPlanDO() {
		clientName = "";
		clientNameId = 0;
		saleContract = "";
		saleContractId = 0;
		totalAmount = 0;
		noZeroAmount = 0;
		backAmount = 0;
		invoiceAmount = 0;
		planBackDate = "";
		period = 0;
		planBackAmount = 0;
		id = 1;
	}
};
class updateConfirmPlanDO
{
	// 客户名称
	CC_SYNTHESIZE(string, clientName, ClientName);
	// 客户名称编号
	CC_SYNTHESIZE(int, clientNameId, ClientNameId);
	// 销售合同
	CC_SYNTHESIZE(string, saleContract, SaleContract);
	// 销售合同编号
	CC_SYNTHESIZE(int, saleContractId, SaleContractId);
	// 总金额
	CC_SYNTHESIZE(double, totalAmount, TotalAmount);
	// 去零金额
	CC_SYNTHESIZE(double, noZeroAmount, NoZeroAmount);
	// 已付金额
	CC_SYNTHESIZE(double, havePayAmount, HavePayAmount);
	// 已开发票金额
	CC_SYNTHESIZE(double, invoiceAmount, InvoiceAmount);
	// 计划回款日期
	CC_SYNTHESIZE(string, planBackDate, PlanBackDate);
	// 期次
	CC_SYNTHESIZE(int, period, Period);
	// 付款金额
	CC_SYNTHESIZE(double, payAmount, PayAmount);
	// 付款账户
	CC_SYNTHESIZE(string, payAccount, PayAccount);
	// 回款计划编号
	CC_SYNTHESIZE(int, id, Id);
public:
	updateConfirmPlanDO() {
		clientName = "";
		clientNameId = 0;
		saleContract = "";
		saleContractId = 0;
		totalAmount = 0;
		noZeroAmount = 0;
		havePayAmount = 0;
		invoiceAmount = 0;
		planBackDate = "";
		period = 0;
		payAmount = 0;
		payAccount = "";
		id = 1;
	}
};
#endif 
