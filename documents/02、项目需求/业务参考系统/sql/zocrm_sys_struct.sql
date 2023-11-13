-- ----------------------------
--  Create database and change database
-- ----------------------------
DROP DATABASE IF EXISTS `zocrm_sys`;
CREATE DATABASE `zocrm_sys` CHARACTER SET 'utf8mb4' COLLATE 'utf8mb4_0900_ai_ci';
USE `zocrm_sys`;

SET FOREIGN_KEY_CHECKS=0;

CREATE TABLE `cst_chance` (
  `chance_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `customer_id` int(16) NOT NULL DEFAULT '0',
  `linkman_id` varchar(256) NOT NULL DEFAULT '0',
  `find_date` date DEFAULT NULL COMMENT '发现时间',
  `bill_date` date DEFAULT NULL COMMENT '预计签单时间',
  `salestage` int(4) NOT NULL DEFAULT '0' COMMENT '谈判状态',
  `money` decimal(20,2) NOT NULL DEFAULT '0.00' COMMENT '预计金额',
  `success_rate` int(2) NOT NULL DEFAULT '0' COMMENT '预计可能性成功率',
  `userID` int(16) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '主题',
  `intro` varchar(256) NOT NULL DEFAULT '',
  `status` smallint(1) NOT NULL DEFAULT '1',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime NOT NULL,
  PRIMARY KEY (`chance_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='销售机会';

CREATE TABLE `cst_customer` (
  `customer_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL DEFAULT '' COMMENT '客户名称',
  `customer_no` varchar(64) NOT NULL DEFAULT '' COMMENT '客户编号',
  `create_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '创建人员',
  `owner_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '归属人员',
  `create_time` datetime DEFAULT NULL,
  `next_time` datetime DEFAULT NULL COMMENT '下次沟通时间',
  `conn_time` datetime DEFAULT NULL COMMENT '最近联系时间',
  `conn_body` varchar(1024) NOT NULL DEFAULT '' COMMENT '最近沟通内容',
  `linkman` varchar(250) DEFAULT '' COMMENT '客户代表',
  `source` varchar(250) DEFAULT '' COMMENT '客户来源',
  `grade` varchar(250) DEFAULT '' COMMENT '客户等级',
  `industry` varchar(250) DEFAULT '' COMMENT '客户行业',
  `mobile` varchar(250) DEFAULT '' COMMENT '联系手机',
  `tel` varchar(250) DEFAULT '' COMMENT '联系电话',
  `address` varchar(250) DEFAULT '' COMMENT '联系地址',
  `intro` varchar(250) DEFAULT '' COMMENT '客户介绍',
  `needs` varchar(250) DEFAULT '' COMMENT '客户需求',
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='客户信息表';

CREATE TABLE `cst_dict` (
  `dict_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '名字',
  `typetag` varchar(256) NOT NULL DEFAULT '' COMMENT '分类标识',
  `sort` smallint(8) NOT NULL DEFAULT '0',
  `visible` smallint(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`dict_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='字典表';

CREATE TABLE `cst_dict_type` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `typename` varchar(256) NOT NULL DEFAULT '' COMMENT '分类名称',
  `typedir` varchar(256) NOT NULL DEFAULT '' COMMENT '分类目录',
  `typetag` varchar(1024) NOT NULL DEFAULT '' COMMENT '分类标识',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序',
  `visible` tinyint(2) NOT NULL DEFAULT '1' COMMENT '是否启用',
  `intro` varchar(1024) DEFAULT '',
  `seotitle` varchar(256) NOT NULL DEFAULT '',
  `keywords` varchar(256) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='字典分类';

CREATE TABLE `cst_field_ext` (
  `field_ext_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `main_table` varchar(50) NOT NULL DEFAULT '' COMMENT '关联主表',
  `ext_table` varchar(50) NOT NULL DEFAULT '' COMMENT '扩展表名',
  `show_name` varchar(256) NOT NULL DEFAULT '' COMMENT '字段表单名称',
  `field_name` varchar(256) NOT NULL DEFAULT '' COMMENT '字段名称',
  `field_type` varchar(50) NOT NULL DEFAULT '' COMMENT '单文本=varchar,文本=text,多行文本=textarea,整数=int,小数=float,图片=img,下拉=option,单选=radio,复选=checkbox',
  `default_value` varchar(256) NOT NULL DEFAULT '' COMMENT '字段默认值',
  `maxlength` varchar(256) NOT NULL DEFAULT '' COMMENT '最大值',
  `desc` varchar(256) NOT NULL DEFAULT '' COMMENT '表单说明',
  `visible` smallint(1) NOT NULL DEFAULT '1' COMMENT '是否使用',
  `is_system` smallint(1) NOT NULL DEFAULT '0' COMMENT '是否为系统字段，1=是（不能删除）0=否',
  `is_must` smallint(1) NOT NULL DEFAULT '0' COMMENT '是否改填',
  `sort` int(16) NOT NULL DEFAULT '0' COMMENT '显示排序',
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  PRIMARY KEY (`field_ext_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='客户字段扩展表';

CREATE TABLE `cst_filing` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `cusID` int(16) NOT NULL DEFAULT '0',
  `linkmanID` int(16) NOT NULL DEFAULT '0',
  `chanceID` int(16) NOT NULL DEFAULT '0',
  `userID` int(16) NOT NULL DEFAULT '0',
  `applicant_userID` int(16) NOT NULL DEFAULT '0',
  `audit_userID` int(16) NOT NULL DEFAULT '0',
  `audit_dt` datetime DEFAULT NULL,
  `title` varchar(256) NOT NULL DEFAULT '',
  `intro` text,
  `support` text COMMENT '所需支持',
  `status` smallint(1) NOT NULL DEFAULT '1' COMMENT '1=未审核2=同意3=否决',
  `create_userID` int(16) NOT NULL DEFAULT '0',
  `adt` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='项目报备';

CREATE TABLE `cst_linkman` (
  `linkman_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `customer_id` int(16) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '',
  `gender` smallint(1) NOT NULL DEFAULT '0' COMMENT '姓别1=男，0=女',
  `postion` varchar(256) NOT NULL DEFAULT '' COMMENT '职位、',
  `tel` varchar(256) NOT NULL DEFAULT '',
  `mobile` varchar(256) NOT NULL DEFAULT '',
  `qicq` varchar(256) NOT NULL DEFAULT '',
  `email` varchar(256) NOT NULL DEFAULT '',
  `zipcode` varchar(256) NOT NULL DEFAULT '',
  `address` varchar(1024) NOT NULL DEFAULT '',
  `intro` text,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`linkman_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='客户联系人';

CREATE TABLE `cst_quoted` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `cusID` int(16) NOT NULL DEFAULT '0',
  `linkmanID` int(16) NOT NULL DEFAULT '0',
  `chanceID` int(16) NOT NULL DEFAULT '0',
  `userID` int(16) NOT NULL DEFAULT '0',
  `quoted_userID` int(16) NOT NULL DEFAULT '0',
  `audit_userID` int(16) NOT NULL DEFAULT '0',
  `title` varchar(256) NOT NULL DEFAULT '',
  `intro` text,
  `delivery_intro` text,
  `payment_intro` text,
  `audit_dt` datetime DEFAULT NULL,
  `transport_intro` text,
  `status` smallint(1) NOT NULL DEFAULT '1' COMMENT '1=未审核2=同意3=否决',
  `create_userID` int(16) NOT NULL DEFAULT '0',
  `adt` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='报价表';

CREATE TABLE `cst_quoted_detail` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `quotedID` int(16) NOT NULL DEFAULT '0',
  `pro_number` varchar(64) NOT NULL DEFAULT '',
  `name` varchar(64) NOT NULL DEFAULT '',
  `model` varchar(64) NOT NULL DEFAULT '',
  `norm` varchar(64) NOT NULL DEFAULT '',
  `price` int(16) NOT NULL DEFAULT '0',
  `rebate` int(16) NOT NULL DEFAULT '0',
  `number` int(16) NOT NULL DEFAULT '0',
  `money` int(16) NOT NULL DEFAULT '0',
  `intro` text,
  `userID` int(16) NOT NULL DEFAULT '0' COMMENT '归属人员',
  `adt` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='报价明细';

CREATE TABLE `cst_service` (
  `service_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `customer_id` int(16) NOT NULL DEFAULT '0',
  `linkman_id` int(16) NOT NULL DEFAULT '0',
  `services` int(4) NOT NULL DEFAULT '0',
  `servicesmodel` int(4) NOT NULL DEFAULT '0',
  `price` int(11) NOT NULL DEFAULT '0',
  `status` smallint(1) NOT NULL DEFAULT '1' COMMENT '1=无需处理，2未处理，3=处理中，4处理完成',
  `service_time` datetime DEFAULT NULL,
  `tlen` varchar(64) NOT NULL DEFAULT '',
  `content` text,
  `intro` text,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`service_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='服务记录';

CREATE TABLE `cst_talk` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `cusID` int(16) NOT NULL DEFAULT '0',
  `name` varchar(1024) NOT NULL DEFAULT '',
  `create_userID` int(16) NOT NULL DEFAULT '0',
  `adt` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='打电话沟通记录';

CREATE TABLE `cst_trace` (
  `trace_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `customer_id` int(16) NOT NULL DEFAULT '0',
  `linkman_id` int(11) NOT NULL DEFAULT '0',
  `chance_id` int(11) NOT NULL DEFAULT '0',
  `conn_time` datetime DEFAULT NULL,
  `salestage` int(4) NOT NULL DEFAULT '0' COMMENT '沟通阶段',
  `salemode` int(4) unsigned zerofill NOT NULL DEFAULT '0000' COMMENT '销售方式',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '主题名称',
  `intro` text,
  `status` smallint(1) NOT NULL DEFAULT '1',
  `next_time` datetime DEFAULT NULL COMMENT '下次联系时间',
  `nexttitle` varchar(256) NOT NULL DEFAULT '' COMMENT '下次沟通主题',
  `create_user_id` int(16) unsigned NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`trace_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='跟踪记录';

CREATE TABLE `cst_website` (
  `website_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `customer_id` int(16) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '',
  `url` varchar(1024) NOT NULL DEFAULT '' COMMENT '网址',
  `start_date` date DEFAULT NULL,
  `end_date` date DEFAULT NULL,
  `ftp` varchar(256) NOT NULL DEFAULT '',
  `ftp_ip` varchar(256) NOT NULL DEFAULT '' COMMENT 'FTP ip',
  `ftp_account` varchar(256) NOT NULL DEFAULT '' COMMENT 'FTP 帐号',
  `ftp_pwd` varchar(256) NOT NULL DEFAULT '' COMMENT 'FTP 密码',
  `icp` varchar(256) NOT NULL DEFAULT '',
  `icp_account` varchar(256) NOT NULL DEFAULT '',
  `icp_pwd` varchar(256) NOT NULL DEFAULT '',
  `icp_num` varchar(256) NOT NULL DEFAULT '',
  `address` varchar(1024) NOT NULL DEFAULT '',
  `intro` text,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `status` int(2) NOT NULL DEFAULT '1' COMMENT '网站状态1=新增，2=续费，3=流失',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`website_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='网站业务';

CREATE TABLE `fin_bank_account` (
  `bank_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '开户银行名称',
  `card` varchar(256) NOT NULL DEFAULT '' COMMENT '帐号号',
  `address` varchar(256) NOT NULL DEFAULT '' COMMENT '开户地址',
  `holders` varchar(256) NOT NULL DEFAULT '' COMMENT '开户人',
  `sort` smallint(2) NOT NULL DEFAULT '0',
  `visible` smallint(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`bank_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='银行帐户';

CREATE TABLE `fin_capital_record` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `type_id` int(16) NOT NULL DEFAULT '1' COMMENT '费用类别，1=注入，-1=抽取',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `bank_id` int(16) NOT NULL DEFAULT '0',
  `money` int(16) NOT NULL DEFAULT '0',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `happen_date` date DEFAULT NULL COMMENT '产生日期',
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='资金注入抽取';

CREATE TABLE `fin_expenses_record` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `type_id` int(16) NOT NULL DEFAULT '0' COMMENT '费用类别',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `bank_id` int(16) NOT NULL DEFAULT '0',
  `money` int(16) NOT NULL DEFAULT '0',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `happen_date` date DEFAULT NULL COMMENT '产生日期',
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='其它支出记录';

CREATE TABLE `fin_expenses_type` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `parentID` int(11) NOT NULL DEFAULT '0',
  `sort` int(11) NOT NULL DEFAULT '0',
  `visible` tinyint(2) NOT NULL DEFAULT '1',
  `intro` varchar(1024) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=armscii8 COMMENT='其它支出类型';

CREATE TABLE `fin_flow_record` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `balance` decimal(20,2) NOT NULL DEFAULT '0.00' COMMENT '余额',
  `pay_money` decimal(20,2) NOT NULL DEFAULT '0.00' COMMENT '支出',
  `rece_money` decimal(20,2) NOT NULL DEFAULT '0.00' COMMENT '收入',
  `bank_id` int(16) NOT NULL DEFAULT '0',
  `bus_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联单号=业务单号',
  `bus_type` varchar(128) NOT NULL DEFAULT '' COMMENT '单号类型=财务类型',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '创建人',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='财务流水';

CREATE TABLE `fin_income_record` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `type_id` int(16) NOT NULL DEFAULT '0' COMMENT '费用类别',
  `bank_id` int(16) NOT NULL DEFAULT '0',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00',
  `intro` text,
  `happen_date` date DEFAULT NULL COMMENT '产生日期',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='其它收入记录';

CREATE TABLE `fin_income_type` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `parentID` int(11) NOT NULL DEFAULT '0',
  `sort` int(11) NOT NULL DEFAULT '0',
  `visible` tinyint(2) NOT NULL DEFAULT '1',
  `intro` varchar(1024) CHARACTER SET utf8 DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=armscii8 COMMENT='其它收入类型';

CREATE TABLE `fin_invoice_pay` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '合同订单号',
  `contract_name` varchar(256) NOT NULL DEFAULT '',
  `customer_id` int(16) NOT NULL DEFAULT '0' COMMENT '客户号',
  `customer_name` varchar(256) NOT NULL DEFAULT '',
  `money` int(16) NOT NULL DEFAULT '0',
  `pay_date` date DEFAULT NULL COMMENT '开票时间',
  `stages` int(11) NOT NULL DEFAULT '0',
  `invoice_no` varchar(256) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '0',
  `bus_type` varchar(256) NOT NULL DEFAULT '0' COMMENT '订单类型',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='开票记录、';

CREATE TABLE `fin_invoice_rece` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联采购号',
  `supplier_id` int(16) NOT NULL DEFAULT '0' COMMENT '供应商号',
  `contract_name` varchar(256) NOT NULL DEFAULT '',
  `supplier_name` varchar(256) NOT NULL DEFAULT '',
  `money` int(16) NOT NULL DEFAULT '0',
  `rece_date` date DEFAULT NULL COMMENT '收票时间',
  `stages` int(11) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '发票内容',
  `invoice_no` varchar(256) NOT NULL DEFAULT '0' COMMENT '发票编号',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='收票记录';

CREATE TABLE `fin_pay_plan` (
  `plan_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '采购订单号',
  `contract_name` varchar(256) NOT NULL DEFAULT '' COMMENT '采购合同名称',
  `supplier_id` int(16) NOT NULL DEFAULT '0' COMMENT '供应商号',
  `supplier_name` varchar(256) NOT NULL DEFAULT '' COMMENT '供应商名称',
  `bank_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联银行帐号',
  `money` int(16) NOT NULL DEFAULT '0' COMMENT '金额',
  `plan_date` date DEFAULT NULL COMMENT '计划付款时间',
  `stages` int(11) NOT NULL DEFAULT '0' COMMENT '其次',
  `ifpay` varchar(50) NOT NULL DEFAULT '-1',
  `intro` text,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`plan_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='付款计划表';

CREATE TABLE `fin_pay_record` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `plan_id` int(16) unsigned NOT NULL DEFAULT '0' COMMENT '关联付款记划',
  `contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '采购订单号',
  `contract_name` varchar(256) NOT NULL DEFAULT '',
  `supplier_id` int(16) NOT NULL DEFAULT '0' COMMENT '供应商号',
  `supplier_name` varchar(256) NOT NULL DEFAULT '',
  `bank_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联帐号',
  `pay_date` date DEFAULT NULL,
  `money` decimal(10,2) NOT NULL DEFAULT '0.00',
  `zero_money` decimal(10,2) NOT NULL DEFAULT '0.00',
  `stages` int(11) NOT NULL DEFAULT '0',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='付款记录';

CREATE TABLE `fin_rece_plan` (
  `plan_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '合同订单号',
  `contract_name` varchar(256) NOT NULL DEFAULT '' COMMENT '合同名称',
  `customer_id` int(16) NOT NULL DEFAULT '0' COMMENT '客户号',
  `customer_name` varchar(256) NOT NULL DEFAULT '' COMMENT '客户名称',
  `bank_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联帐号',
  `money` int(16) NOT NULL DEFAULT '0',
  `plan_date` date DEFAULT NULL COMMENT '计划回款时间',
  `stages` int(11) NOT NULL DEFAULT '0',
  `create_user_id` int(11) NOT NULL DEFAULT '0',
  `ifpay` varchar(50) NOT NULL DEFAULT '-1' COMMENT 'NO=未付 YES=已经付',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`plan_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='计划回款表';

CREATE TABLE `fin_rece_record` (
  `record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '合同订单号',
  `contract_name` varchar(256) NOT NULL DEFAULT '',
  `plan_id` int(16) NOT NULL DEFAULT '0',
  `customer_id` int(16) NOT NULL DEFAULT '0' COMMENT '客户号',
  `customer_name` varchar(256) NOT NULL DEFAULT '',
  `bank_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联帐号',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '金额',
  `zero_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '去零金额',
  `back_date` date DEFAULT NULL COMMENT '计划回款时间',
  `stages` int(11) NOT NULL DEFAULT '0' COMMENT '期次',
  `bus_type` varchar(128) NOT NULL DEFAULT '' COMMENT '关联业务类型',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='回款记录';

CREATE TABLE `fly_goods` (
  `goods_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品id(SKU)',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '商品名称',
  `shop_id` int(10) unsigned NOT NULL DEFAULT '1' COMMENT '店铺id',
  `category_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '商品分类id',
  `category_id_1` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '一级分类id',
  `category_id_2` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '二级分类id',
  `category_id_3` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '三级分类id',
  `brand_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '品牌id',
  `group_id_array` varchar(255) NOT NULL DEFAULT '' COMMENT '店铺分类id 首尾用,隔开',
  `promotion_type` tinyint(3) NOT NULL DEFAULT '0' COMMENT '促销类型 0无促销，1团购，2限时折扣',
  `goods_type` tinyint(4) NOT NULL DEFAULT '1' COMMENT '实物或虚拟商品标志 1实物商品 0 虚拟商品 2 F码商品',
  `market_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '市场价',
  `sale_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '销售价格',
  `cost_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '成本价',
  `price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '商品原价格',
  `promotion_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '商品促销价格',
  `give_point` int(11) NOT NULL DEFAULT '0' COMMENT '购买商品赠送积分',
  `is_member_discount` int(1) NOT NULL DEFAULT '0' COMMENT '参与会员折扣',
  `shipping_fee` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '运费 0为免运费',
  `shipping_fee_id` int(11) NOT NULL DEFAULT '0' COMMENT '售卖区域id 物流模板id  ns_order_shipping_fee 表id',
  `max_buy` int(11) NOT NULL DEFAULT '0' COMMENT '限购 0 不限购',
  `clicks` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '商品点击数量',
  `min_stock_alarm` int(11) NOT NULL DEFAULT '0' COMMENT '库存预警值',
  `sales` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '销售数量',
  `collects` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '收藏数量',
  `star` tinyint(3) unsigned NOT NULL DEFAULT '5' COMMENT '好评星级',
  `evaluates` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '评价数',
  `shares` int(11) NOT NULL DEFAULT '0' COMMENT '分享数',
  `province_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '一级地区id',
  `city_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '二级地区id',
  `defaultpic` varchar(255) NOT NULL DEFAULT '0' COMMENT '商品主图',
  `keywords` varchar(255) NOT NULL DEFAULT '' COMMENT '商品关键词',
  `introduction` varchar(255) NOT NULL DEFAULT '' COMMENT '商品简介，促销语',
  `description` text NOT NULL COMMENT '商品详情',
  `content` text NOT NULL COMMENT '商品详细内容',
  `code` varchar(50) NOT NULL DEFAULT '' COMMENT '商家编号',
  `is_hot` int(1) NOT NULL DEFAULT '0' COMMENT '是否热销商品',
  `is_recommend` int(1) NOT NULL DEFAULT '0' COMMENT '是否推荐0=不推荐，1=推荐',
  `is_new` int(1) NOT NULL DEFAULT '0' COMMENT '是否新品',
  `is_bill` int(1) NOT NULL DEFAULT '0' COMMENT '是否开具增值税发票 1是，0否',
  `state` tinyint(3) NOT NULL DEFAULT '1' COMMENT '商品状态 0下架，1正常，10违规（禁售）',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序',
  `img_id_array` varchar(1000) DEFAULT NULL COMMENT '商品图片序列',
  `sku_img_array` varchar(1000) DEFAULT NULL COMMENT '商品sku应用图片列表  属性,属性值，图片ID',
  `match_point` float(10,2) DEFAULT NULL COMMENT '实物与描述相符（根据评价计算）',
  `match_ratio` float(10,2) DEFAULT NULL COMMENT '实物与描述相符（根据评价计算）百分比',
  `real_sales` int(10) NOT NULL DEFAULT '0' COMMENT '实际销量',
  `goods_attribute_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品类型',
  `goods_spec_format` text NOT NULL COMMENT '商品规格',
  `goods_weight` decimal(8,2) NOT NULL DEFAULT '0.00' COMMENT '商品重量',
  `goods_volume` decimal(8,2) NOT NULL DEFAULT '0.00' COMMENT '商品体积',
  `shipping_fee_type` int(11) NOT NULL DEFAULT '1' COMMENT '计价方式1.重量2.体积3.计件',
  `extend_category_id` varchar(255) DEFAULT NULL,
  `extend_category_id_1` varchar(255) DEFAULT NULL,
  `extend_category_id_2` varchar(255) DEFAULT NULL,
  `extend_category_id_3` varchar(255) DEFAULT NULL,
  `supplier_id` int(11) NOT NULL DEFAULT '0' COMMENT '供货商id',
  `sale_date` datetime NOT NULL COMMENT '上下架时间',
  `create_time` datetime NOT NULL COMMENT '商品添加时间',
  `update_time` datetime NOT NULL COMMENT '商品编辑时间',
  `min_buy` int(11) NOT NULL DEFAULT '0' COMMENT '最少买几件',
  `virtual_goods_type_id` int(11) DEFAULT '0' COMMENT '虚拟商品类型id',
  `production_date` int(11) NOT NULL DEFAULT '0' COMMENT '生产日期',
  `shelf_life` varchar(50) NOT NULL DEFAULT '' COMMENT '保质期',
  `goods_video_address` varchar(455) DEFAULT '' COMMENT '商品视频地址，不为空时前台显示视频',
  `pc_custom_template` varchar(255) NOT NULL DEFAULT '' COMMENT 'pc端商品自定义模板',
  `wap_custom_template` varchar(255) NOT NULL DEFAULT '' COMMENT 'wap端商品自定义模板',
  `max_use_point` int(11) NOT NULL DEFAULT '0' COMMENT '积分抵现最大可用积分数 0为不可使用',
  `is_open_presell` tinyint(4) NOT NULL DEFAULT '0' COMMENT '是否支持预售',
  `presell_time` int(11) NOT NULL DEFAULT '0' COMMENT '预售发货时间',
  `presell_day` int(11) NOT NULL DEFAULT '0' COMMENT '预售发货天数',
  `presell_delivery_type` int(11) NOT NULL DEFAULT '1' COMMENT '预售发货方式1. 按照预售发货时间 2.按照预售发货天数',
  `presell_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '预售金额',
  `goods_unit` varchar(20) NOT NULL DEFAULT '' COMMENT '商品单位',
  PRIMARY KEY (`goods_id`),
  KEY `UK_fly_goods_brand_id` (`brand_id`),
  KEY `UK_fly_goods_category_id` (`category_id`),
  KEY `UK_fly_goods_category_id_1` (`category_id_1`),
  KEY `UK_fly_goods_category_id_2` (`category_id_2`),
  KEY `UK_fly_goods_category_id_3` (`category_id_3`),
  KEY `UK_fly_goods_extend_category_id` (`extend_category_id`),
  KEY `UK_fly_goods_extend_category_id_1` (`extend_category_id_1`),
  KEY `UK_fly_goods_extend_category_id_2` (`extend_category_id_2`),
  KEY `UK_fly_goods_extend_category_id_3` (`extend_category_id_3`),
  KEY `UK_fly_goods_goods_attribute_id` (`goods_attribute_id`),
  KEY `UK_fly_goods_group_id_array` (`group_id_array`),
  KEY `UK_fly_goods_promotion_price` (`promotion_price`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=16554 COMMENT='商品表';

CREATE TABLE `fly_goods_attr` (
  `attr_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT '商品属性ID',
  `attr_name` varchar(255) NOT NULL DEFAULT '' COMMENT '属性名称',
  `visible` tinyint(1) NOT NULL DEFAULT '1' COMMENT '是否使用',
  `spec_id_array` varchar(255) NOT NULL DEFAULT '' COMMENT '关联规格',
  `sort` int(11) DEFAULT '0',
  `create_time` int(11) DEFAULT '0' COMMENT '创建时间',
  `modify_time` int(11) DEFAULT '0' COMMENT '修改时间',
  `brand_id_array` varchar(255) NOT NULL DEFAULT '' COMMENT '关联品牌',
  PRIMARY KEY (`attr_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=16384 COMMENT='商品相关属性';

CREATE TABLE `fly_goods_attr_relation` (
  `attr_relation_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `shop_id` int(11) NOT NULL DEFAULT '0' COMMENT '店铺ID',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `attr_id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '属性编号',
  `attr_name` varchar(255) NOT NULL DEFAULT '' COMMENT '属性名称',
  `attr_value_id` int(11) NOT NULL DEFAULT '0' COMMENT '属性值id',
  `attr_value_name` varchar(255) NOT NULL DEFAULT '' COMMENT '属性值的名称',
  `attr_value_data` varchar(255) NOT NULL DEFAULT '' COMMENT '属性值名称对应最终数据',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序',
  `create_time` int(11) DEFAULT '0' COMMENT '创建时间',
  PRIMARY KEY (`attr_relation_id`),
  KEY `UK_fly_goods_attribute_attr_value_id` (`attr_value_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=315 COMMENT='商品和属性关联表\r\n';

CREATE TABLE `fly_goods_attr_value` (
  `attr_value_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '属性值ID',
  `attr_id` int(11) NOT NULL DEFAULT '0' COMMENT '属性ID',
  `attr_value_name` varchar(50) NOT NULL DEFAULT '' COMMENT '属性值名称',
  `attr_value_data` varchar(1000) NOT NULL DEFAULT '' COMMENT '属性对应相关数据',
  `type` int(11) NOT NULL DEFAULT '1' COMMENT '属性对应输入类型1.直接2.单选3.多选',
  `sort` int(11) NOT NULL DEFAULT '1999' COMMENT '排序号',
  `is_search` tinyint(1) NOT NULL DEFAULT '1' COMMENT '是否使用',
  PRIMARY KEY (`attr_value_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=4096 COMMENT='商品属性值';

CREATE TABLE `fly_goods_brand` (
  `brand_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '索引ID',
  `shop_id` int(11) NOT NULL DEFAULT '0' COMMENT '店铺ID',
  `brand_name` varchar(100) NOT NULL DEFAULT '' COMMENT '品牌名称',
  `brand_initial` varchar(1) NOT NULL DEFAULT '' COMMENT '品牌首字母',
  `brand_pic` varchar(100) NOT NULL DEFAULT '' COMMENT '图片',
  `brand_recommend` tinyint(1) NOT NULL DEFAULT '0' COMMENT '推荐，0为否，1为是，默认为0',
  `sort` int(11) DEFAULT '0',
  `brand_category_name` varchar(50) NOT NULL DEFAULT '' COMMENT '类别名称',
  `category_id_array` varchar(1000) NOT NULL DEFAULT '' COMMENT '所属分类id组',
  `brand_ads` varchar(255) NOT NULL DEFAULT '' COMMENT '品牌推荐广告',
  `category_name` varchar(50) NOT NULL DEFAULT '' COMMENT '品牌所属分类名称',
  `category_id_1` int(11) NOT NULL DEFAULT '0' COMMENT '一级分类ID',
  `category_id_2` int(11) NOT NULL DEFAULT '0' COMMENT '二级分类ID',
  `category_id_3` int(11) NOT NULL DEFAULT '0' COMMENT '三级分类ID',
  PRIMARY KEY (`brand_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=1024 COMMENT='品牌表';

CREATE TABLE `fly_goods_category` (
  `category_id` int(11) NOT NULL AUTO_INCREMENT,
  `category_name` varchar(50) NOT NULL DEFAULT '',
  `short_name` varchar(50) NOT NULL DEFAULT '' COMMENT '商品分类简称 ',
  `parent_id` int(11) NOT NULL DEFAULT '0',
  `level` tinyint(4) NOT NULL DEFAULT '0',
  `visible` int(11) NOT NULL DEFAULT '1' COMMENT '是否显示  1 显示 0 不显示',
  `attr_id` int(11) NOT NULL DEFAULT '0' COMMENT '关联商品类型ID',
  `attr_name` varchar(255) NOT NULL DEFAULT '' COMMENT '关联类型名称',
  `keywords` varchar(255) NOT NULL DEFAULT '' COMMENT '分类关键字用于seo',
  `description` varchar(255) NOT NULL DEFAULT '' COMMENT '分类描述用于seo',
  `sort` int(11) DEFAULT NULL,
  `category_pic` varchar(255) NOT NULL DEFAULT '' COMMENT '商品分类图片',
  `pc_custom_template` varchar(255) NOT NULL DEFAULT '' COMMENT 'pc端商品分类自定义模板',
  `wap_custom_template` varchar(255) NOT NULL DEFAULT '' COMMENT 'wap端商品分类自定义模板',
  PRIMARY KEY (`category_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=244 COMMENT='商品分类表';

CREATE TABLE `fly_goods_img` (
  `img_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'ID',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `img_path` varchar(256) NOT NULL DEFAULT '' COMMENT '图片路径',
  PRIMARY KEY (`img_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=16384 COMMENT='商品图片';

CREATE TABLE `fly_goods_sku` (
  `sku_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '表序号',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品编号',
  `goods_name` varchar(500) NOT NULL DEFAULT '' COMMENT '商品名称',
  `sku_name` varchar(500) NOT NULL DEFAULT '' COMMENT 'SKU名称',
  `sku_value_items` varchar(255) NOT NULL DEFAULT '' COMMENT '属性和属性值 id串 attribute + attribute value 表ID分号分隔',
  `sku_value_items_format` varchar(500) NOT NULL DEFAULT '' COMMENT '属性和属性值id串组合json格式',
  `market_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '市场价',
  `sale_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '销售价格',
  `price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '价格',
  `promote_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '促销价格',
  `cost_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '成本价',
  `total_cost_money` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '成本总金额',
  `total_sale_money` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '销售总金额',
  `total_profit_money` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '利润总金额',
  `picture` int(11) NOT NULL DEFAULT '0' COMMENT '如果是第一个sku编码, 可以加图片',
  `code` varchar(255) NOT NULL DEFAULT '' COMMENT '商家编码',
  `QRcode` varchar(255) NOT NULL DEFAULT '' COMMENT '商品二维码',
  `create_date` datetime DEFAULT NULL COMMENT '创建时间',
  `update_date` datetime DEFAULT NULL COMMENT '修改时间',
  PRIMARY KEY (`sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=481 COMMENT='商品sku规格价格信息表';

CREATE TABLE `fly_goods_spec` (
  `spec_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '属性ID',
  `shop_id` int(11) NOT NULL DEFAULT '0' COMMENT '店铺ID',
  `spec_name` varchar(255) NOT NULL DEFAULT '' COMMENT '属性名称',
  `visible` tinyint(1) NOT NULL DEFAULT '0' COMMENT '是否可视',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序',
  `show_type` int(11) NOT NULL DEFAULT '1' COMMENT '展示方式 1 文字 2 颜色 3 图片',
  `create_time` datetime DEFAULT NULL COMMENT '创建日期',
  `is_screen` tinyint(1) NOT NULL DEFAULT '1' COMMENT '是否参与筛选 0 不参与 1 参与',
  `spec_des` varchar(255) NOT NULL DEFAULT '' COMMENT '属性说明',
  `goods_id` int(11) DEFAULT '0' COMMENT '商品关联id',
  PRIMARY KEY (`spec_id`),
  KEY `IDX_category_props_categoryId` (`shop_id`),
  KEY `IDX_category_props_orders` (`sort`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=3276 COMMENT='商品属性（规格）表';

CREATE TABLE `fly_goods_spec_value` (
  `spec_value_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '商品属性值ID',
  `spec_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品属性ID',
  `spec_value_name` varchar(255) NOT NULL DEFAULT '' COMMENT '商品属性值名称',
  `spec_value_data` varchar(255) NOT NULL DEFAULT '' COMMENT '商品属性值数据',
  `is_visible` tinyint(1) NOT NULL DEFAULT '0' COMMENT '是否可视',
  `sort` int(11) NOT NULL DEFAULT '0' COMMENT '排序',
  `create_time` datetime DEFAULT NULL,
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品id',
  PRIMARY KEY (`spec_value_id`),
  KEY `IDX_category_propvalues_c_pId` (`spec_id`),
  KEY `IDX_category_propvalues_orders` (`sort`),
  KEY `IDX_category_propvalues_value` (`spec_value_name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=1092 COMMENT='商品规格值模版表';

CREATE TABLE `fly_sys_area` (
  `id` int(4) NOT NULL AUTO_INCREMENT,
  `parentID` int(4) NOT NULL DEFAULT '0',
  `sort` int(4) NOT NULL DEFAULT '0',
  `name` varchar(12) NOT NULL DEFAULT '',
  `type` int(1) NOT NULL DEFAULT '0',
  `visible` int(1) NOT NULL DEFAULT '0',
  `intro` varchar(256) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='地区表';

CREATE TABLE `fly_sys_config` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) NOT NULL DEFAULT '',
  `varname` varchar(128) NOT NULL DEFAULT '',
  `value` text,
  `type` varchar(50) NOT NULL DEFAULT '' COMMENT '字段类型',
  `groupid` tinyint(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='系统配置表';

CREATE TABLE `fly_sys_dept` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `parentID` int(11) NOT NULL DEFAULT '0',
  `sort` int(11) NOT NULL DEFAULT '0',
  `visible` tinyint(2) NOT NULL DEFAULT '1',
  `tel` varchar(32) CHARACTER SET utf8 DEFAULT '',
  `fax` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `intro` varchar(1024) CHARACTER SET utf8 DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=armscii8 COMMENT='部门表';

CREATE TABLE `fly_sys_log` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `ipaddr` varchar(16) NOT NULL DEFAULT '',
  `content` text,
  `create_user_id` varchar(32) DEFAULT '',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='系统日志表';

CREATE TABLE `fly_sys_menu` (
  `id` int(4) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL DEFAULT '',
  `name_en` varchar(64) NOT NULL DEFAULT '',
  `url` varchar(128) NOT NULL DEFAULT '',
  `parentID` int(4) NOT NULL DEFAULT '0',
  `sort` int(4) NOT NULL DEFAULT '0',
  `visible` int(2) NOT NULL DEFAULT '0',
  `icon` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='系统菜单栏目';

-- zocrm_sys.fly_sys_role_menu definition

CREATE TABLE `fly_sys_role_menu` (
  `id` int unsigned NOT NULL AUTO_INCREMENT,
  `role_id` int unsigned DEFAULT NULL,
  `menu_id` int unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=67 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='角色菜单关联表';

CREATE TABLE `fly_sys_message` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `msg_type` varchar(256) NOT NULL DEFAULT '' COMMENT '消息类型',
  `msg_title` varchar(256) NOT NULL DEFAULT '' COMMENT '消息主题',
  `flag` tinyint(4) NOT NULL DEFAULT '-1' COMMENT '-1=未查看，1=查看',
  `url_type` varchar(50) NOT NULL DEFAULT '',
  `url_id` int(11) NOT NULL DEFAULT '0',
  `owner_user_id` int(2) NOT NULL DEFAULT '0' COMMENT '所属用户编号',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `remind_time` datetime DEFAULT NULL COMMENT '提醒时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='消息信息';

CREATE TABLE `fly_sys_method` (
  `id` int(4) unsigned NOT NULL AUTO_INCREMENT,
  `menuID` int(4) NOT NULL DEFAULT '0',
  `name` varchar(64) NOT NULL DEFAULT '',
  `value` varchar(64) NOT NULL DEFAULT '',
  `sort` int(4) NOT NULL DEFAULT '0',
  `visible` int(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='系统方法';

CREATE TABLE `fly_sys_position` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `parentID` int(11) NOT NULL DEFAULT '0',
  `sort` int(11) NOT NULL DEFAULT '0',
  `visible` tinyint(2) NOT NULL DEFAULT '1',
  `intro` varchar(1024) CHARACTER SET utf8 DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=armscii8 COMMENT='职位表';

CREATE TABLE `fly_sys_power` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `master` varchar(64) NOT NULL DEFAULT '' COMMENT '权限类型，如role,user',
  `master_value` varchar(64) NOT NULL DEFAULT '' COMMENT '权限类型值',
  `access` varchar(64) NOT NULL DEFAULT '' COMMENT '权限属性名称 meun method',
  `access_value` text COMMENT '权限属性名称值',
  `operation` varchar(64) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='权限功能关联表';

CREATE TABLE `fly_sys_role` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `sort` int(16) NOT NULL DEFAULT '0',
  `visible` int(2) NOT NULL DEFAULT '0',
  `parentID` int(16) NOT NULL DEFAULT '0',
  `name` varchar(32) DEFAULT '',
  `intro` varchar(1024) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='权限列表';

CREATE TABLE `fly_sys_user` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `account` varchar(32) NOT NULL DEFAULT '',
  `password` varchar(500) NOT NULL DEFAULT '',
  `name` varchar(32) DEFAULT '',
  `gender` varchar(2) DEFAULT '',
  `tel` varchar(32) DEFAULT '',
  `mobile` varchar(32) DEFAULT '',
  `qicq` varchar(32) DEFAULT '',
  `address` varchar(256) DEFAULT '',
  `zipcode` varchar(256) DEFAULT '',
  `email` varchar(128) DEFAULT '',
  `roleID` varchar(50) NOT NULL DEFAULT '',
  `deptID` int(16) NOT NULL DEFAULT '0',
  `positionID` int(16) NOT NULL DEFAULT '0',
  `intro` varchar(1024) NOT NULL DEFAULT '',
  `adt` datetime DEFAULT NULL,
  `identity` varchar(50) DEFAULT '',
  `status` int(16) DEFAULT '0' COMMENT '账号状态 0=正常，1=冻结',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='系统用户表';

CREATE TABLE `fly_sys_user_notice` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `title` varchar(256) NOT NULL DEFAULT '' COMMENT '标题',
  `content` text COMMENT '通知内容',
  `status` int(2) NOT NULL DEFAULT '-1' COMMENT '-1=未查看，1=查看',
  `owner_user_id` int(2) NOT NULL DEFAULT '0' COMMENT '接收人员编号',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '发布人员的编号',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='系统员工通知信息';

CREATE TABLE `fly_sys_user_role` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `role_id` int(16) NOT NULL DEFAULT '0',
  `user_id` int(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='用户权限关联列表';

CREATE TABLE `hrm_staff` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_no` varchar(50) NOT NULL DEFAULT '' COMMENT '员工编号',
  `name` varchar(256) NOT NULL DEFAULT '',
  `gender` smallint(1) NOT NULL DEFAULT '0' COMMENT '姓别1=男，0=女',
  `idcard` varchar(50) NOT NULL DEFAULT '' COMMENT '身份证号',
  `age` smallint(4) NOT NULL DEFAULT '0' COMMENT '年龄',
  `dept_id` varchar(256) NOT NULL DEFAULT '' COMMENT '部门',
  `position_id` varchar(256) NOT NULL DEFAULT '' COMMENT '职务',
  `marriage` varchar(256) NOT NULL DEFAULT '' COMMENT '婚姻情况',
  `politics` varchar(256) NOT NULL DEFAULT '' COMMENT '政治面貌',
  `degree` varchar(256) NOT NULL DEFAULT '' COMMENT '最高学历',
  `major` varchar(256) NOT NULL DEFAULT '' COMMENT '就读专业',
  `qualification` varchar(256) NOT NULL DEFAULT '' COMMENT '职业资格',
  `position` varchar(256) NOT NULL DEFAULT '' COMMENT '工作职务',
  `social` varchar(256) NOT NULL DEFAULT '' COMMENT '社会职',
  `mobile` varchar(256) NOT NULL DEFAULT '',
  `qicq` varchar(256) NOT NULL DEFAULT '',
  `email` varchar(256) NOT NULL DEFAULT '',
  `zipcode` varchar(256) NOT NULL DEFAULT '',
  `address` varchar(1024) NOT NULL DEFAULT '',
  `intro` text,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工档案';

CREATE TABLE `hrm_staff_achiev` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '名称',
  `work_date` date DEFAULT NULL COMMENT '工作时间',
  `content` text COMMENT '业绩内容',
  `remark` text COMMENT '介绍',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工工作业绩';

CREATE TABLE `hrm_staff_certified` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '名称',
  `company` varchar(256) NOT NULL DEFAULT '' COMMENT '获取单位',
  `gettime` date DEFAULT NULL COMMENT '获取时间',
  `remark` text COMMENT '备注',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工个人证书';

CREATE TABLE `hrm_staff_contract` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `begin_date` date DEFAULT NULL COMMENT '开始时间',
  `end_date` date DEFAULT NULL COMMENT '结束时间',
  `content` text COMMENT '内容',
  `remark` text COMMENT '备注',
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工劳动合作';

CREATE TABLE `hrm_staff_employ` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `position` varchar(256) NOT NULL DEFAULT '' COMMENT '职务',
  `work_date` date DEFAULT NULL COMMENT '入职时间',
  `content` text COMMENT '工作内容',
  `remark` text COMMENT '备注',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工用工记录';

CREATE TABLE `hrm_staff_examine` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `exa_time` date DEFAULT NULL COMMENT '考核时间',
  `score` varchar(50) NOT NULL DEFAULT '' COMMENT '考核分数',
  `results` varchar(50) NOT NULL DEFAULT '' COMMENT '考核结果',
  `remark` text COMMENT '备注',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工考核记录';

CREATE TABLE `hrm_staff_reward` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `type` varchar(256) NOT NULL DEFAULT '' COMMENT '奖励、处罚',
  `content` text COMMENT '内容',
  `gettime` date DEFAULT NULL COMMENT '获取时间',
  `remark` text COMMENT '备注',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工奖罚记录';

CREATE TABLE `hrm_staff_school` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '学校名称',
  `begin_date` date DEFAULT NULL COMMENT '开始时间',
  `end_date` date DEFAULT NULL COMMENT '结束时间',
  `position` varchar(50) NOT NULL DEFAULT '' COMMENT '职务',
  `intro` text COMMENT '介绍',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工学习经历';

CREATE TABLE `hrm_staff_talk` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '谈话人',
  `content` text COMMENT '内容',
  `gettime` date DEFAULT NULL COMMENT '时间',
  `remark` text COMMENT '备注',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工谈话记录';

CREATE TABLE `hrm_staff_work` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `staff_id` int(16) NOT NULL DEFAULT '0' COMMENT '员工编号',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '工作单位',
  `begin_date` date DEFAULT NULL COMMENT '开始时间',
  `end_date` date DEFAULT NULL COMMENT '结束时间',
  `position` varchar(50) NOT NULL DEFAULT '' COMMENT '职务',
  `intro` text COMMENT '介绍',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='员工工作经历';

CREATE TABLE `pos_contract` (
  `contract_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `contract_no` varchar(50) NOT NULL DEFAULT '' COMMENT '合同编号',
  `supplier_id` int(16) NOT NULL DEFAULT '0',
  `linkman_id` int(16) NOT NULL DEFAULT '0',
  `chance_id` int(16) NOT NULL DEFAULT '0',
  `website_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联网站',
  `start_date` date DEFAULT NULL COMMENT '采购时间',
  `end_date` date DEFAULT NULL COMMENT '预订到货时间',
  `our_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '我方联系人',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '合同金额',
  `goods_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '商品金额',
  `zero_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '去零金额',
  `back_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '回款金额',
  `owe_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '欠款金额',
  `pay_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '支付金额',
  `unpaid_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '未支付金额',
  `invoice_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '开票金额',
  `title` varchar(256) NOT NULL DEFAULT '' COMMENT '订单主题',
  `intro` text COMMENT '订单介绍',
  `status` smallint(1) NOT NULL DEFAULT '1' COMMENT '1=临时单，2=执行，3=完成，4=撤消',
  `back_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '回款状态，1=未付，2=部分，3=全部',
  `pay_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '支付状态，1=未付，2=部分，3=全部',
  `deliver_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '交付状态，-1=不需要，1=需要，2=录入明细，3=待入库，4=部分，5=全部',
  `invoice_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '开票状态 0=不需要，1=需要，2=部分，3=全部',
  `rece_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '收货状态，1=需要，2=录入明细，3=待入库，4=部分，5=全部',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime NOT NULL,
  PRIMARY KEY (`contract_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='采购合同';

CREATE TABLE `pos_contract_file` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '订单项ID',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同ID',
  `name` varchar(50) NOT NULL DEFAULT '' COMMENT '文件名称',
  `type` varchar(50) NOT NULL DEFAULT '' COMMENT '类型',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '备注',
  `filepath` varchar(255) NOT NULL DEFAULT '' COMMENT '文件路径',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  KEY `UK_ns_order_goods_order_id` (`contract_id`) USING BTREE
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='采购合同附件';

CREATE TABLE `pos_contract_list` (
  `list_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '订单项ID',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同ID',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '商品名称',
  `sku_id` int(11) NOT NULL DEFAULT '0' COMMENT 'skuID',
  `sku_name` varchar(50) NOT NULL DEFAULT '' COMMENT 'sku名称',
  `sale_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '商品价格',
  `cost_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '商品成本价',
  `num` varchar(255) NOT NULL DEFAULT '0' COMMENT '购买数量',
  `into_num` varchar(255) NOT NULL DEFAULT '0' COMMENT '入库数据',
  `owe_num` varchar(255) NOT NULL DEFAULT '0' COMMENT '未入库数量',
  `owe_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '未入库金额',
  `adjust_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '调整金额',
  `goods_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '商品总价',
  `goods_picture` int(11) NOT NULL DEFAULT '0' COMMENT '商品图片',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '备注',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`list_id`),
  KEY `UK_ns_order_goods_goods_id` (`goods_id`),
  KEY `UK_ns_order_goods_order_id` (`contract_id`),
  KEY `UK_ns_order_goods_sku_id` (`sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='采购订单商品表';

CREATE TABLE `sal_contract` (
  `contract_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(256) NOT NULL DEFAULT '' COMMENT '订单主题',
  `contract_no` varchar(50) NOT NULL DEFAULT '' COMMENT '合同编号',
  `customer_id` int(16) NOT NULL DEFAULT '0' COMMENT '客户ID',
  `linkman_id` int(16) NOT NULL DEFAULT '0' COMMENT '联系人ID',
  `chance_id` int(16) NOT NULL DEFAULT '0' COMMENT '销售机会',
  `website_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联网站',
  `start_date` date DEFAULT NULL COMMENT '开始时间',
  `end_date` date DEFAULT NULL COMMENT '结束时间',
  `our_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '我方联系人',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '合同金额',
  `goods_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '商品金额',
  `zero_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '去零金额',
  `back_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '回款金额',
  `owe_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '欠款金额',
  `deliver_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '交付金额',
  `invoice_money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '开票金额',
  `intro` text NOT NULL COMMENT '订单介绍',
  `status` smallint(1) NOT NULL DEFAULT '1' COMMENT '1=临时单，2=执行，3=完成，4=撤消',
  `back_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '回款状态，1=未付，2=部分，3=全部',
  `deliver_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '交付状态，-1=不需要，1=需要，2=录入明细，3=待出库，4=部分，5=全部',
  `invoice_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '开票状态， 0=不需要，1=需要，2=部分，3=全部',
  `renew_status` smallint(1) NOT NULL DEFAULT '1' COMMENT '订单类型，1=新增加，2=续费',
  `create_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '创建者',
  `create_time` datetime NOT NULL COMMENT '创建时间',
  PRIMARY KEY (`contract_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='销售合同';

CREATE TABLE `sal_contract_file` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '订单项ID',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同ID',
  `name` varchar(50) NOT NULL DEFAULT '' COMMENT '文件名称',
  `type` varchar(50) NOT NULL DEFAULT '' COMMENT '类型',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '备注',
  `filepath` varchar(255) NOT NULL DEFAULT '' COMMENT '文件路径',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  KEY `UK_ns_order_goods_order_id` (`contract_id`) USING BTREE
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='销售合同明附件';

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

CREATE TABLE `stock_goods_sku` (
  `stock_goods_sku_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '表序号',
  `sku_id` int(11) NOT NULL DEFAULT '0' COMMENT 'skuID',
  `store_id` int(11) NOT NULL DEFAULT '0' COMMENT '仓库编号',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品编号',
  `goods_name` varchar(500) NOT NULL DEFAULT '' COMMENT '商品名称',
  `sku_name` varchar(500) NOT NULL DEFAULT '' COMMENT 'SKU名称',
  `sale_price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '销售价格',
  `cost_price` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '成本价',
  `total_cost_money` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '成本总金额',
  `total_sale_money` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '销售总金额',
  `total_profit_money` decimal(19,2) NOT NULL DEFAULT '0.00' COMMENT '利润总金额',
  `stock` int(11) NOT NULL DEFAULT '0' COMMENT '库存',
  `code` varchar(255) NOT NULL DEFAULT '' COMMENT '商家编码',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_time` datetime DEFAULT NULL COMMENT '修改时间',
  PRIMARY KEY (`stock_goods_sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=481 COMMENT='库存清单';

CREATE TABLE `stock_into` (
  `into_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `store_id` int(16) unsigned NOT NULL DEFAULT '0' COMMENT '仓库编号',
  `contract_id` int(16) unsigned NOT NULL DEFAULT '0' COMMENT '采购合同编号',
  `title` varchar(256) NOT NULL DEFAULT '' COMMENT '订单主题',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '金额',
  `number` int(16) NOT NULL DEFAULT '0' COMMENT '数量',
  `intro` text NOT NULL COMMENT '订单介绍',
  `status` smallint(1) NOT NULL DEFAULT '-1' COMMENT '1=已经入库，-1=未入库',
  `into_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '入库管理员',
  `into_time` datetime NOT NULL COMMENT '入库时间',
  `into_type` varchar(50) NOT NULL DEFAULT '' COMMENT '入库类型',
  `create_user_id` int(16) NOT NULL COMMENT '创建人',
  `create_time` datetime NOT NULL COMMENT '创建时间',
  PRIMARY KEY (`into_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='入库单';

CREATE TABLE `stock_into_list` (
  `list_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '订单项ID',
  `into_id` int(11) NOT NULL DEFAULT '0' COMMENT '入库单编号 ',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同ID',
  `contract_list_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同明细ID',
  `store_id` int(11) NOT NULL DEFAULT '0' COMMENT '库存编号',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '商品名称',
  `sku_id` int(11) NOT NULL DEFAULT '0' COMMENT 'skuID',
  `sku_name` varchar(50) NOT NULL DEFAULT '' COMMENT 'sku名称',
  `number` varchar(255) NOT NULL DEFAULT '0' COMMENT '购买数量',
  `price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '采购价格',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '总金额',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '备注',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime NOT NULL,
  `into_user_id` int(11) DEFAULT '0' COMMENT '入库人员',
  `into_time` datetime NOT NULL COMMENT '入库时间',
  PRIMARY KEY (`list_id`),
  KEY `UK_ns_order_goods_goods_id` (`goods_id`),
  KEY `UK_ns_order_goods_order_id` (`contract_id`),
  KEY `UK_ns_order_goods_sku_id` (`sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='入库单明细表';

CREATE TABLE `stock_out` (
  `out_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `store_id` int(16) unsigned NOT NULL DEFAULT '0' COMMENT '仓库编号',
  `contract_id` int(16) unsigned NOT NULL DEFAULT '0' COMMENT '销售合同编号',
  `title` varchar(256) NOT NULL DEFAULT '' COMMENT '订单主题',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '金额',
  `number` int(16) NOT NULL DEFAULT '0' COMMENT '数量',
  `intro` text COMMENT '订单介绍',
  `status` smallint(1) NOT NULL DEFAULT '-1' COMMENT '1=已经出库，-1=未出库',
  `out_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '出库管理员',
  `out_time` datetime DEFAULT NULL COMMENT '出库时间',
  `out_type` varchar(50) NOT NULL DEFAULT '' COMMENT '出库类型',
  `create_user_id` int(16) NOT NULL DEFAULT '0' COMMENT '创建人',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`out_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='入库单';

CREATE TABLE `stock_out_list` (
  `list_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '订单项ID',
  `out_id` int(11) NOT NULL DEFAULT '0' COMMENT '出库单编号 ',
  `contract_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同ID',
  `contract_list_id` int(11) NOT NULL DEFAULT '0' COMMENT '合同明细ID',
  `store_id` int(11) NOT NULL DEFAULT '0' COMMENT '库存编号',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `goods_name` varchar(100) NOT NULL DEFAULT '' COMMENT '商品名称',
  `sku_id` int(11) NOT NULL DEFAULT '0' COMMENT 'skuID',
  `sku_name` varchar(50) NOT NULL DEFAULT '' COMMENT 'sku名称',
  `number` varchar(255) NOT NULL DEFAULT '0' COMMENT '购买数量',
  `price` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '出库价格',
  `money` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '总金额',
  `remarks` varchar(255) NOT NULL DEFAULT '' COMMENT '备注',
  `create_user_id` int(11) DEFAULT '0',
  `create_time` datetime NOT NULL,
  `out_user_id` int(11) DEFAULT '0' COMMENT '入库人员',
  `out_time` datetime DEFAULT NULL COMMENT '入库时间',
  PRIMARY KEY (`list_id`),
  KEY `UK_ns_order_goods_goods_id` (`goods_id`),
  KEY `UK_ns_order_goods_order_id` (`contract_id`),
  KEY `UK_ns_order_goods_sku_id` (`sku_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='入库单明细表';

CREATE TABLE `stock_store` (
  `store_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '名称',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人员',
  `own_user_id` varchar(256) NOT NULL DEFAULT '' COMMENT '管理人员',
  `sort` smallint(2) NOT NULL DEFAULT '0',
  `visible` smallint(2) NOT NULL DEFAULT '0',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`store_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='仓库管理';

CREATE TABLE `sup_linkman` (
  `linkman_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `supplier_id` int(16) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '',
  `gender` smallint(1) NOT NULL DEFAULT '0',
  `postion` varchar(256) NOT NULL DEFAULT '',
  `tel` varchar(256) NOT NULL DEFAULT '',
  `mobile` varchar(256) NOT NULL DEFAULT '',
  `qicq` varchar(256) NOT NULL DEFAULT '',
  `email` varchar(256) NOT NULL DEFAULT '',
  `zipcode` varchar(256) NOT NULL DEFAULT '',
  `address` varchar(1024) NOT NULL DEFAULT '',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  PRIMARY KEY (`linkman_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='供应商联系人';

CREATE TABLE `sup_supplier` (
  `supplier_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL DEFAULT '',
  `area_id` int(16) NOT NULL DEFAULT '0' COMMENT '所在地区',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `level` int(16) NOT NULL DEFAULT '0' COMMENT '客户等级',
  `ecotype` int(16) NOT NULL DEFAULT '0' COMMENT '经济类型',
  `trade` int(16) NOT NULL DEFAULT '0' COMMENT '行业',
  `satisfy` smallint(6) NOT NULL DEFAULT '3' COMMENT '满意度（1-5），默认为3',
  `credit` smallint(2) NOT NULL DEFAULT '3' COMMENT '信用度（1-5），默认为3',
  `address` varchar(256) NOT NULL DEFAULT '',
  `linkman` varchar(256) NOT NULL DEFAULT '',
  `website` varchar(256) NOT NULL DEFAULT '',
  `zipcode` varchar(64) NOT NULL DEFAULT '',
  `tel` varchar(256) NOT NULL DEFAULT '',
  `fax` varchar(256) NOT NULL DEFAULT '',
  `email` varchar(256) NOT NULL DEFAULT '',
  `intro` text,
  `create_time` datetime DEFAULT NULL,
  `test` varchar(250) DEFAULT '' COMMENT 'test',
  PRIMARY KEY (`supplier_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='供应商';

SET FOREIGN_KEY_CHECKS=1;
