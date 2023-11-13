#pragma once
#ifndef _INVOICE_DO_
#define _INVOICE_DO_
#include "Macros.h"
#include <string>
#include <list>
using namespace std;

/**
 * ʾ�����ݿ�ʵ����
 */
class InvoiceDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// ��ͬid
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// ��ͬ����
	CC_SYNTHESIZE(string, contract_name ,Contract_name);
	//�˿�id
	CC_SYNTHESIZE(uint64_t, customer_id, Customer_id);
	// �˿�����
	CC_SYNTHESIZE(string,customer_name, Customer_name);
	//���
	CC_SYNTHESIZE(uint64_t, money, Money);
	//��Ʊ����
	CC_SYNTHESIZE(string,pay_date, Pay_date);
	//��Ʊ�ڴ�
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	//��Ʊ���
	CC_SYNTHESIZE(string, invoice_no, Invoice_no);
	//������Ա
	CC_SYNTHESIZE(string,name ,Name );
	//��Ʊ����
	CC_SYNTHESIZE(string,bus_type ,Bus_type );
	//��ע
	CC_SYNTHESIZE(string,intro ,Intro );
	//����ʱ��
	CC_SYNTHESIZE(string,create_time ,Create_time);
	//������id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);

public:
	InvoiceDO() {
		record_id = 0;
		contract_id = 1;
		contract_name = "";
		customer_id = 0;
		customer_name = "";
		money = 0;
		pay_date = "";
		stages = 0;
		invoice_no = "";
		name = "";
		bus_type = "";
		intro = "";
		create_time = "";
		create_user_id = 0;
	}
};

#endif 