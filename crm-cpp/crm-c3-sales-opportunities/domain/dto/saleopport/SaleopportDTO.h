#pragma once
#ifndef SALEOPPORTDTO_H__
#define SALEOPPORTDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Saleopport销售机会列表传输对象
 */
class SaleopportDTO : public oatpp::DTO
{
	DTO_INIT(SaleopportDTO, DTO);
	
	//销售机会ID
	DTO_FIELD(Int32, chance_id);
	DTO_FIELD_INFO(chance_id) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id");
	}
	// 销售机会主题
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}
	//客户ID
	DTO_FIELD(Int32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id");
	}
	//客户姓名
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_name");
	}
	//联系人姓名
	DTO_FIELD(String, linkman_name);
	DTO_FIELD_INFO(linkman_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_name");
	}
	// 发现时间
	DTO_FIELD(String, find_date);
	DTO_FIELD_INFO(find_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date");
	}
	// 预计签单时间
	DTO_FIELD(String, bill_date);
	DTO_FIELD_INFO(bill_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date");
	}
	// 金额
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.money");
	}
	// 当前阶段
	DTO_FIELD(Int32, salestage);
	DTO_FIELD_INFO(salestage) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage");
	}
	// 需求
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.intro");
	}
	// 创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.create_time");
	}
	
};
/**
 * saleopportPgae传输对象
 */
class SaleopportPgaeDTO : public PageDTO<SaleopportDTO::Wrapper>
{
	DTO_INIT(SaleopportPgaeDTO, PageDTO<SaleopportDTO::Wrapper>);
};
/**
 * AddSaleopport传输对象
 */
//添加销售机会
class AddSaleopportDTO : public oatpp::DTO
{
	DTO_INIT(AddSaleopportDTO, DTO);

		// 销售机会主题
	DTO_FIELD(String, sale_name);
	DTO_FIELD_INFO(sale_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}

	//客户名称
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {;
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id");
	}
	// 发现时间
	DTO_FIELD(String, happen_date);
	DTO_FIELD_INFO(happen_date) {

		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date");
	}

	// 预计签单时间
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date");
	}

		// 金额
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.money");
	}

	// 当前阶段
	DTO_FIELD(String, now_state);
	DTO_FIELD_INFO(now_state) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.status");
	}
		// 需求
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.intro");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // SALEOPPORTDTO_H__