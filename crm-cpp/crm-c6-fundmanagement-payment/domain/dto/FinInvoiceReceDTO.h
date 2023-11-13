#pragma once
#ifndef _FININVOICERECE_DTO_
#define _FININVOICERECE_DTO_

#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class FinInvoiceReceDTO : public oatpp::DTO 
{
	DTO_INIT(FinInvoiceReceDTO, DTO);
	//关联采购号
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.contract_id");
		info->required = true;
	}
	//供应商号
	DTO_FIELD(UInt64, supplier_id);
	DTO_FIELD_INFO(supplier_id) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_id");
		info->required = true;
	}
	//关联采购名称
	DTO_FIELD(String, contract_name);
	DTO_FIELD_INFO(contract_name) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name");
		info->required = false;
	}
	//供应商名称
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name");
		info->required = false;
	}
	//金额
	DTO_FIELD(UInt64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.money");
		info->required = true;
	}
	//收票时间
	DTO_FIELD(String, rece_date);
	DTO_FIELD_INFO(rece_date) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date");
		info->required = false;
	}
	//期次
	DTO_FIELD(UInt64, stages);
	DTO_FIELD_INFO(stages) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.stages");
		info->required = true;
	}
	//发票内容
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.name");
		info->required = true;
	}
	//发票编号
	DTO_FIELD(String, invoice_no);
	DTO_FIELD_INFO(invoice_no) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.invoice_no");
		info->required = true;
	}
	//备注
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.intro");
		info->required = false;
	}
	//创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.creat_time");
		info->required = false;
	}
	DTO_FIELD(UInt64, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("fin_invoice_rece.field.create_user_id");
		info->required = false;
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif
