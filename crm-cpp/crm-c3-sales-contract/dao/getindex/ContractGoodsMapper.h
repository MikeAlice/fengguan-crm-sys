#pragma once
#ifndef _CONTRACTGOODSMAPPER_H_
#define _CONTRACTGOODSMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/getindex/ContractGoodsDO.h"

/**
* 获取的合同清单字段匹配
* DAO中查询语句片段：
* SELECT
*	scl.goods_name, fgs.sku_name, scl.sale_price, scl.num, scl.goods_money, scl.remarks
* 因此映射顺序：
*	商品名称 1
*	商品规格 2
*	价格	    3
*	购买数量 4
*	小计    5
*   备注    6
*/
class ContractGoodsMapper : public Mapper<ContractGoodsDO> {
public:
	ContractGoodsDO mapper(ResultSet* resultSet) const override {
		ContractGoodsDO data;
		data.setGoodsName(resultSet->getString(1));
		data.setSkuName(resultSet->getString(2));
		data.setSalePrice(resultSet->getDouble(3));
		data.setNum(resultSet->getInt64(4));
		data.setGoodsMoney(resultSet->getDouble(5));
		data.setRemarks(resultSet->getString(6));
		return data;
	}
};


#endif