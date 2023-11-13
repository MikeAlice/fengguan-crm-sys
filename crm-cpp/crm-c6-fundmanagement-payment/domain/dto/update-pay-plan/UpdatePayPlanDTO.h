#pragma once

#ifndef _PAYRECORD_DTO_
#define _RECORD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class UpdatePayPlanDTO : public oatpp::DTO
{
	DTO_INIT(UpdatePayPlanDTO, DTO);
	// ��Ӧ������
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("PayRecord.field.plan_id");
	}

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


	//�ƻ���������
	DTO_FIELD(String, plan_date);
	DTO_FIELD_INFO(plan_date) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.plan_date");
	}

	//������
	DTO_FIELD(String, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.money");
	}


	//�ڴ�
	DTO_FIELD(UInt64, stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.stages");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !RecordDTO