#pragma once
#ifndef _SAL_CONTRACT_LIST_DO_H_
#define _SAL_CONTRACT_LIST_DO_H_
#include "DoInclude.h"

//销售合同明细表'sal_contract_list'
/*
CREATE TABLE `sal_contract_list` (
  `list_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '订单项ID',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同ID',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '商品名称',
  `sku_id` int(11) NOT NULL DEFAULT '0' COMMENT 'skuID',
  `sku_name` varchar(50) NOT NULL DEFAULT '' COMMENT 'sku名称',
  `sale_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '商品价格',
  `cost_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '商品成本价',
  `num` int(11) NOT NULL DEFAULT '0' COMMENT '购买数量',
  `out_num` int(11) NOT NULL DEFAULT '0' COMMENT '出库数量',
  `owe_num` int(11) NOT NULL DEFAULT '0' COMMENT '未出库数量',
  `owe_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '未出库金额',
  `adjust_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '调整金额',
  `goods_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '商品总价',
  `goods_picture` int(11) NOT NULL DEFAULT '0' COMMENT '商品图片',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '备注',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime NOT NULL,
  PRIMARY KEY (`list_id`),
  KEY `UK_ns_order_goods_goods_id` (`goods_id`),
  KEY `UK_ns_order_goods_order_id` (`contract_id`),
  KEY `UK_ns_order_goods_sku_id` (`sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='销售合同明细表';
*/

/**
 * 销售合同明细表数据库实体类
 */
class SalContractListDO
{
	// 订单项ID
	CC_SYNTHESIZE(uint64_t, list_id, List_id);
	// 合同ID
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// 商品ID
	CC_SYNTHESIZE(uint64_t, goods_id, Goods_id);
	// 商品名称
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	// skuID
	CC_SYNTHESIZE(uint64_t, sku_id, Sku_id);
	// sku名称
	CC_SYNTHESIZE(string, sku_name, Sku_name);
	// 商品价格
	CC_SYNTHESIZE(double, sale_price, Sale_price);
	// 商品成本价
	CC_SYNTHESIZE(double, cost_price, Cost_price);
	// 购买数量
	CC_SYNTHESIZE(uint64_t, num, Num);
	// 出库数量
	CC_SYNTHESIZE(uint64_t, out_num, Out_num);
	// 未出库数量
	CC_SYNTHESIZE(uint64_t, owe_num, Owe_num);
	// 未出库金额
	CC_SYNTHESIZE(double, owe_money, Owe_money);
	// 调整金额
	CC_SYNTHESIZE(double, adjust_money, Odjust_money);
	// 商品总价
	CC_SYNTHESIZE(double, goods_money, Goods_money);
	// 商品图片
	CC_SYNTHESIZE(uint64_t, goods_picture, Goods_picture);
	// 备注
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
