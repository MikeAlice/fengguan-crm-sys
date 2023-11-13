#pragma once
#ifndef _BANKACCOUNT_DO_
#define _BANKACCOUNT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class BankAccountDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t,bank_id,Bank_id);
	// 开户银行名称
	CC_SYNTHESIZE(string, name, Name);
	// 银行账号
	CC_SYNTHESIZE(uint64_t, card, Card);
	// 银行地址
	CC_SYNTHESIZE(string, address, Address);
	//开户人
	CC_SYNTHESIZE(string,holders,Holders);
	//排序
	CC_SYNTHESIZE(uint64_t, sort, Sort);
	//是否启用
	CC_SYNTHESIZE(uint64_t, visible, Visible);//不知道bool类型是啥


public:
	BankAccountDO() {
		bank_id = 0;
		name = "";
		card = 0;
		address = "";
		holders = "";
		sort = 0;
		visible = 0;
	}
};
class BankAccountListDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, bank_id, Bank_id);
	// 开户银行名称
	CC_SYNTHESIZE(string, name, Name);
	// 银行账号
	CC_SYNTHESIZE(uint64_t, card, Card);

public:
	BankAccountListDO() {
		bank_id = 0;
		name = "";
		card = 0;
		
	}
};

#endif // !_BANKACCOUNT_DO_