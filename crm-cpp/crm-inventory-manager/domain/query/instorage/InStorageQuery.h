#pragma once

#ifndef INSTORAGEQUERY_H__
#define INSTORAGEQUERY_H__

#include "../..//GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class InStorageQuery : public PageQuery
{
	DTO_INIT(InStorageQuery, PageQuery);
	// id  ����
	DTO_FIELD(Int32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("instorage.field.id");
	}
	// contract_id  ��ͬ���
	DTO_FIELD(Int32, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.contract_id");
	}
	// title  ����
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("instorage.field.title");
	}
	// store_id  �ֿ���
	DTO_FIELD(Int32, store_id);
	DTO_FIELD_INFO(store_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.store_id");
	}
	// into_user_id  �����
	DTO_FIELD(Int32, into_user_id);
	DTO_FIELD_INFO(into_user_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_user_id");
	}
	// create_user_id  ������
	DTO_FIELD(Int32, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_user_id");
	}
	// create_time  ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_time");
	}
	// intro ��ע
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("instorage.field.intro");
	}
	// status  ���״̬
	DTO_FIELD(Int32, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("instorage.field.status");
	}
	// number  ����
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("instorage.field.number");
	}
	// into_time  ���ʱ��
	DTO_FIELD(String, into_time);
	DTO_FIELD_INFO(into_time) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_time");
	}
	// into_type  �������
	DTO_FIELD(String, into_type);
	DTO_FIELD_INFO(into_type) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_type");
	}
	// good_name ��Ʒ����-��ⵥ��ϸ
	DTO_FIELD(String, good_name);
	DTO_FIELD_INFO(good_name) {
		info->description = ZH_WORDS_GETTER("instorage.field.good_name");
	}
	// sku_name sku����-��ⵥ��ϸ
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("instorage.field.sku_name");
	}
	// suppliers_name ��Ӧ������-��Ӧ��
	DTO_FIELD(String, suppliers_name);
	DTO_FIELD_INFO(suppliers_name) {
		info->description = ZH_WORDS_GETTER("instorage.field.suppliers_name");
	}
	// address ͨ�ŵ�ַ-��Ӧ����ϵ��
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("instorage.field.address");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !INSTORAGEQUERY_H__