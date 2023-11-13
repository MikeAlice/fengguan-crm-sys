#pragma once


#ifndef _COLLECTIONRECORD_DTO_
#define _COLLECTIONRECORD_DTO_

#include "../../GlobalInclude.h"
//#include"../../query/collectionrecord/CollectionRecordQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class CollectionRecordDTO : public oatpp::DTO 
{

	DTO_INIT(CollectionRecordDTO, DTO);

	// �ؿ���
	DTO_FIELD(UInt32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.record_id");
	}
	// �ͻ�����
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.customer_name");
	}
	// ��ͬ����
	DTO_FIELD(UInt32, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.contract_id");
	}

	// �ؿ�����
	DTO_FIELD(String, back_date);
	DTO_FIELD_INFO(back_date) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.back_date");
	}
	// �ڴ�
	DTO_FIELD(UInt32, stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.stages");
	}
	// �ؿ��˺�
	DTO_FIELD(UInt32, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.bank_id");
	}

	// ���
	DTO_FIELD(UInt32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.money");
	}

	//// ������
	DTO_FIELD(UInt64, create_user_id);
	DTO_FIELD_INFO(create_user_id){
		info->description = ZH_WORDS_GETTER("collectionRecord.field.create_user_id");
	}
	// ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.create_time");
	}








};

class CollectionRecordPageDTO : public PageDTO<CollectionRecordDTO::Wrapper>
{
	DTO_INIT(CollectionRecordPageDTO, PageDTO<CollectionRecordDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif
