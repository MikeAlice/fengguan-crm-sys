#pragma once

#ifndef INSTORAGEQUERY_H__
#define INSTORAGEQUERY_H__

#include "../..//GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class InStorageQuery : public PageQuery
{
	DTO_INIT(InStorageQuery, PageQuery);
	// id  单号
	DTO_FIELD(Int32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("instorage.field.id");
	}
	// contract_id  合同编号
	DTO_FIELD(Int32, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.contract_id");
	}
	// title  主题
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("instorage.field.title");
	}
	// store_id  仓库编号
	DTO_FIELD(Int32, store_id);
	DTO_FIELD_INFO(store_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.store_id");
	}
	// into_user_id  入库人
	DTO_FIELD(Int32, into_user_id);
	DTO_FIELD_INFO(into_user_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_user_id");
	}
	// create_user_id  创建人
	DTO_FIELD(Int32, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_user_id");
	}
	// create_time  创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_time");
	}
	// intro 备注
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("instorage.field.intro");
	}
	// status  入库状态
	DTO_FIELD(Int32, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("instorage.field.status");
	}
	// number  数量
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("instorage.field.number");
	}
	// into_time  入库时间
	DTO_FIELD(String, into_time);
	DTO_FIELD_INFO(into_time) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_time");
	}
	// into_type  入库类型
	DTO_FIELD(String, into_type);
	DTO_FIELD_INFO(into_type) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_type");
	}
	// good_name 商品名称-入库单明细
	DTO_FIELD(String, good_name);
	DTO_FIELD_INFO(good_name) {
		info->description = ZH_WORDS_GETTER("instorage.field.good_name");
	}
	// sku_name sku名称-入库单明细
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("instorage.field.sku_name");
	}
	// suppliers_name 供应商名称-供应商
	DTO_FIELD(String, suppliers_name);
	DTO_FIELD_INFO(suppliers_name) {
		info->description = ZH_WORDS_GETTER("instorage.field.suppliers_name");
	}
	// address 通信地址-供应商联系人
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("instorage.field.address");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !INSTORAGEQUERY_H__