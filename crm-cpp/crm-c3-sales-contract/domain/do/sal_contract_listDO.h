#pragma once
#ifndef _SAL_CONTRACT_LIST_DO_H_
#define _SAL_CONTRACT_LIST_DO_H_
#include "DoInclude.h"

//���ۺ�ͬ��ϸ��'sal_contract_list'
/*
CREATE TABLE `sal_contract_list` (
  `list_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '��ͬID',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '��ƷID',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '��Ʒ����',
  `sku_id` int(11) NOT NULL DEFAULT '0' COMMENT 'skuID',
  `sku_name` varchar(50) NOT NULL DEFAULT '' COMMENT 'sku����',
  `sale_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '��Ʒ�۸�',
  `cost_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '��Ʒ�ɱ���',
  `num` int(11) NOT NULL DEFAULT '0' COMMENT '��������',
  `out_num` int(11) NOT NULL DEFAULT '0' COMMENT '��������',
  `owe_num` int(11) NOT NULL DEFAULT '0' COMMENT 'δ��������',
  `owe_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT 'δ������',
  `adjust_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '�������',
  `goods_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '��Ʒ�ܼ�',
  `goods_picture` int(11) NOT NULL DEFAULT '0' COMMENT '��ƷͼƬ',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '��ע',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime NOT NULL,
  PRIMARY KEY (`list_id`),
  KEY `UK_ns_order_goods_goods_id` (`goods_id`),
  KEY `UK_ns_order_goods_order_id` (`contract_id`),
  KEY `UK_ns_order_goods_sku_id` (`sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='���ۺ�ͬ��ϸ��';
*/

/**
 * ���ۺ�ͬ��ϸ�����ݿ�ʵ����
 */
class SalContractListDO
{
	// ������ID
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	// ��ͬID
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// ��ƷID
	CC_SYNTHESIZE(uint64_t, goods_id, Goods_id);
	// ��Ʒ����
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	// skuID
	CC_SYNTHESIZE(uint64_t, sku_id, Sku_id);
	// sku����
	CC_SYNTHESIZE(string, sku_name, Sku_name);
	// ��Ʒ�۸�
	CC_SYNTHESIZE(double, sale_price, Sale_price);
	// ��Ʒ�ɱ���
	CC_SYNTHESIZE(double, cost_price, Cost_price);
	// ��������
	CC_SYNTHESIZE(uint64_t, num, Num);
	// ��������
	CC_SYNTHESIZE(uint64_t, out_num, Out_num);
	// δ��������
	CC_SYNTHESIZE(uint64_t, owe_num, Owe_num);
	// δ������
	CC_SYNTHESIZE(double, owe_money, Owe_money);
	// �������
	CC_SYNTHESIZE(double, adjust_money, Odjust_money);
	// ��Ʒ�ܼ�
	CC_SYNTHESIZE(double, goods_money, Goods_money);
	// ��ƷͼƬ
	CC_SYNTHESIZE(uint64_t, goods_picture, Goods_picture);
	// ��ע
	CC_SYNTHESIZE(string, remarks, Remarks);
	// create_user_id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// create_time
	CC_SYNTHESIZE(string, create_time, Create_time);

public:
	SalContractListDO() {
		list_id = 0;
		contract_id = 0;
		goods_id = 0;
		goods_name = "";
		sku_id = 0;
		sku_name = "";
		sale_price = 0.00;
		cost_price = 0.00;
		num = 0;
		out_num = 0;
		owe_num = 0;
		owe_money = 0.00;
		adjust_money = 0.00;
		goods_money = 0.00;
		goods_picture = 0;
		remarks = "";
		create_user_id = 0;
		create_time = "";
	}
};

#endif // !_SAL_CONTRACT_LIST_DO_H_
