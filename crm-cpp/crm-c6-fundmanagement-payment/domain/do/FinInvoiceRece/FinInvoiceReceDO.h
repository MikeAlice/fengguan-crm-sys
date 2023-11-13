#pragma once
#ifndef _FININVOICERECE_DO_
#define _FININVOICERECE_DO_

#include "../../../Macros.h"
#include<string>

using namespace std;

class FinInvoiceReceDO {
	//��¼���
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	//�����ɹ���
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	//��Ӧ�̺�
	CC_SYNTHESIZE(uint64_t, supplier_id, Supplier_id);
	//�����ɹ���
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	//��Ӧ����
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	//���
	CC_SYNTHESIZE(uint64_t, money, Money);
	//��Ʊʱ��
	CC_SYNTHESIZE(string, rece_date, Rece_date);
	//�ڴ�
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	//��Ʊ����
	CC_SYNTHESIZE(string, name, Name);
	//��Ʊ���
	CC_SYNTHESIZE(string, invoice_no, Invoice_no);
	//��ע
	CC_SYNTHESIZE(string, intro, Intro);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//������id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
public:
	FinInvoiceReceDO() {
		record_id = 0;
		contract_id = 0;
		supplier_id = 0;
		contract_name = "";
		supplier_name = "";
		money = 0;
		rece_date = "";
		stages = 0;
		name = "";
		invoice_no = "";
		intro = "";
		create_time = "";
		create_user_id = 0;
	}
};


#endif
