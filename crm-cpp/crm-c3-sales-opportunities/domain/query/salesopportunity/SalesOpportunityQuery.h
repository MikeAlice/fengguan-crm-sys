#pragma once
#ifndef _SALES_OPPORTUNITY_QUERY_
#define _SALES_OPPORTUNITY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class SalesOpportunityQuery : public PageQuery
{
	DTO_INIT(SalesOpportunityQuery, PageQuery);
	// 销售机会id
	DTO_FIELD(Int16, salesOpportunityId);
	DTO_FIELD_INFO(salesOpportunityId) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id");
	}
	// 客户id
	DTO_FIELD(Int16, customerId);
	DTO_FIELD_INFO(customerId) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id");
	}
	// 联系人id
	DTO_FIELD(Int16, linkmanId);
	DTO_FIELD_INFO(linkmanId) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_id");
	}
	// 发现时间
	DTO_FIELD(String, findDate);
	DTO_FIELD_INFO(findDate) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date");
	}
	// 预计签单时间
	DTO_FIELD(String, billDate);
	DTO_FIELD_INFO(billDate) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date");
	}
	// 谈判状态
	DTO_FIELD(Int16, salestage);
	DTO_FIELD_INFO(salestage) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage");
	}
	// 预计金额
	DTO_FIELD(Float64, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.money");
	}
	// 预计可能性成功率
	DTO_FIELD(Int16, successRate);
	DTO_FIELD_INFO(successRate) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.success_rate");
	}
	// 用户id
	DTO_FIELD(Int16, userId);
	DTO_FIELD_INFO(userId) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.userID");
	}
	// 主题
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}
	// 简介
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.intro");
	}
	// 状态
	DTO_FIELD(Int16, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.status");
	}
	// 创建用户id
	DTO_FIELD(Int16, createUserId);
	DTO_FIELD_INFO(createUserId) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.create_user_id");
	}
	// 创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.create_time");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SALES_OPPORTUNITY_QUERY_