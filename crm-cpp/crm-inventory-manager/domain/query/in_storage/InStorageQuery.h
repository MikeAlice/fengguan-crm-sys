#pragma once

#ifndef INSTORAGEQUERY_H__
#define INSTORAGEQUERY_H__

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class InStorageQuery : public PageQuery
{
	DTO_INIT(InStorageQuery, PageQuery);
	// id  单号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("instorage.field.id");
	}
	// contract_id  合同编号
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.contract_id");
	}
	// title  主题
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("instorage.field.title");
	}
	// store_id  仓库编号
	DTO_FIELD(UInt64, store_id);
	DTO_FIELD_INFO(store_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.store_id");
	}
	// into_user  入库人
	DTO_FIELD(String, into_user);
	DTO_FIELD_INFO(into_user) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_user");
	}
	// create_user  创建人
	DTO_FIELD(String, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_user");
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
	// 入库状态是有符号的
	DTO_FIELD(Int64, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("instorage.field.status");
	}
	// number  数量
	DTO_FIELD(UInt64, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("instorage.field.number");
	}
	// money  金额
	DTO_FIELD(Float64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("instorage.field.money");
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
};

#include OATPP_CODEGEN_END(DTO)
#endif // !INSTORAGEQUERY_H__