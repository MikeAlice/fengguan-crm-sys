#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _SALCONTRACTLIST_DO_
#define _SALCONTRACTLIST_DO_
#include "../DoInclude.h"
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
 * ʾ�����ݿ�ʵ����
 */
class SalContractListDO
{
	// ������ID
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	//// ��ͬID
	//CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);

public:
	SalContractListDO() {
		list_id = 0;
		//contract_id = 0;
	}
};

#endif // !_SALCONTRACTLIST_DO_
