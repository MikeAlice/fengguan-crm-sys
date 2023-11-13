#pragma once
#ifndef FLOWRECORDQUERY_H__
#define FLOWRECORDQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * flowrecord²éÑ¯¶ÔÏó
 */
class FlowrecordPageQuery :public PageQuery {
	DTO_INIT(FlowrecordPageQuery, PageQuery);
	// bank_id
	DTO_FIELD(String, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.bank_id");
	}
	// income
	DTO_FIELD(Float64, income);
	DTO_FIELD_INFO(income) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.income");
	}
	// expenditure
	DTO_FIELD(Float64, expenditure);
	DTO_FIELD_INFO(expenditure) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.expenditure");
	}
	// surplus
	DTO_FIELD(Float64, surplus);
	DTO_FIELD_INFO(surplus) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.surplus");
	}
	// type
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.type");
	}
	//  connect_id
	DTO_FIELD(String, connect_id);
	DTO_FIELD_INFO(connect_id) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.connect_id");
	}
	// create_user
	DTO_FIELD(String, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.create_user");
	}
	// create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("flowrecord.field.create_time");
	}
	//// total_income
	//DTO_FIELD(Int32, total_income);
	//DTO_FIELD_INFO(total_income) {
	//	info->description = ZH_WORDS_GETTER("flowrecord.field.total_income");
	//}
	//// total_expenditure
	//DTO_FIELD(Int32, total_expenditure);
	//DTO_FIELD_INFO(total_expenditure) {
	//	info->description = ZH_WORDS_GETTER("flowrecord.field.total_expenditure");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // FLOWRECORDQUERY_H__