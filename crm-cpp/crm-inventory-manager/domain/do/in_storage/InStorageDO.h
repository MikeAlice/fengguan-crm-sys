#pragma once
#ifndef INSTORAGEDO_H_
#define INSTORAGEDO_H_

#include "../DoInclude.h"

class InStorageDO3 {
public:
	// ����
	CC_SYNTHESIZE(string, number, Number);
	//��Ʒid
	CC_SYNTHESIZE(uint64_t, goods_id, Goods_id);
public:
	InStorageDO3() {
		number = "";
		goods_id = 0;
	}
};

class InStorageDO2 {
public:
	// ����
	CC_SYNTHESIZE(uint64_t, id, Id);
	//// �����
	CC_SYNTHESIZE(string, into_user_id, Into_user_id);
public:
	InStorageDO2() {
		id = 0;
		into_user_id = "";
	}
};

class InStorageDO {
public:
	// ���״̬
	CC_SYNTHESIZE(uint64_t, status, STatus);
	// ����
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��ͬ���
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// ����
	CC_SYNTHESIZE(string, title, Title);
	// �ֿ���
	CC_SYNTHESIZE(uint64_t, store_id, Store_id);
	// �����
	CC_SYNTHESIZE(string, into_user_name, Into_user_name);
	// ����˱��
	CC_SYNTHESIZE(uint64_t, into_user_id, Into_user_id);
	// ������
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// �����˱��
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// ��ע
	CC_SYNTHESIZE(string, intro, Intro);
	// ����
	CC_SYNTHESIZE(uint64_t, number, Number);
	// ���
	CC_SYNTHESIZE(double, money, Money);
	// ���ʱ��
	CC_SYNTHESIZE(string, into_time, Into_time);
	// �������
	CC_SYNTHESIZE(string, into_type, Into_type);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	InStorageDO() {
		id = 0;
		contract_id = 0;
		title = "";
		store_id = 0;
		into_user_id = 0;
		create_user_id = 0;
		intro = "";
		status = -1;
		number = 0;
		money = 0;
		into_time = "1000-01-01 00:00:00";
		into_type = "";
		create_time = "1000-01-01 00:00:00";
	}
};

#endif // !INSTORAGEDO_H_
