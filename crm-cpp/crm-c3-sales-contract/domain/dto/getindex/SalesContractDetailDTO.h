#pragma once
#ifndef _SALESCONTRACTDETAILDTO_H_
#define _SALESCONTRACTDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�������ۺ�ͬ����
class SalesContractDetailDTO : public oatpp::DTO
{
	DTO_INIT(SalesContractDetailDTO, DTO);
	//���ۺ�ͬID
	API_DTO_FIELD_DEFAULT(Int64, contract_id, ZH_WORDS_GETTER("SalesContract.field.contract_id"));
	//��������
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("SalesContract.field.title"));
	//��ͬ���
	API_DTO_FIELD_DEFAULT(String, contract_no, ZH_WORDS_GETTER("SalesContract.field.contract_no"));
	//�ͻ�ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));
	//��ϵ��ID
	API_DTO_FIELD_DEFAULT(Int64, linkman_id, ZH_WORDS_GETTER("SalesContract.field.linkman_id"));
	//���ۻ���
	API_DTO_FIELD_DEFAULT(Int64, chance_id, ZH_WORDS_GETTER("SalesContract.field.chance_id"));
	//������վ
	API_DTO_FIELD_DEFAULT(Int64, website_id, ZH_WORDS_GETTER("SalesContract.field.website_id"));
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("SalesContract.field.start_date"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("SalesContract.field.end_date"));
	//�ҷ���ϵ��
	API_DTO_FIELD_DEFAULT(Int64, our_user_id, ZH_WORDS_GETTER("SalesContract.field.our_user_id"));
	//��ͬ���
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("SalesContract.field.money"));
	//��Ʒ���
	API_DTO_FIELD_DEFAULT(Float32, goods_money, ZH_WORDS_GETTER("SalesContract.field.goods_money"));
	//ȥ����
	API_DTO_FIELD_DEFAULT(Float32, zero_money, ZH_WORDS_GETTER("SalesContract.field.zero_money"));
	//�ؿ���
	API_DTO_FIELD_DEFAULT(Float32, back_money, ZH_WORDS_GETTER("SalesContract.field.back_money"));
	//Ƿ����
	API_DTO_FIELD_DEFAULT(Float32, owe_money, ZH_WORDS_GETTER("SalesContract.field.owe_money"));
	//�������
	API_DTO_FIELD_DEFAULT(Float32, deliver_money, ZH_WORDS_GETTER("SalesContract.field.deliver_money"));
	//��Ʊ���
	API_DTO_FIELD_DEFAULT(Float32, invoice_money, ZH_WORDS_GETTER("SalesContract.field.invoice_money"));
	//��������
	API_DTO_FIELD_DEFAULT(Any, intro, ZH_WORDS_GETTER("SalesContract.field.intro"));
	//����״̬ 1=��ʱ����2=ִ�У�3=��ɣ�4=����
	API_DTO_FIELD_DEFAULT(Int8, status, ZH_WORDS_GETTER("SalesContract.field.status"));
	//�ؿ�״̬��1=δ����2=���֣�3=ȫ��
	API_DTO_FIELD_DEFAULT(Int8, back_status, ZH_WORDS_GETTER("SalesContract.field.back_status"));
	//����״̬��-1=����Ҫ��1=��Ҫ��2=¼����ϸ��3=�����⣬4=���֣�5=ȫ��
	API_DTO_FIELD_DEFAULT(Int8, deliver_status, ZH_WORDS_GETTER("SalesContract.field.deliver_status"));
	//��Ʊ״̬�� 0=����Ҫ��1=��Ҫ��2=���֣�3=ȫ��
	API_DTO_FIELD_DEFAULT(Int8, invoice_status, ZH_WORDS_GETTER("SalesContract.field.invoice_status"));
	//�������ͣ�1=�����ӣ�2=����
	API_DTO_FIELD_DEFAULT(Int8, renew_status, ZH_WORDS_GETTER("SalesContract.field.renew_status"));
	//������
	API_DTO_FIELD_DEFAULT(Int64, create_user_id, ZH_WORDS_GETTER("SalesContract.field.create_user_id"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("SalesContract.field.create_time"));
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCONTRACTDETAILDTO
