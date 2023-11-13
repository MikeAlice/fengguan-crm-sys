#ifndef _ADDSALESCONTRACTDTO_H_
#define _ADDSALESCONTRACTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 原味的原味包
*（添加销售合同）对象
*/
class AddSalesContractDTO : public oatpp::DTO
{
	DTO_INIT(AddSalesContractDTO, DTO);
	// 合同编号，已获取，不需要用户输入
	DTO_FIELD(String, contract_no);
	DTO_FIELD_INFO(contract_no) {
		info->description = ZH_WORDS_GETTER("contractindex.field.contract_no");
	}
	// 标题
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("contractindex.field.title");
	}
	// 客户名称
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("contractindex.field.customer_name");
	}
	// 客户联系人名称
	DTO_FIELD(String, linkman_name);
	DTO_FIELD_INFO(linkman_name) {
		info->description = ZH_WORDS_GETTER("contractindex.field.linkman_name");
	}
	// 销售机会名称
	DTO_FIELD(String, chance_name);
	DTO_FIELD_INFO(chance_name) {
		info->description = ZH_WORDS_GETTER("contractindex.field.chance_name");
	}
	// 起始日期
	DTO_FIELD(String, start_date);
	DTO_FIELD_INFO(start_date) {
		info->description = ZH_WORDS_GETTER("contractindex.field.start_date");
	}
	// 结束日期
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("contractindex.field.end_date");
	}
	// 合同金额
	DTO_FIELD(Float64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("contractindex.field.money");
	}
	// 介绍
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("contractindex.field.intro");
	}
	// 我方代表名称
	DTO_FIELD(String, our_user_name);
	DTO_FIELD_INFO(our_user_name) {
		info->description = ZH_WORDS_GETTER("contractindex.field.our_user_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif