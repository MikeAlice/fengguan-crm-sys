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
#include "stdafx.h"
#include "SalContractListService.h"
#include "SimpleDateTimeFormat.h"

bool SalContractListService::inputList(const InputListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO对象
	SalContractListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		ContractID, contract_id,
		GoodsName, goods_name,
		GoodsID, goods_id,
		SkuID, sku_id,
		SkuName, sku_name,
		SalePrice, sale_price,
		Num, num,
		GoodsMoney, goods_money,
		Remarks, remarks
	);
	//data.setUpdater(payload.getUsername());
	data.setCreateTime(SimpleDateTimeFormat::format());
	// TODO: 调用dao操作数据库
	SalContractListDAO dao;
	return dao.inputList(data);
}
