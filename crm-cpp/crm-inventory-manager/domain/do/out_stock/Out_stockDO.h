#pragma once
#ifndef _OUT_STOCK_DO_
#define _OUT_STOCK_DO_
#include "../DoInclude.h"

/**
 * ���ⵥ���ݿ�ʵ����
 */
class Out_stockDO
{
	// ���ⵥid
	CC_SYNTHESIZE(uint16_t, out_id, Out_id);
	// �ֿ���
	CC_SYNTHESIZE(uint16_t, store_id, Store_id);
	// ���ۺ�ͬ���
	CC_SYNTHESIZE(uint16_t, contract_id, Contract_id);
	// ��������
	CC_SYNTHESIZE(string, title, Title);
	// ���
	CC_SYNTHESIZE(double, money, Money);
	// ����
	CC_SYNTHESIZE(uint16_t, number, Number);
	// ��������
	CC_SYNTHESIZE(string, intro, Intro);
	// ����״̬��1=�ѳ��⣬0=δ����
	CC_SYNTHESIZE(uint16_t, status, Status);
	// �������Ա
	CC_SYNTHESIZE(uint16_t, out_user_id, Out_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, out_time, Out_time);
	// ��������
	CC_SYNTHESIZE(string, out_type, Out_type);
	// ������
	CC_SYNTHESIZE(uint16_t, create_user_id, Create_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);


public:
	Out_stockDO() {
		out_id = 0;
		store_id = 0;
		contract_id = 0;
		title = "";
		money = 0.00;
		number = 0;
		intro = "";
		status = -1;
		out_user_id = 0;
		out_time = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
	}
};
/**
 * ��ѯ��ҳ�����б�
 */
class Out_StockPagDO
{
	//��Ӧ���ⵥ��
	CC_SYNTHESIZE(int32_t, out_stock_id, Out_Stock_Id);
	//��������
	CC_SYNTHESIZE(int32_t, number, Number);
	//����״̬
	CC_SYNTHESIZE(int32_t, status, Status);
	//����ʱ��
	CC_SYNTHESIZE(string, out_time, Out_Time);
	//�ֿ�����
	CC_SYNTHESIZE(string, store_name, Store_Name);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_name, Supplier_Name);
	// ������Ա
	CC_SYNTHESIZE(string, out_stock_person, Out_Stock_Person);
	//������
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//��������
	CC_SYNTHESIZE(string, out_type, Out_Type);
	//��Ӧ���ⵥ
	CC_SYNTHESIZE(string, out_stock_order, Out_Stock_Order);

public:
	Out_StockPagDO() {
		out_stock_id = 0;
		number = 0;
		status = 0;
		out_time = "";
		remarks = "";
		supplier_name = "";
		out_stock_person = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
		out_stock_order = "";
	}
};
/**
 * ��ѯ���ⵥ��ϸ
 */
class Out_StocDetailDO {
	//��Ӧ���ⵥ��
	CC_SYNTHESIZE(int32_t, out_stock_id, Out_Stock_Id);
	//�ֿ�����
	CC_SYNTHESIZE(string, store_name, Store_Name);
	//��Ʒ���
	CC_SYNTHESIZE(uint64_t, goods_id, Goods_Id);
	//SKUID
	CC_SYNTHESIZE(uint64_t, sku_id, Sku_Id);
	//��Ʒ����
	CC_SYNTHESIZE(string, goods_name, Goods_Name);
	//SKU����
	CC_SYNTHESIZE(string, sku_name, Sku_Name);
	//��������
	CC_SYNTHESIZE(int32_t, number, Number);
	//����ʱ��
	CC_SYNTHESIZE(string, out_time, Out_Time);
	//��Ʒ����
	CC_SYNTHESIZE(string, category_name, Category_Name);
	//��Ӧ���ⵥ
	CC_SYNTHESIZE(string, out_stock_order, Out_Stock_Order);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// ��Ӧ��
	CC_SYNTHESIZE(string, supplier_name, Supplier_Name);
public:
	Out_StocDetailDO() {
		out_stock_id = 0;
		store_name = "";
		goods_id = 0;
		sku_id = 0;
		goods_name = "";
		sku_name = "";
		category_name = "";
		out_stock_order = "";
		number = 0;
		out_time = "";
		remarks = "";
		supplier_name = "";
	}

};
/**
 * ��ӳ��ⵥ
 */
class AddOut_StockDO
{
	//��������
	CC_SYNTHESIZE(int32_t, number, Number);
	//����״̬
	CC_SYNTHESIZE(int32_t, status, Status);
	//����ʱ��
	CC_SYNTHESIZE(string, out_time, Out_Time);
	//�ֿ�����
	CC_SYNTHESIZE(string, store_name, Store_Name);
	// ��ע
	//CC_SYNTHESIZE(string, remarks, Remarks);
	// ��Ӧ��
	//CC_SYNTHESIZE(string, supplier_name, Supplier_Name);
	// ������Ա
	CC_SYNTHESIZE(string, out_stock_person, Out_Stock_Person);
	//������
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//��������
	CC_SYNTHESIZE(string, out_type, Out_Type);
	//��Ӧ���ⵥ
	//CC_SYNTHESIZE(string, out_stock_order, Out_Stock_Order);
public:
	AddOut_StockDO() {
		number = 0;
		status = 0;
		out_time = "";
		//remarks = "";
		//supplier_name = "";
		out_stock_person = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
		//out_stock_order = "";
	}

};
#endif // !_OUT_STOCK_DO_