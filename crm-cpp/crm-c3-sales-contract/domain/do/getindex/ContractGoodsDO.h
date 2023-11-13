#pragma once
#ifndef _CONTRACTGOODSDO_H_
#define _CONTRACTGOODSDO_H_
#include "../DoInclude.h"

 /** 
 * 原味的原味包
 * 查询合同清单，从数据库得到的数据
 * 商品名称	goods_name
 * 商品规格	sku_name
 * 价格		sale_price
 * 购买数量	num
 * 总价		goods_money
 * 备注		remarks
 */
class ContractGoodsDO
{
	CC_SYNTHESIZE(string, goods_name, GoodsName);
	CC_SYNTHESIZE(string, sku_name, SkuName);
	CC_SYNTHESIZE(double_t, sale_price, SalePrice);
	CC_SYNTHESIZE(int64_t, num, Num);
	CC_SYNTHESIZE(double_t, goods_money, GoodsMoney);
	CC_SYNTHESIZE(string, remarks, Remarks);

public:
	ContractGoodsDO() {
		goods_name = "";
		sku_name = "";
		sale_price = 0.;
		num = 0;
		goods_money = 0.;
		remarks = "";
	}
};

#endif