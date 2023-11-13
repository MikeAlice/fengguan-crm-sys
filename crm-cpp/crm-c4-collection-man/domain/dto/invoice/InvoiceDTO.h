#pragma once
#ifndef _INVOICE_DTO_
#define _INVOICE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class InvoiceDTO : public oatpp::DTO
{
	DTO_INIT(InvoiceDTO, DTO);
	// 编号
	//DTO_FIELD(UInt64, record_id);
	//DTO_FIELD_INFO(record_id) {
	//	info->description = ZH_WORDS_GETTER("Invoice.field.record_id");
	//}
	//合同id
//	DTO_FIELD(UInt64, contract_id);
//	DTO_FIELD_INFO(contract_id) {
//		info->description = ZH_WORDS_GETTER("Invoice.field.contract_id");
//	}
	// 合同名字
	DTO_FIELD(String,contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("Invoice.field.contract_name");
	}
	//DTO_FIELD(UInt64, customer_id);
	//DTO_FIELD_INFO(customer_id) {
		//info->description = ZH_WORDS_GETTER("Invoice.field.customer_id");
	//}
	//顾客名字
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("Invoice.field.customer_name");
	}
	// 金额
	DTO_FIELD(Int64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("Invoice.field.money");
	}
	// 开票日期
	DTO_FIELD(String, pay_date);
	DTO_FIELD_INFO(pay_date) {
		info->description = ZH_WORDS_GETTER("Invoice.field.pay_date");
	}
	//开票期次
	DTO_FIELD(Int64, stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("Invoice.field.stages");
	}
	//发票编号
	DTO_FIELD(String, invoice_no);
	DTO_FIELD_INFO(invoice_no) {
		info->description = ZH_WORDS_GETTER("Invoice.field.invoice_no");
	}
	//发票内容
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("Invoice.field.name");
	}
	//开票类型bus_type
	//DTO_FIELD(String, bus_type);
	//DTO_FIELD_INFO(bus_type) {
	//info->description = ZH_WORDS_GETTER("Invoice.field.bus_type");
	//}
	//备注
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("Invoice.field.intro");
	}
	//创建时间
	//DTO_FIELD(String, create_time);
	//DTO_FIELD_INFO(create_time) {
		//info->description = ZH_WORDS_GETTER("Invoice.field.create_time");
	//}
	//创建人id
	DTO_FIELD(Int64, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("Invoice.field.create_user_id");
	}
};

/**
 * 示例分页传输对象
 */
class InvoicePageDTO : public PageDTO<InvoiceDTO::Wrapper>
{
	DTO_INIT(InvoicePageDTO, PageDTO<InvoiceDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_