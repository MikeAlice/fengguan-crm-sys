#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/22

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
#ifndef _INPUTLISTDTO_H_
#define _INPUTLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 录入明细传输数据
 */
class InputListDTO : public oatpp::DTO
{
	DTO_INIT(InputListDTO, DTO);
	// 合同ID
	API_DTO_FIELD_DEFAULT(Int32, contract_id, ZH_WORDS_GETTER("sal-contract-list.field.contract-id"));
	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("sal-contract-list.field.goods-name"));
	// 商品ID
	API_DTO_FIELD_DEFAULT(Int32, goods_id, ZH_WORDS_GETTER("sal-contract-list.field.goods-id"));
	// skuID
	API_DTO_FIELD_DEFAULT(Int32, sku_id, ZH_WORDS_GETTER("sal-contract-list.field.sku-id"));
	// sku名称
	API_DTO_FIELD_DEFAULT(String, sku_name, ZH_WORDS_GETTER("sal-contract-list.field.sku-name"));
	// 商品价格
	API_DTO_FIELD_DEFAULT(Float32, sale_price, ZH_WORDS_GETTER("sal-contract-list.field.sale-price"));
	// 购买数量
	API_DTO_FIELD_DEFAULT(Int32, num, ZH_WORDS_GETTER("sal-contract-list.field.num"));
	// 商品总价
	API_DTO_FIELD_DEFAULT(Float32, goods_money, ZH_WORDS_GETTER("sal-contract-list.field.goods-money"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remarks, ZH_WORDS_GETTER("sal-contract-list.field.remarks"));



};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INPUTLISTDTO_H_