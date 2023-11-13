#pragma once

#ifndef INSTORAGEDTO_H__
#define INSTORAGEDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * InStorage�������
 */
class InStorageBaseDTO : public oatpp::DTO
{
	DTO_INIT(InStorageBaseDTO, DTO);
	// contract_id  ��ͬ���
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.contract_id");
	}
	// title  ����
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("instorage.field.title");
	}
	// store_id  �ֿ���
	DTO_FIELD(UInt64, store_id);
	DTO_FIELD_INFO(store_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.store_id");
	}
	// intro ��ע
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("instorage.field.intro");
	}
	// number  ����
	DTO_FIELD(UInt64, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("instorage.field.number");
	}
	// money  ���
	DTO_FIELD(Float64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("instorage.field.money");
	}
	// into_type  �������
	DTO_FIELD(String, into_type);
	DTO_FIELD_INFO(into_type) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_type");
	}
};

/**
*InStorageDTO
��ⵥ������󣬼̳�InStorageBaseDTO�����ڸ�ǰ����ʾ��ⵥ����Ϣ
*/
class InStorageDTO : public InStorageBaseDTO
{
	DTO_INIT(InStorageDTO, InStorageBaseDTO);
	// id  ����
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("instorage.field.id");
	}
	// into_user  �����
	DTO_FIELD(String, into_user);
	DTO_FIELD_INFO(into_user) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_user");
	}
	// create_user  ������
	DTO_FIELD(String, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_user");
	}
	// create_time  ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_time");
	}
	// status  ���״̬
	DTO_FIELD(Int64, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("instorage.field.status");
	}
	// into_time  ���ʱ��
	DTO_FIELD(String, into_time);
	DTO_FIELD_INFO(into_time) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_time");
	}
};

class DeleteByIDStorageDTO : public oatpp::DTO {
	DTO_INIT(DeleteByIDStorageDTO, DTO);
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("instorage.field.contract_id");
	}
};

class ModifyByIDStorageDTO : public oatpp::DTO {
	DTO_INIT(ModifyByIDStorageDTO, DTO);
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("instorage.field.id");
	}
	DTO_FIELD(String, into_user_id);
	DTO_FIELD_INFO(into_user_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.into_user_id");
	}
};

/*
* AddInStorageDTO
  �����ⵥ�Ĵ�����󣬼̳�InStorageBaseDTO��������controller -- service -- dao֮�䴫��
*/
class AddInStorageDTO : public InStorageBaseDTO
{
	DTO_INIT(AddInStorageDTO, InStorageBaseDTO);
	// create_user  ������id
	DTO_FIELD(UInt64, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("instorage.field.create_user_id");
	}
};

#define INSTORAGEBASEDTO_TO_ADDINSTORAGEDTO(base,add) \
add->contract_id = base->contract_id; \
add->title = base->title; \
add->store_id = base->store_id; \
add->intro = base->intro; \
add->number = base->number; \
add->money = base->money; \
add->into_type = base->into_type; \

/**
 * ��ҳ�������
 */
class InStoragePageDTO : public PageDTO<InStorageDTO::Wrapper>
{
	DTO_INIT(InStoragePageDTO, PageDTO<InStorageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // INSTORAGEDTO_H___H__