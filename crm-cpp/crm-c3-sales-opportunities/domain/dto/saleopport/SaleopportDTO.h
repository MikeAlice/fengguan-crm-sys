#pragma once
#ifndef SALEOPPORTDTO_H__
#define SALEOPPORTDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Saleopport���ۻ����б������
 */
class SaleopportDTO : public oatpp::DTO
{
	DTO_INIT(SaleopportDTO, DTO);
	
	//���ۻ���ID
	DTO_FIELD(Int32, chance_id);
	DTO_FIELD_INFO(chance_id) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id");
	}
	// ���ۻ�������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}
	//�ͻ�ID
	DTO_FIELD(Int32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id");
	}
	//�ͻ�����
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_name");
	}
	//��ϵ������
	DTO_FIELD(String, linkman_name);
	DTO_FIELD_INFO(linkman_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_name");
	}
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
	// ���
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.money");
	}
	// ��ǰ�׶�
	DTO_FIELD(Int32, salestage);
	DTO_FIELD_INFO(salestage) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage");
	}
	// ����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.intro");
	}
	// ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.create_time");
	}
	
};
/**
 * saleopportPgae�������
 */
class SaleopportPgaeDTO : public PageDTO<SaleopportDTO::Wrapper>
{
	DTO_INIT(SaleopportPgaeDTO, PageDTO<SaleopportDTO::Wrapper>);
};
/**
 * AddSaleopport�������
 */
//������ۻ���
class AddSaleopportDTO : public oatpp::DTO
{
	DTO_INIT(AddSaleopportDTO, DTO);

		// ���ۻ�������
	DTO_FIELD(String, sale_name);
	DTO_FIELD_INFO(sale_name) {
		info->description = ZH_WORDS_GETTER("opportunities.field.cst_chance.name");
	}

	//�ͻ�����
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {;
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


#include OATPP_CODEGEN_END(DTO)
#endif // SALEOPPORTDTO_H__