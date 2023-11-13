#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/29

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
#ifndef _SALCONTRACTLISTDO_H_
#define _SALCONTRACTLISTDO_H_

#include "../DoInclude.h"

/**
 * 销售合同明细数据库实体类
 */

class SalContractListDO
{
	// 合同ID
	CC_SYNTHESIZE(int, contract_id, ContractID);
	// 商品名称
	CC_SYNTHESIZE(string, goods_name, GoodsName);
	// 商品ID
	CC_SYNTHESIZE(int, goods_id, GoodsID);
	// skuID
	CC_SYNTHESIZE(int, sku_id, SkuID);
	// sku名称
	CC_SYNTHESIZE(string, sku_name, SkuName);
	// 商品价格
	CC_SYNTHESIZE(float, sale_price, SalePrice);
	// 购买数量
	CC_SYNTHESIZE(int, num, Num);
	// 商品总价
	CC_SYNTHESIZE(float, goods_money, GoodsMoney);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
	// 创建时间（必须）
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	SalContractListDO()
	{
		contract_id = 1;
		goods_name = "商品名称";
		goods_id = 1;
		sku_id = 1;
		sku_name = "sku名称";
		sale_price = 200.00;
		num = 10;
		goods_money = 2000.00;
		remarks = "备注";
		create_time = "2000-00-00";
	}
};

#endif // !_SALCONTRACTLISTDO_H_