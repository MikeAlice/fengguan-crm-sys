#pragma once
#ifndef _SALESCONTRACTQUERY_H_
#define _SALESCONTRACTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class SalesContractPageQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(SalesContractPageQuery, PageQuery);
	//���ۺ�ͬID
	//API_DTO_FIELD_DEFAULT(Int64, contract_id, ZH_WORDS_GETTER("SalesContract.field.contract_id"));

	//��ͬ����
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("SalesContract.field.title"));
	//�ͻ�ID���ͻ����ƣ�
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));
	//��ͬ���
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("SalesContract.field.money"));
	//�ؿ���
	API_DTO_FIELD_DEFAULT(Float32, back_money, ZH_WORDS_GETTER("SalesContract.field.back_money"));
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

#include OATPP_CODEGEN_END(DTO)

#endif 