#pragma once
#ifndef _SALESCONTRACTLISTDTO_H_
#define _SALESCONTRACTLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�������ۺ�ͬ����
class SalesContractListDTO : public oatpp::DTO
{
	DTO_INIT(SalesContractListDTO, DTO);
	//���ۺ�ͬID
	API_DTO_FIELD_DEFAULT(Int64, contract_id, ZH_WORDS_GETTER("SalesContract.field.contract_id"));
	//���ۺ�ͬ���
	API_DTO_FIELD_DEFAULT(String, contract_no, ZH_WORDS_GETTER("SalesContract.field.contract_id"));
	//��ͬ����
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("SalesContract.field.title"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("SalesContract.field.create_time"));
	//�ͻ�ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));
	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, customer_name, ZH_WORDS_GETTER("SalesContract.field.customer_name"));
	//��ϵ������
	API_DTO_FIELD_DEFAULT(String, linkman_name, ZH_WORDS_GETTER("SalesContract.field.linkman_name"));
	//��ͬ���
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("SalesContract.field.money"));
	//�ؿ���
	API_DTO_FIELD_DEFAULT(Float32, back_money, ZH_WORDS_GETTER("SalesContract.field.back_money"));
	//ȥ����
	API_DTO_FIELD_DEFAULT(Float32, zero_money, ZH_WORDS_GETTER("SalesContract.field.zero_money"));
	//Ƿ����
	API_DTO_FIELD_DEFAULT(Float32, owe_money, ZH_WORDS_GETTER("SalesContract.field.owe_money"));
	//�ؿ�״̬��1=δ����2=���֣�3=ȫ��
	API_DTO_FIELD_DEFAULT(Int8, back_status, ZH_WORDS_GETTER("SalesContract.field.back_status"));
	//��Ʊ���
	API_DTO_FIELD_DEFAULT(Float32, invoice_money, ZH_WORDS_GETTER("SalesContract.field.invoice_money"));
	//��Ʊ״̬�� 0=����Ҫ��1=��Ҫ��2=���֣�3=ȫ��
	API_DTO_FIELD_DEFAULT(Int8, invoice_status, ZH_WORDS_GETTER("SalesContract.field.invoice_status"));
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("SalesContract.field.start_date"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("SalesContract.field.end_date"));
	//��ͬ״̬ 1=��ʱ����2=ִ�У�3=��ɣ�4=����
	API_DTO_FIELD_DEFAULT(Int8, status, ZH_WORDS_GETTER("SalesContract.field.status"));
	//����״̬��-1=����Ҫ��1=��Ҫ��2=¼����ϸ��3=�����⣬4=���֣�5=ȫ��
	API_DTO_FIELD_DEFAULT(Int8, deliver_status, ZH_WORDS_GETTER("SalesContract.field.deliver_status"));
};

//����һ���û���Ϣ��ҳ�������
class SalesContractListPageDTO : public PageDTO<SalesContractListDTO::Wrapper>
{
	DTO_INIT(SalesContractListPageDTO, PageDTO<SalesContractListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCONTRACTDTO
