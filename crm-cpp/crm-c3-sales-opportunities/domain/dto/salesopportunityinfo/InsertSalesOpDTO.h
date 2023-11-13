#pragma once
#ifndef _INSERTSALESOPDTO_H_
#define _INSERTSALESOPDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 插入销售机会传输对象
*/
class InsertSalesOpDTO : public oatpp::DTO {

	DTO_INIT(InsertSalesOpDTO, DTO);

	// 销售机会id
	API_DTO_FIELD_DEFAULT(Int16, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
	// 客户id
	API_DTO_FIELD_DEFAULT(Int16, customer_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"));
	// 联系人id
	API_DTO_FIELD_DEFAULT(String, linkman_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_id"));
	// 定义销售机会发现日期
	API_DTO_FIELD_DEFAULT(String, find_date, ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"));
	// 定义销售机会预计签单时间
	API_DTO_FIELD_DEFAULT(String, bill_date, ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"));
	// 定义销售机会谈判状态
	API_DTO_FIELD_DEFAULT(Int8, salestage, ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"));
	// 定义销售机会预计金额
	API_DTO_FIELD_DEFAULT(Float64, money, ZH_WORDS_GETTER("opportunities.field.cst_chance.money"));
	// 预计可能性成功率
	API_DTO_FIELD_DEFAULT(Int8, success_rate, ZH_WORDS_GETTER("opportunities.field.cst_chance.success_rate"));
	// userID
	API_DTO_FIELD_DEFAULT(Int16, userID, ZH_WORDS_GETTER("opportunities.field.cst_chance.userID"));
	// 定义销售机会主题
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("opportunities.field.cst_chance.name"));
	// intro
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("opportunities.field.cst_chance.intro"));
	// status
	API_DTO_FIELD_DEFAULT(Int8, status, ZH_WORDS_GETTER("opportunities.field.cst_chance.status"));
	// create_user_id
	API_DTO_FIELD_DEFAULT(Int16, create_user_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.create_user_id"));
	// create_time
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("opportunities.field.cst_chance.create_time"));
};

#include OATPP_CODEGEN_END(DTO)

#endif