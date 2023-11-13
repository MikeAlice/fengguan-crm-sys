#pragma once
#ifndef _CONTRACTAMOUNT_DO_
#define _CONTRACTAMOUNT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ContractamountDO
{
	// 总金额
	CC_SYNTHESIZE(uint64_t, total_money, Total_money);
	// 去零金额
	CC_SYNTHESIZE(uint64_t, zero_money, Zero_money);
	// 已付金额
	CC_SYNTHESIZE(uint64_t, paid_money, Paid_money);
	// 已付发票金额
	CC_SYNTHESIZE(uint64_t, invoice_money, Invoice_money);
public:
	ContractamountDO() {
		total_money = 0;
		zero_money = 0;
		paid_money = 0;
		invoice_money = 0;
	}
};

#endif // !_CONTRACTAMOUNT_DO_