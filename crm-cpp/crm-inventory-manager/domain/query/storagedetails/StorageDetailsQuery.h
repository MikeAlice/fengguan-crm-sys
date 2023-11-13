/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/20
 @FileName:StorageDetailsQuery
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

#ifndef STORAGEDETAILSQUERY_H__
#define STORAGEDETAILSQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * storagedetails查询对象
 */
class StorageDetailsQuery : public PageQuery
{
	DTO_INIT(StorageDetailsQuery, PageQuery);
	
	// 商品ID
	DTO_FIELD(UInt64, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.goods_id");
	}
	// SKU ID
	DTO_FIELD(UInt64, sku_id);
	DTO_FIELD_INFO(sku_id) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.sku_id");
	}
	// 商品名
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.goods_name");
	}
	// SKU名
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.sku_name");
	}
	// 数量
	DTO_FIELD(UInt64, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.number");
	}
	// 商品类型
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.category_name");
	}
	// 仓库名称
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.store_name");
	}
	// 对应入库单
	DTO_FIELD(String, into_intro);
	DTO_FIELD_INFO(into_intro) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.into_intro");
	}
	// 入库时间
	DTO_FIELD(String, into_time);
	DTO_FIELD_INFO(into_time) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.into_time");
	}
	// 备注
	DTO_FIELD(String, remarks);
	DTO_FIELD_INFO(remarks) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.remarks");
	}
	// 供应商名称
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.supplier_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // STORAGEDETAILSQUERY_H__