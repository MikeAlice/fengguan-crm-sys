#pragma once

#ifndef OUTBOUNDDETAILDO_H__
#define OUTBOUNDDETAILDO_H__
#include "../DoInclude.h"

/*
出库明细实体类
*/
class OutboundDetailDO
{
	//CC_SYNTHESIZE(unsigned int, id, Id);
	CC_SYNTHESIZE(int, SKUID, Skuid);
	CC_SYNTHESIZE(string, SKUname, Skuname);
	CC_SYNTHESIZE(string, goodsName, GoodsName);
	CC_SYNTHESIZE(int, goodsId, GoodsId);
	CC_SYNTHESIZE(long long,number,Number);
	CC_SYNTHESIZE(string,commodityType,CommodityType)
	CC_SYNTHESIZE(string,storehouse,Storehouse);
	CC_SYNTHESIZE(long long, stockOut,StockOut);
	CC_SYNTHESIZE(string,stockOutTime, StockOutTime);
	CC_SYNTHESIZE(string,note,Note);
	//CC_SYNTHESIZE(string,supplierName,SupplierName);
	//CC_SYNTHESIZE(string, contactAdd, ContactAdd);
public:
	OutboundDetailDO() {
		SKUID = 0;
		SKUname = "";
		goodsId = 0;
		goodsName = "";
		number = 0;
		storehouse = "";
		stockOutTime = "";
		stockOut = 0;
		note = "";
	}
};
#endif // OUTBOUNDDETAILDO_H__



