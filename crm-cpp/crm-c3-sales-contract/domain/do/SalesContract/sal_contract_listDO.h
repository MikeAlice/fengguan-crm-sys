#pragma once
#ifndef _SAL_CONTRACT_LIST_DO_H_
#define _SAL_CONTRACT_LIST_DO_H_
#include "../DoInclude.h"

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
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	CC_SYNTHESIZE(uint64_t, list_id, List_id);

	//// ��ͬID
	//CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);

public:
	SalContractListDO() {
		list_id = 0;
		//contract_id = 0;
	}
};

#endif // !_SAL_CONTRACT_LIST_DO_H_
