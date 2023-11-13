

#ifndef SALEOPPORTQUERY_H__
#define SALEOPPORTQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Saleopport查询对象
 */
class SaleopportQuery : public oatpp::DTO
{
	DTO_INIT(SaleopportQuery, DTO);
	DTO_FIELD(String, sale_name);
	DTO_FIELD_INFO(sale_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}


	//客户名称
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
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

/**
 * saleopportPage查询对象
 */
class SaleopportPageQuery :public PageQuery 
{
	DTO_INIT(SaleopportPageQuery, PageQuery);

	/*
	DTO_FIELD(String, sale_name);
	DTO_FIELD_INFO(sale_name) {
		info->description = ZH_WORDS_GETTER("saleopport.field.sale_name");
	}
	//客户名称
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("saleopport.field.cus_name");
	}
	*/


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
    // 当前阶段
	DTO_FIELD(Int32, salestage);
	DTO_FIELD_INFO(salestage) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage");
	}

	/*
	// 金额
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("saleopport.field.money");
	}
	// 需求
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("saleopport.field.intro");
	}
	*/
};
#include OATPP_CODEGEN_END(DTO)
#endif // SaleopportQUERY_H__