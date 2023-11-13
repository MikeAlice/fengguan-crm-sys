/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/20
 @FileName:StorageDetailsDTO
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

#ifndef STORAGEDETAILSDTO_H__
#define STORAGEDETAILSDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * StorageDetailsDTO传输对象
 */
class StorageDetailsDTO : public oatpp::DTO
{
	DTO_INIT(StorageDetailsDTO, DTO);
	
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

class StorageDetailsPageDTO : public PageDTO<StorageDetailsDTO::Wrapper>
{
	DTO_INIT(StorageDetailsPageDTO, PageDTO<StorageDetailsDTO::Wrapper>);
};

class ExportStorageDetailsDTO : public oatpp::DTO
{
	DTO_INIT(ExportStorageDetailsDTO, DTO);
	// 订单项ID
	DTO_FIELD(UInt64, list_id);
	DTO_FIELD_INFO(list_id) {
		info->description = ZH_WORDS_GETTER("storagedetails.field.list_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // STORAGEDETAILSDTO_H__