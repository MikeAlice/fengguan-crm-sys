/*
 Copyright ruodi. All rights reserved.

 @Author: ruodi
 @Date: 2023/10/20
 @FileName:InventoryListQuery
 @version:1.0

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

#ifndef INVENTORYLISTQUERY_H__
#define INVENTORYLISTQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * inventorylist��ѯ����
 */
class InventoryListQuery : public oatpp::DTO
{
	DTO_INIT(InventoryListQuery, DTO);

	// ��ƷID
	DTO_FIELD(UInt64, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.goods_id");
	}
	// SKU ID
	DTO_FIELD(UInt64, sku_id);
	DTO_FIELD_INFO(sku_id) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.sku_id");
	}
	// ��Ʒ��
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.goods_name");
	}
	// SKU��
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.sku_name");
	}
	// ����
	DTO_FIELD(UInt64, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.number");
	}
	// ��Ʒ����
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.category_name");
	}
	// �ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.store_name");
	}
	// ���ۼ۸�
	DTO_FIELD(Float32, sale_price);
	DTO_FIELD_INFO(sale_price) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.sale_price");
	}
	// �ɱ��۸�
	DTO_FIELD(Float32, cost_price);
	DTO_FIELD_INFO(cost_price) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.cost_price");
	}
	// �ɱ����
	DTO_FIELD(Float32, cost_amount);
	DTO_FIELD_INFO(cost_amount) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.cost_amount");
	}
	// Ԥ������
	DTO_FIELD(Float32, anticipated_profit);
	DTO_FIELD_INFO(anticipated_profit) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.anticipated_profit");
	}
	// ԭ������
	DTO_FIELD(String, Original_code);
	DTO_FIELD_INFO(Original_code) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.Original_code");
	}
};
/**
 * expendituresPage��ѯ����
 */
class InventoryListPageQuery :public PageQuery
{
	DTO_INIT(InventoryListPageQuery, PageQuery);
	// ��ƷID
	DTO_FIELD(UInt64, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.goods_id");
	}
	// SKU ID
	DTO_FIELD(UInt64, sku_id);
	DTO_FIELD_INFO(sku_id) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.sku_id");
	}
	// ��Ʒ��
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.goods_name");
	}
	// SKU��
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.sku_name");
	}
	// ����
	DTO_FIELD(UInt64, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.number");
	}
	// ��Ʒ����
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.category_name");
	}
	// �ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.store_name");
	}
	// ���ۼ۸�
	DTO_FIELD(Float32, sale_price);
	DTO_FIELD_INFO(sale_price) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.sale_price");
	}
	// �ɱ��۸�
	DTO_FIELD(Float32, cost_price);
	DTO_FIELD_INFO(cost_price) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.cost_price");
	}
	// �ɱ����
	DTO_FIELD(Float32, cost_amount);
	DTO_FIELD_INFO(cost_amount) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.cost_amount");
	}
	// Ԥ������
	DTO_FIELD(Float32, anticipated_profit);
	DTO_FIELD_INFO(anticipated_profit) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.anticipated_profit");
	}
	// ԭ������
	DTO_FIELD(String, Original_code);
	DTO_FIELD_INFO(Original_code) {
		info->description = ZH_WORDS_GETTER("inventorylist.field.Original_code");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // EXPENDITURESQUERY_H__
