#pragma once

#ifndef _PAYRECORD_DTO_
#define _RECORD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class AddPayRecordDTO : public oatpp::DTO
{
	DTO_INIT(AddPayRecordDTO, DTO);
	// ��¼���
	/*	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.record_id");
	}*/

	// �ƻ����
	/*	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.plan_id");
	}*/
	// ��ͬ���
	/*	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.contract_id");
	}*/
	// ��Ӧ������
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("PayRecord.field.supplier_name");
	}

	// ��ͬ����
	DTO_FIELD(String, contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("PayRecord.field.contract_name");
	}
	/*	// ��Ӧ�̱��
	DTO_FIELD(UInt64, supplier_id);
	DTO_FIELD_INFO(supplier_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.supplier_id");
	}*/

	// �����˻�
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.bank_id");
	}
	//��������
	DTO_FIELD(String, pay_date);
	DTO_FIELD_INFO(pay_date) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.pay_date");
	}
	//������
	DTO_FIELD(String, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.money");
	}
	//ȥ����
	DTO_FIELD(String,zero_money);
	DTO_FIELD_INFO(zero_money) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.zero_money");
	}
	//�ڴ�
	DTO_FIELD(UInt64,stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.stages");
	}
	//��ע
	DTO_FIELD(String,intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.intro");
	}
	/*	DTO_FIELD(String,create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.create_time");
	}*/
	//������ID
	DTO_FIELD(UInt64,create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.create_user_id");
	}

};


//  class SamplePageDTO : public PageDTO<AddPayRecordDTO::Wrapper>
//{
//	DTO_INIT(SamplePageDTO, PageDTO<AddPayRecordDTO::Wrapper>);
//};


#include OATPP_CODEGEN_END(DTO)
#endif // !RecordDTO