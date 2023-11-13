#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 弱弟
 @Date: 2023/10/24 11:52:32

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
#ifndef _INVENTORYLIST_DO_
#define _INVENTORYLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class InventoryListDO
{
	CC_SYNTHESIZE(int32_t, goods_id, Goods_id);
	CC_SYNTHESIZE(int64_t, sku_id, Sku_id);
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	CC_SYNTHESIZE(string, sku_name, Sku_name);
	CC_SYNTHESIZE(int64_t, number, Number);
	CC_SYNTHESIZE(string, category_name, Category_name);
	CC_SYNTHESIZE(string, store_name, Store_name);
	CC_SYNTHESIZE(float, sale_price, Sale_price);
	CC_SYNTHESIZE(float, cost_price, Cost_price);
	CC_SYNTHESIZE(float, cost_amount, Cost_amount);
	CC_SYNTHESIZE(float, anticipated_profit, Anticipated_profit);
	CC_SYNTHESIZE(string, original_code, Original_code);
	
public:
	InventoryListDO() {
		goods_id = 0;
		sku_id = 0;
		goods_name = "";
		sku_name = "";
		number = 0;
		category_name = "";
		store_name = "";
		sale_price = 0;
		cost_price = 0;
		cost_amount = 0;
		anticipated_profit = 0;
		original_code = "";		
	}
};

#endif // !_SAMPLE_DO_
