#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
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
 * ���ۺ�ͬ��ϸ���ݿ�ʵ����
 */

class SalContractListDO
{
	// ��ͬID
	CC_SYNTHESIZE(int, contract_id, ContractID);
	// ��Ʒ����
	CC_SYNTHESIZE(string, goods_name, GoodsName);
	// ��ƷID
	CC_SYNTHESIZE(int, goods_id, GoodsID);
	// skuID
	CC_SYNTHESIZE(int, sku_id, SkuID);
	// sku����
	CC_SYNTHESIZE(string, sku_name, SkuName);
	// ��Ʒ�۸�
	CC_SYNTHESIZE(float, sale_price, SalePrice);
	// ��������
	CC_SYNTHESIZE(int, num, Num);
	// ��Ʒ�ܼ�
	CC_SYNTHESIZE(float, goods_money, GoodsMoney);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// ����ʱ�䣨���룩
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	SalContractListDO()
	{
		contract_id = 1;
		goods_name = "��Ʒ����";
		goods_id = 1;
		sku_id = 1;
		sku_name = "sku����";
		sale_price = 200.00;
		num = 10;
		goods_money = 2000.00;
		remarks = "��ע";
		create_time = "2000-00-00";
	}
};

#endif // !_SALCONTRACTLISTDO_H_