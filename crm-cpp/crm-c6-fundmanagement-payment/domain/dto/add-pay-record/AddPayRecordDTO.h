#pragma once

#ifndef _PAYRECORD_DTO_
#define _RECORD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AddPayRecordDTO : public oatpp::DTO
{
	DTO_INIT(AddPayRecordDTO, DTO);
	// 记录编号
	/*	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.record_id");
	}*/

	// 计划编号
	/*	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.plan_id");
	}*/
	// 合同编号
	/*	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.contract_id");
	}*/
	// 供应商名称
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("PayRecord.field.supplier_name");
	}

	// 合同名称
	DTO_FIELD(String, contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("PayRecord.field.contract_name");
	}
	/*	// 供应商编号
	DTO_FIELD(UInt64, supplier_id);
	DTO_FIELD_INFO(supplier_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.supplier_id");
	}*/

	// 银行账户
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.bank_id");
	}
	//付款日期
	DTO_FIELD(String, pay_date);
	DTO_FIELD_INFO(pay_date) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.pay_date");
	}
	//付款金额
	DTO_FIELD(String, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.money");
	}
	//去零金额
	DTO_FIELD(String,zero_money);
	DTO_FIELD_INFO(zero_money) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.zero_money");
	}
	//期次
	DTO_FIELD(UInt64,stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.stages");
	}
	//备注
	DTO_FIELD(String,intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.intro");
	}
	/*	DTO_FIELD(String,create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("addpayrecord.field.create_time");
	}*/
	//创建者ID
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