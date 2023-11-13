#pragma once
#ifndef _PAYRECORDS_DTO_
#define _PAYRECORDS_DTO_

#include "../../GlobalInclude.h"
//#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�������¼��Ϣ�������
 */

class PayrecordsDTO : public oatpp::DTO
{
	DTO_INIT(PayrecordsDTO, DTO);
	// �����¼id
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("pay.field.record_id");
	}
	// ����ƻ�id
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("pay.field.plan_id");
	}
	// ��ͬid
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("pay.field.contract_id");
	}
	// ��Ӧ��id
	DTO_FIELD(UInt64, supplier_id);
	DTO_FIELD_INFO(supplier_id) {
		info->description = ZH_WORDS_GETTER("pay.field.supplier_id");
	}
	// ��Ӧ������
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("pay.field.supplier_name");
	}
	// �ɹ���ͬ����
	DTO_FIELD(String, contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("pay.field.contract_name");
	}
	// ����id
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("pay.field.bank_id");
	}
	// ����ʱ��
	DTO_FIELD(String, pay_date);
	DTO_FIELD_INFO(pay_date) {
		info->description = ZH_WORDS_GETTER("pay.field.pay_date");
	}
	// ���
	DTO_FIELD(UInt64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("pay.field.money");
	}
	// ȥ��
	DTO_FIELD(UInt64, zero_money);
	DTO_FIELD_INFO(zero_money) {
		info->description = ZH_WORDS_GETTER("pay.field.zero_money");
	}
	// �ڴ�
	DTO_FIELD(UInt64, stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("pay.field.stages");
	}
	// ��ע
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("pay.field.intro");
	}
	// ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("pay.field.create_time");
	}

	// ������
	DTO_FIELD(UInt64, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("pay.field.create_user_id");
	}
};

/**
 * ����һ�������¼��Ϣ�б��ҳ�������
 */
class PayrecordsPageDTO : public PageDTO<PayrecordsDTO::Wrapper>
{
	DTO_INIT(PayrecordsPageDTO, PageDTO<PayrecordsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAYRECORDSDTO_H_