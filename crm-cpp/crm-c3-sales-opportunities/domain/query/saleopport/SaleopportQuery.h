

#ifndef SALEOPPORTQUERY_H__
#define SALEOPPORTQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Saleopport��ѯ����
 */
class SaleopportQuery : public oatpp::DTO
{
	DTO_INIT(SaleopportQuery, DTO);
	DTO_FIELD(String, sale_name);
	DTO_FIELD_INFO(sale_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}


	//�ͻ�����
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id");
	}
	// ����ʱ��
	DTO_FIELD(String, happen_date);
	DTO_FIELD_INFO(happen_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date");
	}

	// Ԥ��ǩ��ʱ��
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date");
	}

	// ���
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.money");
	}
	// ��ǰ�׶�
	DTO_FIELD(String, now_state);
	DTO_FIELD_INFO(now_state) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.status");
	}
	// ����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.intro");
	}
};

/**
 * saleopportPage��ѯ����
 */
class SaleopportPageQuery :public PageQuery 
{
	DTO_INIT(SaleopportPageQuery, PageQuery);

	/*
	DTO_FIELD(String, sale_name);
	DTO_FIELD_INFO(sale_name) {
		info->description = ZH_WORDS_GETTER("saleopport.field.sale_name");
	}
	//�ͻ�����
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("saleopport.field.cus_name");
	}
	*/


	// ����ʱ��
	DTO_FIELD(String, find_date);
	DTO_FIELD_INFO(find_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date");
	}
	// Ԥ��ǩ��ʱ��
	DTO_FIELD(String, bill_date);
	DTO_FIELD_INFO(bill_date) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date");
	}
    // ��ǰ�׶�
	DTO_FIELD(Int32, salestage);
	DTO_FIELD_INFO(salestage) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage");
	}

	/*
	// ���
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("saleopport.field.money");
	}
	// ����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("saleopport.field.intro");
	}
	*/
};
#include OATPP_CODEGEN_END(DTO)
#endif // SaleopportQUERY_H__