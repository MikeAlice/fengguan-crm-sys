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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='销售机会';

DELETE FROM `cst_chance`;
/*!40000 ALTER TABLE `cst_chance` DISABLE KEYS */;
INSERT INTO `cst_chance` (`chance_id`, `customer_id`, `linkman_id`, `find_date`, `bill_date`, `salestage`, `money`, `success_rate`, `userID`, `name`, `intro`, `status`, `create_user_id`, `create_time`) VALUES
	(1, 1, '1', '2021-06-03', '2020-07-01', 39, 5000.00, 0, 0, '公司网站开发', '', 1, 1, '2021-06-03 09:32:01');
/*!40000 ALTER TABLE `cst_chance` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='客户信息表';

DELETE FROM `cst_customer`;
/*!40000 ALTER TABLE `cst_customer` DISABLE KEYS */;
INSERT INTO `cst_customer` (`customer_id`, `name`, `customer_no`, `create_user_id`, `owner_user_id`, `create_time`, `next_time`, `conn_time`, `conn_body`, `linkman`, `source`, `grade`, `industry`, `mobile`, `tel`, `address`, `intro`, `needs`) VALUES
	(1, '成都天空之家科技', '', 1, 1, '2021-06-02 16:36:32', '2021-05-12 00:00:00', '2022-12-19 08:45:05', '', '张硒', '网络', '普通客户', '互联网企业', '18525654585', '02812345678', '成都市效园路100', '222', ''),
	(2, '李四', '', 1, 1, '2022-12-19 08:45:40', NULL, '2022-12-19 08:45:40', '', '李总', '网络', '普通客户', '互联网企业', '18525256565', '18525256565', '成都市', '', '');
/*!40000 ALTER TABLE `cst_customer` ENABLE KEYS */;

CREATE TABLE `cst_dict` (
  `dict_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '名字',
  `typetag` varchar(256) NOT NULL DEFAULT '' COMMENT '分类标识',
  `sort` smallint(8) NOT NULL DEFAULT '0',
  `visible` smallint(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`dict_id`)
) ENGINE=InnoDB AUTO_INCREMENT=71 DEFAULT CHARSET=utf8 COMMENT='字典表';

DELETE FROM `cst_dict`;
/*!40000 ALTER TABLE `cst_dict` DISABLE KEYS */;
INSERT INTO `cst_dict` (`dict_id`, `name`, `typetag`, `sort`, `visible`) VALUES
	(1, 'VIP客户', 'level', 3, 1),
	(23, '一般客户', 'level', 4, 1),
	(24, '工业品企业', 'trade', 1, 1),
	(25, '国有经济', 'ecotype', 1, 1),
	(26, '集体经济', 'ecotype', 2, 1),
	(27, '私营经济', 'ecotype', 3, 1),
	(28, '个体经济', 'ecotype', 4, 1),
	(29, '联营经济', 'ecotype', 5, 1),
	(30, '股份制经济', 'ecotype', 6, 1),
	(31, '外商投资经济', 'ecotype', 7, 1),
	(32, '港澳台投资经济', 'ecotype', 8, 1),
	(33, '其它经济', 'ecotype', 9, 1),
	(34, '客户介绍', 'source', 1, 1),
	(35, '电话来访', 'source', 2, 1),
	(36, '独立开发', 'source', 3, 1),
	(37, '电话', 'salemode', 1, 1),
	(38, '初期沟通', 'salestage', 3, 0),
	(39, '立项评估', 'salestage', 2, 0),
	(40, '需求分析', 'salestage', 3, 0),
	(41, '方案制定', 'salestage', 4, 0),
	(42, '商务谈判', 'salestage', 5, 0),
	(43, '合同签订', 'salestage', 6, 0),
	(44, '失单', 'salestage', 7, 0),
	(45, '投诉', 'services', 1, 1),
	(46, '培训', 'services', 2, 1),
	(47, '升级', 'services', 3, 1),
	(48, '互联网企业', 'trade', 1, 1),
	(49, '电话 ', 'servicesmodel', 1, 1),
	(50, 'QQ', 'servicesmodel', 2, 1),
	(51, '服务行业', 'trade', 1, 1),
	(52, '网络资源', 'source', 4, 1),
	(53, '上门', 'salemode', 2, 1),
	(54, '维护', 'services', 4, 1),
	(55, '现场', 'servicesmodel', 3, 1),
	(56, '邮寄', 'salemode', 3, 1),
	(57, '网络', 'salemode', 4, 1),
	(58, '网络', 'servicesmodel', 4, 1),
	(59, '消费品企业', 'trade', 1, 1),
	(60, '原材料企业', 'trade', 1, 1),
	(61, '农业企业', 'trade', 1, 1),
	(63, '不需要', 'talk', 2, 1),
	(64, '挂了', 'talk', 3, 1),
	(65, '空号', 'talk', 4, 1),
	(66, '加微信号', 'talk', 5, 1),
	(67, '白银客户', 'level', 0, 0),
	(68, '钻石客户', 'level', 0, 0);
/*!40000 ALTER TABLE `cst_dict` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COMMENT='字典分类';

DELETE FROM `cst_dict_type`;
/*!40000 ALTER TABLE `cst_dict_type` DISABLE KEYS */;
INSERT INTO `cst_dict_type` (`id`, `typename`, `typedir`, `typetag`, `sort`, `visible`, `intro`, `seotitle`, `keywords`) VALUES
	(1, '客户等级', '', 'level', 0, 1, NULL, '', ''),
	(2, '隶属行业', '', 'trade', 0, 1, NULL, '', ''),
	(3, '经济类型', '', 'ecotype', 0, 1, NULL, '', ''),
	(4, '客户来源', '', 'source', 0, 1, NULL, '', ''),
	(5, '销售方式', '', 'salemode', 0, 1, NULL, '', ''),
	(6, '销售阶段', '', 'salestage', 0, 1, NULL, '', ''),
	(7, '服务类型', '', 'services', 0, 1, NULL, '', ''),
	(8, '服务方式', '', 'servicesmodel', 0, 1, NULL, '', '');
/*!40000 ALTER TABLE `cst_dict_type` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8 COMMENT='客户字段扩展表';

DELETE FROM `cst_field_ext`;
/*!40000 ALTER TABLE `cst_field_ext` DISABLE KEYS */;
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES
	(2, 'cst_customer', 'cst_customer', '客户代表', 'linkman', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:15:19', 1),
	(3, 'cst_customer', 'cst_customer', '客户来源', 'source', 'option', '网络,客户介绍,主动开发', '250', '', 1, 1, 1, 0, '2019-05-28 12:16:35', 1),
	(4, 'cst_customer', 'cst_customer', '客户等级', 'grade', 'option', '普通客户,一般客户,重点客户', '250', '', 1, 1, 1, 0, '2019-05-28 12:17:40', 1),
	(5, 'cst_customer', 'cst_customer', '客户行业', 'industry', 'option', '互联网企业,服务行业,原材料企业', '250', '', 1, 1, 1, 0, '2019-05-28 12:19:04', 1),
	(6, 'cst_customer', 'cst_customer', '联系手机', 'mobile', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:17', 1),
	(7, 'cst_customer', 'cst_customer', '联系电话', 'tel', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:25', 1),
	(8, 'cst_customer', 'cst_customer', '联系地址', 'address', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:33', 1),
	(9, 'cst_customer', 'cst_customer', '客户介绍', 'intro', 'textarea', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:54', 1),
	(10, 'cst_customer', 'cst_customer', '客户需求', 'needs', 'varchar', '2000', '250', '', 1, 0, 0, 0, '2020-10-18 15:36:58', 1),
	(14, 'sup_supplier', 'sup_supplier', 'test', 'test', 'varchar', '', '250', '', 1, 0, 0, 0, '2020-12-29 09:45:10', 1);
/*!40000 ALTER TABLE `cst_field_ext` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COMMENT='项目报备';

DELETE FROM `cst_filing`;
/*!40000 ALTER TABLE `cst_filing` DISABLE KEYS */;
INSERT INTO `cst_filing` (`id`, `cusID`, `linkmanID`, `chanceID`, `userID`, `applicant_userID`, `audit_userID`, `audit_dt`, `title`, `intro`, `support`, `status`, `create_userID`, `adt`) VALUES
	(1, 1, 2, 1, 0, 0, 4, '2017-10-31 14:31:38', '项目报价', '项目介绍', '', 1, 0, '2013-09-09 21:34:14'),
	(4, 1, 2, 2, 0, 5, 4, '2016-06-12 15:02:30', '这是一个不错的项目的呢', '', '', 2, 4, '2013-09-23 10:34:50'),
	(5, 1, 2, 2, 0, 5, 4, '2016-12-22 11:23:32', '这是一个不错的项目的呢', '', '需要技术部门和销售部门的支持和帮助的呢', 3, 4, '2013-09-23 10:35:16');
/*!40000 ALTER TABLE `cst_filing` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='客户联系人';

DELETE FROM `cst_linkman`;
/*!40000 ALTER TABLE `cst_linkman` DISABLE KEYS */;
INSERT INTO `cst_linkman` (`linkman_id`, `customer_id`, `name`, `gender`, `postion`, `tel`, `mobile`, `qicq`, `email`, `zipcode`, `address`, `intro`, `create_user_id`, `create_time`) VALUES
	(1, 1, '张硒', 0, '', '02812345678', '18525654585', '', '', '', '', '', 1, '2021-06-02 16:36:32'),
	(2, 2, '李总', 0, '', '18525256565', '18525256565', '', '', '', '', '', 1, '2022-12-19 08:45:40');
/*!40000 ALTER TABLE `cst_linkman` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='服务记录';

DELETE FROM `cst_service`;
/*!40000 ALTER TABLE `cst_service` DISABLE KEYS */;
INSERT INTO `cst_service` (`service_id`, `customer_id`, `linkman_id`, `services`, `servicesmodel`, `price`, `status`, `service_time`, `tlen`, `content`, `intro`, `create_user_id`, `create_time`) VALUES
	(1, 1, 0, 45, 49, 0, 0, '2021-06-02 00:00:00', '200', '给客户培训指导', '', 1, '2021-06-02 16:37:11');
/*!40000 ALTER TABLE `cst_service` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COMMENT='银行帐户';

DELETE FROM `fin_bank_account`;
/*!40000 ALTER TABLE `fin_bank_account` DISABLE KEYS */;
INSERT INTO `fin_bank_account` (`bank_id`, `name`, `card`, `address`, `holders`, `sort`, `visible`) VALUES
	(1, '工商银行', '9855824408011', '成都大天路456号', '李先生', 2, 1),
	(2, '农业银行', '624404040231212', '成都市犀浦', '李枭', 1, 0);
/*!40000 ALTER TABLE `fin_bank_account` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=armscii8 COMMENT='其它支出类型';

DELETE FROM `fin_expenses_type`;
/*!40000 ALTER TABLE `fin_expenses_type` DISABLE KEYS */;
INSERT INTO `fin_expenses_type` (`id`, `name`, `parentID`, `sort`, `visible`, `intro`) VALUES
	(16, '营业费用', 0, 4, 1, ''),
	(17, '管理费用', 0, 3, 1, ''),
	(18, '办公司开支', 17, 1, 1, ''),
	(19, '日常开支', 17, 2, 1, '2');
/*!40000 ALTER TABLE `fin_expenses_type` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='财务流水';

DELETE FROM `fin_flow_record`;
/*!40000 ALTER TABLE `fin_flow_record` DISABLE KEYS */;
INSERT INTO `fin_flow_record` (`id`, `balance`, `pay_money`, `rece_money`, `bank_id`, `bus_id`, `bus_type`, `intro`, `create_time`, `create_user_id`) VALUES
	(4, -500.50, 500.50, 0.00, 1, 1, 'pos_contract', '', '2021-06-02 18:08:09', 1);
/*!40000 ALTER TABLE `fin_flow_record` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COMMENT='其它收入记录';

DELETE FROM `fin_income_record`;
/*!40000 ALTER TABLE `fin_income_record` DISABLE KEYS */;
INSERT INTO `fin_income_record` (`record_id`, `type_id`, `bank_id`, `money`, `intro`, `happen_date`, `create_user_id`, `create_time`) VALUES
	(1, 19, 2, 100.00, '这个什么费用 呢', '2018-12-25', 4, '2018-12-26 10:50:02'),
	(2, 19, 2, 100.00, '这个什么费用 呢', '2018-12-25', 4, '2018-12-26 10:52:34'),
	(4, 21, 2, 10000.00, '这是投资人加放进来的', '2018-12-31', 4, '2018-12-26 11:38:21'),
	(5, 19, 2, 65400.00, 'fsgsfgsfg', '2018-12-25', 4, '2018-12-28 15:52:45');
/*!40000 ALTER TABLE `fin_income_record` ENABLE KEYS */;

CREATE TABLE `fin_income_type` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `parentID` int(11) NOT NULL DEFAULT '0',
  `sort` int(11) NOT NULL DEFAULT '0',
  `visible` tinyint(2) NOT NULL DEFAULT '1',
  `intro` varchar(1024) CHARACTER SET utf8 DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=armscii8 COMMENT='其它收入类型';

DELETE FROM `fin_income_type`;
/*!40000 ALTER TABLE `fin_income_type` DISABLE KEYS */;
INSERT INTO `fin_income_type` (`id`, `name`, `parentID`, `sort`, `visible`, `intro`) VALUES
	(16, '营业外收入5', 0, 3, 1, '这是其它之外的收入'),
	(18, '办公司开支', 0, 2, 1, ''),
	(19, '销售收入', 18, 3, 1, '还可以吧'),
	(21, '其它分类收入', 0, 1, 1, '杂七杂入');
/*!40000 ALTER TABLE `fin_income_type` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf8 COMMENT='开票记录、';

DELETE FROM `fin_invoice_pay`;
/*!40000 ALTER TABLE `fin_invoice_pay` DISABLE KEYS */;
INSERT INTO `fin_invoice_pay` (`record_id`, `contract_id`, `contract_name`, `customer_id`, `customer_name`, `money`, `pay_date`, `stages`, `invoice_no`, `name`, `bus_type`, `intro`, `create_time`, `create_user_id`) VALUES
	(11, 16, '0', 1, '0', 100, '2017-05-22', 1, '212312313', '测试了吧-这是修改的内容', 'sal_order', '', '2017-05-22 22:01:49', 4),
	(12, 6, '0', 9, '0', 2600, '2017-05-22', 1, '', '100', 'sal_contract', '', '2017-05-22 22:13:17', 4),
	(13, 6, '0', 9, '0', 2600, '2017-05-22', 1, '', '100', 'sal_contract', '', '2017-05-22 22:13:25', 4),
	(14, 6, '0', 9, '0', 2600, '2017-05-22', 1, '', '100', 'sal_contract', '', '2017-05-22 22:15:01', 4),
	(22, 8, '0', 11, '0', 4770, '2017-11-01', 1, '', '合同', 'sal_contract', '4500合同金额，补了270的发票', '2017-11-15 15:04:44', 4);
/*!40000 ALTER TABLE `fin_invoice_pay` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8 COMMENT='收票记录';

DELETE FROM `fin_invoice_rece`;
/*!40000 ALTER TABLE `fin_invoice_rece` DISABLE KEYS */;
INSERT INTO `fin_invoice_rece` (`record_id`, `contract_id`, `supplier_id`, `contract_name`, `supplier_name`, `money`, `rece_date`, `stages`, `name`, `invoice_no`, `intro`, `create_time`, `create_user_id`) VALUES
	(21, 3, 1, '', '山西太原', 5000, '2020-03-27', 1, '货款', 'XWR', '', '2020-03-27 14:53:45', 1);
/*!40000 ALTER TABLE `fin_invoice_rece` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COMMENT='付款计划表';

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
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=utf8 COMMENT='付款记录';

DELETE FROM `fin_pay_record`;
/*!40000 ALTER TABLE `fin_pay_record` DISABLE KEYS */;
INSERT INTO `fin_pay_record` (`record_id`, `plan_id`, `contract_id`, `contract_name`, `supplier_id`, `supplier_name`, `bank_id`, `pay_date`, `money`, `zero_money`, `stages`, `intro`, `create_time`, `create_user_id`) VALUES
	(47, 0, 1, '天河一期', 12, '上海八达', 0, '2021-06-02', 500.50, 0.00, 1, '', '2021-06-02 18:08:09', 1);
/*!40000 ALTER TABLE `fin_pay_record` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8 COMMENT='计划回款表';

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
) ENGINE=InnoDB AUTO_INCREMENT=133 DEFAULT CHARSET=utf8 COMMENT='回款记录';

DELETE FROM `fin_rece_record`;
/*!40000 ALTER TABLE `fin_rece_record` DISABLE KEYS */;
INSERT INTO `fin_rece_record` (`record_id`, `contract_id`, `contract_name`, `plan_id`, `customer_id`, `customer_name`, `bank_id`, `money`, `zero_money`, `back_date`, `stages`, `bus_type`, `intro`, `create_time`, `create_user_id`) VALUES
	(28, 6, '', 0, 9, '', 1, 1300.00, 0.00, '2017-03-31', 1, '0', '收了50%预付款', '2017-04-11 14:43:59', 4),
	(29, 6, '', 0, 9, '', 1, 1300.00, 0.00, '2017-05-03', 2, '0', '已经结清尾款', '2017-05-03 17:43:32', 4),
	(30, 8, '', 0, 11, '', 1, 900.00, 0.00, '2017-04-24', 1, '0', '预付20%，首页确定后30%', '2017-05-03 20:58:29', 4),
	(31, 8, '', 0, 11, '', 1, 100.00, 0.00, '2017-05-03', 2, '0', '', '2017-05-03 21:57:45', 4),
	(32, 8, '', 0, 11, '', 1, 100.00, 0.00, '2017-05-22', 3, 'sal_contract', '', '2017-05-22 15:52:27', 4),
	(34, 9, '', 0, 12, '', 1, 800.00, 0.00, '2017-05-15', 1, 'sal_contract', '', '2017-06-19 09:36:32', 4),
	(35, 10, '', 0, 13, '', 1, 2300.00, 0.00, '2017-06-26', 1, 'sal_contract', '', '2017-06-26 21:18:26', 4),
	(36, 11, '', 0, 17, '', 1, 2300.00, 0.00, '2017-06-26', 1, 'sal_contract', '', '2017-06-26 21:18:48', 4),
	(37, 12, '', 0, 18, '', 1, 1000.00, 0.00, '2017-06-30', 1, 'sal_contract', '网站预付款', '2017-06-30 12:29:28', 4),
	(38, 12, '', 0, 18, '', 1, 600.00, 0.00, '2017-08-02', 2, 'sal_contract', '推广按月支付8月费用', '2017-08-14 18:13:14', 4),
	(39, 13, '', 0, 13151, '', 1, 2400.00, 0.00, '2017-08-26', 1, 'sal_contract', '预付30%', '2017-08-30 08:41:22', 4),
	(40, 12, '', 0, 18, '', 1, 600.00, 0.00, '2017-09-02', 3, 'sal_contract', '', '2017-09-03 11:15:12', 4),
	(41, 12, '', 0, 18, '', 1, 600.00, 0.00, '2017-10-09', 4, 'sal_contract', '推广费用10月，600元', '2017-10-16 09:40:55', 4),
	(42, 13, '', 0, 13151, '', 1, 3200.00, 0.00, '2017-09-29', 2, 'sal_contract', '网站第二款40%费用3200', '2017-10-16 09:41:53', 4),
	(43, 8, '', 0, 11, '', 1, 1150.00, 0.00, '2017-05-17', 2, 'sal_contract', '第2批款，1150', '2017-10-16 09:46:13', 4),
	(44, 15, '', 0, 295, '', 1, 1000.00, 0.00, '2017-10-26', 1, 'sal_contract', '', '2017-10-31 12:00:46', 4),
	(45, 8, '', 0, 11, '', 1, 2250.00, 0.00, '2017-11-01', 3, 'sal_contract', '尾款，补发票，270', '2017-11-02 15:59:38', 4),
	(46, 16, '', 0, 13155, '', 1, 1000.00, 0.00, '2017-11-06', 1, 'sal_contract', '预付款', '2017-11-14 17:18:31', 4),
	(47, 16, '', 0, 13155, '', 1, 1500.00, 0.00, '2017-11-26', 2, 'sal_contract', '尾款', '2017-12-07 16:43:21', 4),
	(48, 12, '', 0, 18, '', 1, 600.00, 0.00, '2017-11-04', 4, 'sal_contract', 'SEO续费', '2017-12-07 16:46:25', 4),
	(49, 19, '', 0, 967, '', 1, 900.00, 0.00, '2017-12-21', 1, 'sal_contract', '', '2017-12-21 11:53:16', 4),
	(50, 29, '', 0, 274, '', 1, 1500.00, 0.00, '2018-01-08', 1, 'sal_contract', '转帐', '2018-01-10 13:09:26', 4),
	(51, 21, '', 0, 289, '', 1, 2500.00, 0.00, '2018-01-09', 1, 'sal_contract', '支付宝收帐', '2018-01-10 13:09:57', 4),
	(52, 18, '', 0, 13156, '', 1, 1000.00, 0.00, '2018-01-12', 1, 'sal_contract', '', '2018-01-16 17:39:03', 4),
	(53, 30, '', 0, 289, '', 1, 800.00, 0.00, '2018-02-25', 1, 'sal_contract', '', '2018-02-28 11:58:06', 4),
	(54, 17, '', 0, 13156, '', 1, 1000.00, 0.00, '2018-01-19', 1, 'sal_contract', '', '2018-02-28 12:17:40', 4),
	(55, 13, '', 0, 13151, '', 1, 2000.00, 0.00, '2018-02-07', 3, 'sal_contract', '', '2018-02-28 12:20:51', 4),
	(56, 32, '', 0, 13156, '', 1, 1000.00, 0.00, '2018-03-05', 1000, 'sal_contract', '', '2018-03-07 14:38:50', 4),
	(57, 31, '', 0, 232, '', 1, 800.00, 0.00, '2018-03-05', 1, 'sal_contract', '', '2018-03-07 14:39:32', 4),
	(58, 34, '', 0, 9, '', 1, 600.00, 0.00, '2018-03-26', 1, 'sal_contract', '', '2018-03-26 13:17:08', 4),
	(59, 35, '', 0, 254, '', 1, 1000.00, 0.00, '2018-03-26', 1, 'sal_contract', '网站一年续费', '2018-03-26 16:59:24', 4),
	(60, 37, '', 0, 12, '', 1, 600.00, 0.00, '2018-04-24', 1, 'sal_contract', '', '2018-04-26 09:46:12', 4),
	(61, 36, '', 0, 11, '', 1, 3600.00, 0.00, '2018-04-18', 1, 'sal_contract', '三年续费', '2018-04-26 09:46:57', 4),
	(62, 38, '', 0, 289, '', 1, 800.00, 0.00, '2018-06-10', 1, 'sal_contract', '', '2018-06-24 20:46:08', 4),
	(63, 41, '', 0, 289, '', 1, 800.00, 0.00, '2018-07-17', 1, 'sal_contract', '18年续费', '2018-07-18 14:28:11', 4),
	(64, 39, '', 0, 17, '', 1, 1500.00, 0.00, '2018-06-25', 1, 'sal_contract', '必是信任科技 ', '2018-07-18 14:28:54', 4),
	(65, 40, '', 0, 13, '', 1, 1500.00, 0.00, '2018-06-25', 1, 'sal_contract', '', '2018-07-18 14:29:29', 4),
	(66, 42, '', 0, 254, '', 1, 1800.00, 0.00, '2018-08-01', 1, 'sal_contract', '还有700空间费用 ', '2018-07-18 14:29:29', 4),
	(67, 44, '', 0, 13160, '', 1, 5000.00, 0.00, '2018-05-15', 1, 'sal_contract', '', '2018-07-18 14:29:29', 4),
	(68, 46, '', 0, 13161, '', 1, 5000.00, 0.00, '2018-09-10', 1, 'sal_contract', '预付款', '2018-10-09 15:41:58', 4),
	(69, 49, '', 0, 13163, '', 1, 10000.00, 0.00, '2018-09-25', 1, 'sal_contract', '一期费用', '2018-10-09 15:42:51', 4),
	(70, 48, '', 0, 13162, '', 1, 2600.00, 0.00, '2018-09-02', 1, 'sal_contract', '定制费用 ', '2018-10-09 15:43:17', 4),
	(71, 47, '', 0, 13155, '', 1, 2000.00, 0.00, '2018-09-20', 1, 'sal_contract', '定金费用', '2018-10-09 15:44:10', 4),
	(72, 51, '', 0, 295, '', 1, 1200.00, 0.00, '2018-10-19', 1, 'sal_contract', '', '2018-10-19 17:48:18', 4),
	(73, 43, '', 0, 289, '', 1, 2500.00, 0.00, '2018-10-18', 1, 'sal_contract', '开了收据了的，下次有可能要发票', '2018-10-19 17:49:53', 4),
	(102, 67, '金福机电续费', 0, 12, '金福机电维修中心', 0, 680.00, 0.00, '2019-05-30', 1, '0', '', '2019-05-01 13:30:52', 1),
	(98, 61, '铭丰资本续费', 0, 274, '铭丰资本', 0, 1500.00, 0.00, '2019-01-09', 1, '0', '', '2019-01-10 14:42:54', 1),
	(99, 62, '尚美居续费', 0, 232, '尚美居装饰公司', 0, 800.00, 0.00, '2019-02-28', 1, '0', '', '2019-03-06 19:09:26', 1),
	(100, 63, 'CRM功能定制', 0, 13175, '车险-CRM定制', 0, 1000.00, 0.00, '2019-03-01', 1, '0', '', '2019-03-12 16:47:54', 1),
	(101, 63, 'CRM功能定制', 0, 13175, '车险-CRM定制', 0, 4000.00, 0.00, '2019-03-13', 2, '0', '', '2019-03-13 20:30:47', 1),
	(103, 65, '万籁阁续费', 0, 289, '成都瞳创广告', 0, 800.00, 0.00, '2019-05-15', 1, '0', '', '2019-05-01 13:33:12', 1),
	(104, 68, '瞳创广告官网续费', 0, 289, '成都瞳创广告', 0, 800.00, 0.00, '2019-05-27', 1, '0', '', '2019-05-28 13:45:12', 1),
	(105, 76, '吉庆实业网站制作', 0, 13327, '吉庆实业发展有限公司', 0, 3600.00, 0.00, '2019-07-30', 1, '0', '', '2019-07-30 10:50:02', 1),
	(106, 73, '巨能特种车', 0, 13326, '巨能汽车销售', 0, 2300.00, 0.00, '2019-04-15', 1, '0', '', '2019-07-30 10:51:29', 1),
	(107, 73, '巨能特种车', 0, 13326, '巨能汽车销售', 0, 2300.00, 0.00, '2019-07-03', 2, '0', '', '2019-07-30 10:52:16', 1),
	(108, 72, '熊猫兼兼网站', 0, 13325, '熊猫兼兼', 0, 2000.00, 0.00, '2019-04-07', 1, '0', '', '2019-07-30 10:52:52', 1),
	(109, 72, '熊猫兼兼网站', 0, 13325, '熊猫兼兼', 0, 1500.00, 0.00, '2019-05-09', 2, '0', '', '2019-07-30 10:53:22', 1),
	(110, 74, '商标交易网站', 0, 13320, '李健', 0, 3000.00, 0.00, '2019-06-25', 1, '0', '', '2019-07-30 10:54:09', 1),
	(111, 45, '图拉博网站', 0, 13156, '零起点形象设计', 0, 1000.00, 0.00, '2018-12-20', 1, '0', '', '2019-09-08 18:05:55', 1),
	(112, 77, '善本堂健康调查系统', 0, 13156, '零起点形象设计', 0, 7800.00, 0.00, '2019-08-30', 1, '0', '', '2019-09-08 18:06:26', 1),
	(113, 78, '泰建筑劳续费', 0, 17, '东泰劳务公司', 0, 1500.00, 0.00, '2019-08-30', 1, '0', '', '2019-09-08 18:09:55', 1),
	(114, 79, '堰汇劳务续费', 0, 13, '四川堰汇建筑劳务公司', 0, 1500.00, 0.00, '2019-08-30', 1, '0', '', '2019-09-08 18:10:12', 1),
	(115, 64, '企业网站仿制', 0, 13176, '仿制网站-王先生', 0, 1080.00, 0.00, '2019-07-17', 1, '0', '', '2019-09-08 18:10:45', 1),
	(116, 70, '知行天下旅游网续费', 0, 13163, '知行天下旅游', 0, 1600.00, 0.00, '2019-06-26', 1, '0', '', '2019-09-08 18:11:33', 1),
	(117, 69, '万经堂续费', 0, 289, '成都瞳创广告', 0, 800.00, 0.00, '2019-06-26', 1, '0', '', '2019-09-08 18:12:21', 1),
	(118, 75, '二维码收款', 0, 13176, '', 0, 600.00, 0.00, '2019-07-02', 1, '0', '', '2019-09-08 21:16:55', 1),
	(119, 66, '直线官网续费', 0, 254, '', 0, 1000.00, 0.00, '2019-04-23', 1, '0', '', '2019-09-08 21:32:24', 1),
	(120, 82, '旭兴官网建设', 0, 13328, '', 0, 4000.00, 1000.00, '2019-08-26', 1, '0', '', '2019-09-09 08:38:11', 1),
	(121, 83, '旅游门市管理系统', 0, 13329, '', 0, 4000.00, 0.00, '2019-08-17', 1, '0', '', '2019-09-09 08:41:54', 1),
	(122, 83, '旅游门市管理系统', 0, 13329, '', 0, 8000.00, 0.00, '2019-09-29', 3, '0', '', '2019-09-29 18:07:33', 1),
	(123, 84, '足博仕商城续费', 0, 13161, '', 0, 1600.00, 0.00, '2019-09-10', 1, '0', '', '2019-09-29 18:08:30', 1),
	(124, 74, '商标交易网站', 0, 13320, '', 0, 3000.00, 0.00, '2019-07-17', 2, '0', '', '2019-09-29 18:09:25', 1),
	(125, 85, '华西建筑设计院续费', 0, 289, '', 0, 800.00, 0.00, '2019-10-12', 1, '0', '', '2019-10-21 14:10:58', 1),
	(126, 86, '正源康柠檬网站续费', 0, 295, '', 0, 1200.00, 0.00, '2019-10-29', 1, '0', '', '2019-10-29 16:52:07', 1),
	(127, 87, '全正农业续费', 0, 295, '', 0, 1200.00, 0.00, '2019-10-29', 1, '0', '', '2019-10-29 16:52:35', 1),
	(128, 88, '标筑广告续费', 0, 13174, '', 0, 800.00, 0.00, '2019-12-27', 1, '0', '', '2019-12-28 10:15:24', 1),
	(129, 89, '多测测授权', 0, 13331, '', 0, 500.00, 0.00, '2020-01-15', 1, '0', '', '2020-01-15 15:34:43', 1),
	(130, 90, '民航电子续费', 0, 254, '', 0, 1400.00, 0.00, '2020-01-15', 1, '0', '', '2020-01-15 15:35:30', 1),
	(131, 91, '铭丰资本续费', 0, 274, '', 0, 1500.00, 0.00, '2020-01-15', 1, '0', '', '2020-01-15 15:35:47', 1),
	(132, 92, '直线官网续费', 0, 254, '', 0, 1000.00, 0.00, '2020-03-10', 1, '0', '', '2020-03-21 13:47:01', 1);
/*!40000 ALTER TABLE `fin_rece_record` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=78 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=16554 COMMENT='商品表';

DELETE FROM `fly_goods`;
/*!40000 ALTER TABLE `fly_goods` DISABLE KEYS */;
INSERT INTO `fly_goods` VALUES (76, '老人鞋子', 1, 4, 0, 0, 0, 0, '', 0, 1, 200.00, 160.00, 100.00, 0.00, 0.00, 0, 0, 0.00, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, '/upload/images/190903/20190903095648913.jpg', '老人鞋子', '', '老人鞋子', '<p>老人鞋子老人鞋子老人鞋子</p>', '', 0, 0, 0, 0, 1, 1, NULL, NULL, NULL, NULL, 0, 0, '', 0.00, 0.00, 1, NULL, NULL, NULL, NULL, 0, '0000-00-00 00:00:00', '2019-09-03 09:57:49', '2020-03-10 14:04:42', 0, 0, 0, '', '', '', '', 0, 0, 0, 0, 1, 0.00, '');
INSERT INTO `fly_goods` VALUES (77, '精品商品', 1, 4, 0, 0, 0, 0, '', 0, 1, 100.00, 100.00, 100.00, 0.00, 0.00, 0, 0, 0.00, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, '', '系统', '', '好的呀', '', '', 0, 0, 0, 0, 1, 100, NULL, NULL, NULL, NULL, 0, 0, '', 0.00, 0.00, 1, NULL, NULL, NULL, NULL, 0, '0000-00-00 00:00:00', '2020-04-05 14:56:55', '0000-00-00 00:00:00', 0, 0, 0, '', '', '', '', 0, 0, 0, 0, 1, 0.00, '');
/*!40000 ALTER TABLE `fly_goods` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=16384 COMMENT='商品相关属性';

DELETE FROM `fly_goods_attr`;
/*!40000 ALTER TABLE `fly_goods_attr` DISABLE KEYS */;
INSERT INTO `fly_goods_attr` (`attr_id`, `attr_name`, `visible`, `spec_id_array`, `sort`, `create_time`, `modify_time`, `brand_id_array`) VALUES
	(1, 'IDC租用', 1, '', 3, 1536331561, 1536333703, ''),
	(28, '硬盘', 1, '', 1, 0, 0, ''),
	(27, '原材料', 1, '', 0, 0, 0, ''),
	(29, '硬盘', 1, '', 1, 0, 0, '');
/*!40000 ALTER TABLE `fly_goods_attr` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=315 COMMENT='商品和属性关联表\r\n';

DELETE FROM `fly_goods_attr_relation`;
/*!40000 ALTER TABLE `fly_goods_attr_relation` DISABLE KEYS */;
INSERT INTO `fly_goods_attr_relation` (`attr_relation_id`, `shop_id`, `goods_id`, `attr_id`, `attr_name`, `attr_value_id`, `attr_value_name`, `attr_value_data`, `sort`, `create_time`) VALUES
	(9, 0, 24, 5, '', 1, '100', '红色', 0, 1537101643),
	(10, 0, 24, 6, '', 4, '101', '黑色', 0, 1537101643),
	(11, 0, 24, 7, '', 2, '102', '白色', 1, 1537101643),
	(12, 0, 24, 8, '', 3, '103', '大红色', 2, 1537101643);
/*!40000 ALTER TABLE `fly_goods_attr_relation` ENABLE KEYS */;

CREATE TABLE `fly_goods_attr_value` (
  `attr_value_id` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '属性值ID',
  `attr_id` int(11) NOT NULL DEFAULT '0' COMMENT '属性ID',
  `attr_value_name` varchar(50) NOT NULL DEFAULT '' COMMENT '属性值名称',
  `attr_value_data` varchar(1000) NOT NULL DEFAULT '' COMMENT '属性对应相关数据',
  `type` int(11) NOT NULL DEFAULT '1' COMMENT '属性对应输入类型1.直接2.单选3.多选',
  `sort` int(11) NOT NULL DEFAULT '1999' COMMENT '排序号',
  `is_search` tinyint(1) NOT NULL DEFAULT '1' COMMENT '是否使用',
  PRIMARY KEY (`attr_value_id`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=4096 COMMENT='商品属性值';

DELETE FROM `fly_goods_attr_value`;
/*!40000 ALTER TABLE `fly_goods_attr_value` DISABLE KEYS */;
INSERT INTO `fly_goods_attr_value` (`attr_value_id`, `attr_id`, `attr_value_name`, `attr_value_data`, `type`, `sort`, `is_search`) VALUES
	(19, 1, '设备类型', '1U设备\r\n2U设备', 1, 0, 1),
	(18, 27, '化纤', '国内\r\n国外\r\n华中', 1, 1, 1),
	(17, 27, '绵薄', '新疆\r\n内地\r\n沿海', 1, 0, 1),
	(12, 26, '时尚款', '', 1, 0, 1),
	(13, 26, '经典款', '', 1, 1, 1),
	(14, 26, '复古款', '', 1, 2, 1),
	(20, 1, '带宽大小', '100M\r\n200M\r\n300M', 1, 2, 1),
	(21, 28, '大小', '250G\r\n512G', 3, 0, 1),
	(22, 28, '颜色', '黑色\r\n白色\r\n蓝色', 3, 1, 1),
	(23, 29, '大小', '250G\r\n512G', 3, 0, 1),
	(24, 29, '颜色', '黑色\r\n白色\r\n蓝色', 3, 1, 1);
/*!40000 ALTER TABLE `fly_goods_attr_value` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=1024 COMMENT='品牌表';

DELETE FROM `fly_goods_brand`;
/*!40000 ALTER TABLE `fly_goods_brand` DISABLE KEYS */;
INSERT INTO `fly_goods_brand` (`brand_id`, `shop_id`, `brand_name`, `brand_initial`, `brand_pic`, `brand_recommend`, `sort`, `brand_category_name`, `category_id_array`, `brand_ads`, `category_name`, `category_id_1`, `category_id_2`, `category_id_3`) VALUES
	(1, 0, '足博仕', 'Z', '/upload/images/190325/20190325104438170.gif', 1, 3, '', '', '', '', 0, 0, 0),
	(2, 0, '零起飞网络', 'L', '/upload/images/181117/20181117223043637.jpg', 1, 1, '', '', '', '', 0, 0, 0);
/*!40000 ALTER TABLE `fly_goods_brand` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=244 COMMENT='商品分类表';

DELETE FROM `fly_goods_category`;
/*!40000 ALTER TABLE `fly_goods_category` DISABLE KEYS */;
INSERT INTO `fly_goods_category` (`category_id`, `category_name`, `short_name`, `parent_id`, `level`, `visible`, `attr_id`, `attr_name`, `keywords`, `description`, `sort`, `category_pic`, `pc_custom_template`, `wap_custom_template`) VALUES
	(1, '49元促销区1', '49元促销区', 0, 1, 1, 0, '', '零起飞网站建设', '这是一个不错的栏目哟', 2, 'upload/goods_category/1536765526.jpg', '', ''),
	(2, '轻爽鞋专区', '轻爽鞋专区', 0, 1, 1, 0, '', '', '', 3, 'upload/goods_category/1536765621.jpg', '', ''),
	(3, '安全鞋系列', '安全鞋系列', 0, 1, 1, 0, '', '', '', 4, 'upload/goods_category/1536765650.jpg', '', ''),
	(4, '舒爽鞋专区', '舒爽鞋专区', 0, 1, 1, 0, '', '', '', 1, 'upload/goods_category/1536765712.jpg', '', ''),
	(5, '男款专区', '男款专区', 1, 1, 1, 0, '', '网站建设,企业网站建设', '', 0, '', '', ''),
	(6, '女款专区', '女款专区', 1, 1, 1, 0, '', '网站建设,企业网站建设', '', 1, '', '', ''),
	(8, '女款专区', '女款专区', 5, 1, 1, 0, '', '网站建设,企业网站建设', '', 1, '', '', ''),
	(9, '老年版', '1', 3, 0, 1, 0, '', '111', '11', 1, '', '', '');
/*!40000 ALTER TABLE `fly_goods_category` ENABLE KEYS */;

CREATE TABLE `fly_goods_img` (
  `img_id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'ID',
  `goods_id` int(11) NOT NULL DEFAULT '0' COMMENT '商品ID',
  `img_path` varchar(256) NOT NULL DEFAULT '' COMMENT '图片路径',
  PRIMARY KEY (`img_id`)
) ENGINE=InnoDB AUTO_INCREMENT=112 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=16384 COMMENT='商品图片';

DELETE FROM `fly_goods_img`;
/*!40000 ALTER TABLE `fly_goods_img` DISABLE KEYS */;
INSERT INTO `fly_goods_img` (`img_id`, `goods_id`, `img_path`) VALUES
	(28, 31, '/upload/images/181111/20181111113539236.jpg'),
	(29, 31, '/upload/images/181111/20181111113539869.jpg'),
	(30, 31, '/upload/images/181111/20181111113539197.png'),
	(31, 31, '/upload/images/181111/20181111113540228.jpg'),
	(32, 31, '/upload/images/181111/20181111113540894.jpg'),
	(33, 31, '/upload/images/181111/20181111113540845.jpg'),
	(34, 31, '/upload/images/181111/20181111113540355.jpg'),
	(35, 31, '/upload/images/181111/20181111113540144.jpg'),
	(36, 34, '/upload/images/181111/20181111114053291.jpg'),
	(37, 34, '/upload/images/181111/20181111114053243.jpg'),
	(38, 34, '/upload/images/181111/20181111114054476.jpg'),
	(39, 34, '/upload/images/181111/20181111114054536.png'),
	(40, 35, '/upload/images/181111/20181111114053291.jpg'),
	(41, 35, '/upload/images/181111/20181111114053243.jpg'),
	(42, 35, '/upload/images/181111/20181111114054476.jpg'),
	(43, 35, '/upload/images/181111/20181111114054536.png'),
	(44, 36, '/upload/images/181115/20181115092621879.jpg'),
	(45, 38, '/upload/images/181115/20181115170329429.jpg'),
	(46, 38, '/upload/images/181115/20181115170329902.jpg'),
	(47, 39, '/upload/images/181115/20181115200902424.jpg'),
	(48, 39, '/upload/images/181115/20181115200903125.jpg'),
	(49, 39, '/upload/images/181115/20181115200903715.jpg'),
	(50, 52, '/upload/images/181117/20181117211132635.jpg'),
	(51, 52, 'Array'),
	(52, 52, ''),
	(53, 52, 'Array'),
	(54, 52, 'Array'),
	(55, 52, 'Array'),
	(56, 52, 'Array'),
	(57, 53, '/upload/images/181117/20181117211132635.jpg'),
	(58, 54, '/upload/images/181117/20181117211132635.jpg'),
	(59, 55, '/upload/images/181117/20181117211132635.jpg'),
	(60, 58, '/upload/images/181117/20181117211723880.jpg'),
	(61, 59, '/upload/images/181117/20181117211723880.jpg'),
	(62, 60, '/upload/images/181117/20181117211723880.jpg'),
	(63, 61, '/upload/images/181117/20181117211723880.jpg'),
	(64, 62, '/upload/images/181117/20181117211723880.jpg'),
	(65, 63, '/upload/images/181117/20181117211723880.jpg'),
	(66, 64, '/upload/images/181117/20181117211723880.jpg'),
	(67, 65, '/upload/images/181117/20181117211723880.jpg'),
	(68, 66, '/upload/images/181117/20181117211723880.jpg'),
	(69, 67, '/upload/images/181117/20181117211723880.jpg'),
	(70, 68, '/upload/images/181117/20181117211723880.jpg'),
	(71, 69, '/upload/images/181117/20181117211723880.jpg'),
	(85, 70, '/upload/images/181203/20181203103351697.jpg'),
	(84, 70, '/upload/images/181203/20181203103351171.jpg'),
	(83, 70, '/upload/images/181203/20181203103351715.jpg'),
	(82, 70, '/upload/images/181203/20181203103350936.jpg'),
	(81, 70, '/upload/images/181117/20181117211723880.jpg'),
	(97, 71, '/upload/images/190326/20190326143838513.gif'),
	(88, 72, '/upload/images/190326/20190326151309691.gif'),
	(103, 73, '/upload/images/190326/20190326151309691.gif'),
	(104, 74, '/upload/images/190902/20190902232154643.jpg'),
	(105, 74, '/upload/images/190902/20190902232154290.jpg'),
	(106, 74, '/upload/images/190902/20190902232154829.jpg'),
	(111, 76, '/upload/images/190903/20190903095648913.jpg');
/*!40000 ALTER TABLE `fly_goods_img` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=481 COMMENT='商品sku规格价格信息表';

DELETE FROM `fly_goods_sku`;
/*!40000 ALTER TABLE `fly_goods_sku` DISABLE KEYS */;
INSERT INTO `fly_goods_sku` VALUES (22, 76, '老人鞋子', '颜色:白色,尺寸:35码', '颜色:白色,尺寸:35码', '', 200.00, 300.00, 0.00, 0.00, -200.00, -800.00, 5100.00, 3200.00, 0, '', '', '2020-03-10 14:04:42', '2020-03-10 14:04:42');
INSERT INTO `fly_goods_sku` VALUES (23, 76, '老人鞋子', '颜色:白色,尺寸:40码', '颜色:白色,尺寸:40码', '', 200.00, 160.00, 0.00, 0.00, 70.00, 700.00, 0.00, 0.00, 0, '', '', '2020-03-10 14:04:42', '2020-03-10 14:04:42');
INSERT INTO `fly_goods_sku` VALUES (24, 76, '老人鞋子', '颜色:黑色,尺寸:35码', '颜色:黑色,尺寸:35码', '', 200.00, 160.00, 0.00, 0.00, 93.33, 840.00, 0.00, 0.00, 0, '', '', '2020-03-10 14:04:42', '2020-03-10 14:04:42');
INSERT INTO `fly_goods_sku` VALUES (25, 76, '老人鞋子', '颜色:黑色,尺寸:40码', '颜色:黑色,尺寸:40码', '', 200.00, 150.00, 0.00, 0.00, 94.44, 850.00, 2850.00, 550.00, 0, '', '', '2020-03-10 14:04:42', '2020-03-10 14:04:42');
/*!40000 ALTER TABLE `fly_goods_sku` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=3276 COMMENT='商品属性（规格）表';

DELETE FROM `fly_goods_spec`;
/*!40000 ALTER TABLE `fly_goods_spec` DISABLE KEYS */;
INSERT INTO `fly_goods_spec` (`spec_id`, `shop_id`, `spec_name`, `visible`, `sort`, `show_type`, `create_time`, `is_screen`, `spec_des`, `goods_id`) VALUES
	(2, 0, '尺码', 1, 3, 1, '0000-00-00 00:00:00', 1, '', 0),
	(3, 0, '颜色', 1, 1, 1, NULL, 1, '', 0),
	(5, 0, '尺寸', 1, 2, 1, NULL, 1, '', 0);
/*!40000 ALTER TABLE `fly_goods_spec` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=1092 COMMENT='商品规格值模版表';

DELETE FROM `fly_goods_spec_value`;
/*!40000 ALTER TABLE `fly_goods_spec_value` DISABLE KEYS */;
INSERT INTO `fly_goods_spec_value` (`spec_value_id`, `spec_id`, `spec_value_name`, `spec_value_data`, `is_visible`, `sort`, `create_time`, `goods_id`) VALUES
	(12, 2, '35', '', 1, 255, '0000-00-00 00:00:00', 0),
	(13, 2, '36', '', 1, 255, '0000-00-00 00:00:00', 0),
	(14, 2, '37', '', 1, 255, '0000-00-00 00:00:00', 0),
	(15, 2, '42', '', 1, 255, '0000-00-00 00:00:00', 0),
	(22, 3, '天空色', '', 0, 3, NULL, 0),
	(21, 3, '黑色', '', 0, 2, NULL, 0),
	(20, 3, '白色', '', 0, 1, NULL, 0),
	(30, 5, '35码', '', 0, 0, NULL, 0),
	(31, 5, '40码', '', 0, 1, NULL, 0);
/*!40000 ALTER TABLE `fly_goods_spec_value` ENABLE KEYS */;

CREATE TABLE `fly_sys_area` (
  `id` int(4) NOT NULL AUTO_INCREMENT,
  `parentID` int(4) NOT NULL DEFAULT '0',
  `sort` int(4) NOT NULL DEFAULT '0',
  `name` varchar(12) NOT NULL DEFAULT '',
  `type` int(1) NOT NULL DEFAULT '0',
  `visible` int(1) NOT NULL DEFAULT '0',
  `intro` varchar(256) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='地区表';
-- zocrm_sys.fly_sys_menu_role definition

CREATE TABLE `fly_sys_menu_role` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `menu_id` int(10) NOT NULL COMMENT '是menu表的id',
  `role_id` int(10) NOT NULL COMMENT '是role表的id',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
DELETE FROM `fly_sys_area`;
/*!40000 ALTER TABLE `fly_sys_area` DISABLE KEYS */;
INSERT INTO `fly_sys_area` (`id`, `parentID`, `sort`, `name`, `type`, `visible`, `intro`) VALUES
	(1, 0, 11, '华南地区', 0, 1, '111'),
	(2, 1, 22, '222', 0, 1, '22');
/*!40000 ALTER TABLE `fly_sys_area` ENABLE KEYS */;

CREATE TABLE `fly_sys_config` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) NOT NULL DEFAULT '',
  `varname` varchar(128) NOT NULL DEFAULT '',
  `value` text,
  `type` varchar(50) NOT NULL DEFAULT '' COMMENT '字段类型',
  `groupid` tinyint(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=47 DEFAULT CHARSET=utf8 COMMENT='系统配置表';

DELETE FROM `fly_sys_config`;
/*!40000 ALTER TABLE `fly_sys_config` DISABLE KEYS */;
INSERT INTO `fly_sys_config` (`id`, `name`, `varname`, `value`, `type`, `groupid`) VALUES
	(1, '系统域名 ', 'basehost', 'http://www.07fly.xyz', 'string', 0),
	(2, '系统标题', 'title', '首页', 'string', 0),
	(3, '系统名称', 'name', '零起飞客户关系管理系统-07fly-CRM ', 'string', 0),
	(4, '系统版权', 'powerby', '网站版信息', 'bstring', 0),
	(5, '公司名称', 'companyname', '成都零起飞网络', 'string', 0),
	(6, '公司简介', 'companydesc', '<h4>零起飞介绍:</h4><p>服务项目：网站建设，域名空间，优化排名，网站推广，网站维护，软件定制等业务。 我们是技术性团队，只用作品说话。</p><p>服务宗旨：以质量求生存，以服务谋发展，以信誉创品牌</p><h4><br/></h4><h4>零起飞开源项目:</h4><p><a href="https://gitee.com/07fly/FLY-CRM" target="_blank">客户关系管理系统-（07FLY-CRM）</a><a href="//shang.qq.com/wpa/qunwpa?idkey=b587b0c97d7a7e17b805c05f5c2e4aa1a2a16958edee01c2d5208ac675e6d4aa" target="_blank">(QQ)交流群：575085787</a></p><p><a href="https://gitee.com/07fly/lingqifei" target="_blank">企业建站管理系统-（07FLY-CMS）</a><a href="//shang.qq.com/wpa/qunwpa?idkey=c7344a52e726be533fbdefe8cffd7f856d70ffe167afecb09c8cb0e27de731bf" target="_blank">(QQ)交流群：156729480</a></p><p><a href="https://gitee.com/07fly/07flyfms" target="_blank">小说网站管理系统-（07FLY-FMS）</a><a href="//shang.qq.com/wpa/qunwpa?idkey=630dd170e1779efe9edc5c24f08c0e9cac62524dc29cb3c711d21e88b18291d5" target="_blank">(QQ)交流群：326456035</a></p><p><a href="https://gitee.com/07fly/FLY-WEBOS" target="_blank">桌面应用框架系统-（WebSystem）</a> <a href="//shang.qq.com/wpa/qunwpa?idkey=55cf781a3aa2a259af48372f5ae3db00e82eae519e1140ec3e049e720fc2ea4a" target="_blank">(QQ)交流群：201192371</a></p><p><a href="http://bbs.zm-kj.com/forum-78-1.html" target="_blank">宽带认证计费系统-（AAARadius）</a> <a href="//shang.qq.com/wpa/qunwpa?idkey=6d5c31325e3168ef9cd16ea624fb2959e27eacdd4b06dfd4f240c13ce59f79ba" target="_blank">(QQ)交流群：125444118</a></p><h4><br/></h4><h4>有偿服务请联系:</h4><p>定制化开发,公司培训,技术支持,解决使用过程中出现的全部疑难问题</p><p>开发团队：零起飞网络</p><p>合作电话：18030402705(李先生)</p><p>技术支持：goodmuzi@qq.com</p><h4><br/></h4><h4>有限担保和免责声明:</h4><p>本软件及所附带的文件是作为不提供任何明确的或隐含的赔偿或担保的形式提供的。\r\n &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; <br/></p><p>用户出于自愿而使用本软件，您必须了解使用本软件的风险，在尚未购买产品技术服务之前，\r\n &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; <br/></p><p>我们不承诺提供任何形式的技术支持、使用担保，也不承担任何因使用本软件而产生问题的相关责任。\r\n &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; <br/></p><p>究相关责任的权力。</p>', 'text', 0),
	(7, '联系电话', 'phone', '18030402705', 'string', 0),
	(8, '联系地址', 'address', '四川省成都市量力钢材城贸易区A4-3', 'string', 0);
/*!40000 ALTER TABLE `fly_sys_config` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=armscii8 COMMENT='部门表';

DELETE FROM `fly_sys_dept`;
/*!40000 ALTER TABLE `fly_sys_dept` DISABLE KEYS */;
INSERT INTO `fly_sys_dept` (`id`, `name`, `parentID`, `sort`, `visible`, `tel`, `fax`, `intro`) VALUES
	(1, '零起飞工作室', 0, 11, 1, '12345677', '02888133145', '主要是用来产的哟'),
	(2, '商务部', 1, 5, 1, '028 8976214', '028 8976214', ''),
	(6, '行政部', 1, 12, 1, '02861833149', '02861833149', ''),
	(7, '技术部', 1, 12, 1, '191231231', '21312', '123'),
	(8, '财务部', 1, 22, 1, '2222222222', '22222222222222', '222');
/*!40000 ALTER TABLE `fly_sys_dept` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=100 DEFAULT CHARSET=utf8 COMMENT='系统菜单栏目';

-- zocrm_sys.fly_sys_menu_role definition

CREATE TABLE `fly_sys_role_menu` (
  `id` int unsigned NOT NULL AUTO_INCREMENT,
  `role_id` int unsigned DEFAULT NULL,
  `menu_id` int unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=67 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='角色菜单关联表';
DELETE FROM `fly_sys_menu`;
/*!40000 ALTER TABLE `fly_sys_menu` DISABLE KEYS */;
-- ----------------------------
-- Records of fly_sys_menu
-- ----------------------------
INSERT INTO `fly_sys_menu` VALUES (1, '系统管理', 'SystemManage', 'cogs', 0, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (2, '客户管理', 'Customer', 'user', 0, 20, 1, '');
INSERT INTO `fly_sys_menu` VALUES (3, '统计分析', '', 'line-chart', 0, 50, 1, '');
INSERT INTO `fly_sys_menu` VALUES (4, '系统设置', '', '#', 1, 11, 1, '');
INSERT INTO `fly_sys_menu` VALUES (5, '组织结构', '', '#', 1, 12, 1, '');
INSERT INTO `fly_sys_menu` VALUES (6, '商品管理', '', 'goods', 1, 13, 1, '');
INSERT INTO `fly_sys_menu` VALUES (7, '数据字典', '', '#', 1, 13, 1, '');
INSERT INTO `fly_sys_menu` VALUES (8, '消息通知', '', '/sysmanage/Message/message_show/', 4, 116, 1, '');
INSERT INTO `fly_sys_menu` VALUES (9, '销售管理', '', 'sal', 2, 22, 0, '');
INSERT INTO `fly_sys_menu` VALUES (10, '采购合同统计', '', '/erp/ChartPurchase/chart_purchase_show/', 3, 23, 1, '');
INSERT INTO `fly_sys_menu` VALUES (11, '公共客户', '', '/crm/CstCustomerComm/cst_customer_comm_show/', 2, 213, 1, '');
INSERT INTO `fly_sys_menu` VALUES (12, '供应商管理', '', 'users', 0, 31, 1, '');
INSERT INTO `fly_sys_menu` VALUES (13, '采购管理', '', 'ship', 0, 32, 1, '');
INSERT INTO `fly_sys_menu` VALUES (14, '库存管理', 'kucun', 'cube', 0, 40, 1, '');
INSERT INTO `fly_sys_menu` VALUES (15, '系统参数', 'system', '/sysmanage/SysConfig/sys_config/', 4, 111, 1, '');
INSERT INTO `fly_sys_menu` VALUES (16, '系统菜单', '', '/sysmanage/Menu/menu_show/', 4, 112, 1, '');
INSERT INTO `fly_sys_menu` VALUES (17, '密码修改', 'serial', '/sysmanage/Sys/sys_password_modify/', 4, 113, 1, '');
INSERT INTO `fly_sys_menu` VALUES (18, '商品规格', 'system log', '/goods/GoodsSpec/goods_spec_show/', 6, 136, 1, '');
INSERT INTO `fly_sys_menu` VALUES (19, '数据库管理', 'database', '/sysmanage/SysData/sys_data/', 4, 115, 1, '');
INSERT INTO `fly_sys_menu` VALUES (20, '系统升级', '#', '/sysmanage/Sys/sys_upgrade/', 4, 115, 1, '');
INSERT INTO `fly_sys_menu` VALUES (21, '部门管理', '', '/sysmanage/Dept/dept_show/', 5, 115, 1, '');
INSERT INTO `fly_sys_menu` VALUES (22, '岗位管理', '', '/sysmanage/Position/position_show/', 5, 122, 1, '');
INSERT INTO `fly_sys_menu` VALUES (23, '角色管理', 'Role Management', '/sysmanage/Role/role_show/', 5, 122, 1, '');
INSERT INTO `fly_sys_menu` VALUES (24, '用户管理', 'Sys User Management', '/sysmanage/User/user_show/', 5, 124, 1, '');
INSERT INTO `fly_sys_menu` VALUES (25, '商品维护', 'product_dict', '/goods/Goods/goods_show/', 6, 131, 1, '');
INSERT INTO `fly_sys_menu` VALUES (26, '商品分类', '', '/goods/GoodsCategory/goods_category_show/', 6, 134, 1, '');
INSERT INTO `fly_sys_menu` VALUES (27, '商品品牌', 'ProductType', '/goods/GoodsBrand/goods_brand_show/', 6, 133, 1, '');
INSERT INTO `fly_sys_menu` VALUES (28, '商品类型', '', '/goods/GoodsAttr/goods_attr_show/', 6, 135, 1, '');
INSERT INTO `fly_sys_menu` VALUES (29, '字典管理', '', '/crm/CstDict/cst_dict_show/', 7, 141, 1, '');
INSERT INTO `fly_sys_menu` VALUES (30, '仓库管理', '', '/erp/StockStore/stock_store_show/', 1, 142, 1, '');
INSERT INTO `fly_sys_menu` VALUES (31, '经济类型', '', '/crm/CstDict/cst_dict_show/type/ecotype/', 7, 143, 0, '');
INSERT INTO `fly_sys_menu` VALUES (32, '客户来源', '', '/crm/CstDict/cst_dict_show/type/source/', 7, 144, 0, '');
INSERT INTO `fly_sys_menu` VALUES (33, '销售方式', '', '/crm/CstDict/cst_dict_show/type/salemode/', 7, 145, 0, '');
INSERT INTO `fly_sys_menu` VALUES (34, '销售阶段', '', '/crm/CstDict/cst_dict_show/type/salestage/', 7, 146, 0, '');
INSERT INTO `fly_sys_menu` VALUES (35, '服务类型', 'Service Type', '/crm/CstDict/cst_dict_show/type/services/', 7, 147, 0, '');
INSERT INTO `fly_sys_menu` VALUES (36, '服务方式', '', '/crm/CstDict/cst_dict_show/type/servicesmodel/', 7, 148, 0, '');
INSERT INTO `fly_sys_menu` VALUES (37, '我的客户', 'Customer List', '/crm/CstCustomer/cst_customer_show/', 2, 211, 1, '');
INSERT INTO `fly_sys_menu` VALUES (38, '客户联系人', 'Customer Linkman', '/crm/CstLinkman/cst_linkman_show/', 2, 214, 1, '');
INSERT INTO `fly_sys_menu` VALUES (39, '公告通知', '#', '/sysmanage/Notice/notice_show/', 1, 213, 1, '');
INSERT INTO `fly_sys_menu` VALUES (40, '服务记录', 'Service', '/crm/CstService/cst_service_show/', 2, 215, 1, '');
INSERT INTO `fly_sys_menu` VALUES (41, '地区管理', '#', '/sysmanage/Area/area_show/', 1, 215, 1, '');
INSERT INTO `fly_sys_menu` VALUES (42, '销售机会', '', '/crm/CstChance/cst_chance_show/', 2, 221, 1, '');
INSERT INTO `fly_sys_menu` VALUES (43, '跟踪记录', '', '/crm/CstTrace/cst_trace_show/', 2, 222, 1, '');
INSERT INTO `fly_sys_menu` VALUES (44, '产品报价', '', '/crm/CstQuoted/cst_quoted_show/', 9, 223, 0, '');
INSERT INTO `fly_sys_menu` VALUES (45, '项目报备', '', '/crm/CstFiling/cst_filing_show/', 9, 224, 0, '');
INSERT INTO `fly_sys_menu` VALUES (46, '销售合同', 'sale contract', '/crm/SalContract/sal_contract_show/', 2, 231, 1, '');
INSERT INTO `fly_sys_menu` VALUES (47, '多维度统计', 'Contract', '/erp/ChartDime/chart_dime_show/', 3, 232, 1, '');
INSERT INTO `fly_sys_menu` VALUES (48, '销售合同统计', 'Contact', '/erp/ChartSale/chart_sale_show/', 3, 233, 1, '');
INSERT INTO `fly_sys_menu` VALUES (49, '字段扩展', 'Sale order', '/crm/CstFieldExt/cst_field_ext_show/', 1, 241, 1, '');
INSERT INTO `fly_sys_menu` VALUES (50, '下属客户', 'Order Sale', '/crm/CstCustomerDept/cst_customer_dept_show/', 2, 212, 1, '');
INSERT INTO `fly_sys_menu` VALUES (51, '供应商列表', 'Supplier', '/erp/SupSupplier/sup_supplier_show/', 12, 311, 1, '');
INSERT INTO `fly_sys_menu` VALUES (52, '供应商联系人', '', '/erp/SupLinkman/sup_linkman_show/', 12, 312, 1, '');
INSERT INTO `fly_sys_menu` VALUES (53, '商品SKU', '', '/goods/GoodsSku/goods_sku_show/', 6, 132, 1, '');
INSERT INTO `fly_sys_menu` VALUES (54, '采购订单', 'POS', '/erp/PosContract/pos_contract_show/', 13, 321, 1, '');
INSERT INTO `fly_sys_menu` VALUES (55, '采购明细', 'POS Detail', '/erp/PosContractList/pos_contract_list_show/', 13, 322, 1, '');
INSERT INTO `fly_sys_menu` VALUES (56, '库存清单', '', '/erp/StockGoodsSku/stock_goods_sku_show//', 14, 331, 1, '');
INSERT INTO `fly_sys_menu` VALUES (57, '入库单', '', '/erp/StockInto/stock_into_show/', 14, 332, 1, '');
INSERT INTO `fly_sys_menu` VALUES (58, '入库明细', '', '/erp/StockIntoList/stock_into_list_show/', 14, 333, 1, '');
INSERT INTO `fly_sys_menu` VALUES (59, '出库单', '', '/erp/StockOut/stock_out_show/', 14, 334, 1, '');
INSERT INTO `fly_sys_menu` VALUES (60, '出库明细', '', '/erp/StockOutList/stock_out_list_show/', 14, 335, 1, '');
INSERT INTO `fly_sys_menu` VALUES (61, '系统方法', 'System Model', '/sysmanage/Method/method_show/', 4, 112, 1, '');
INSERT INTO `fly_sys_menu` VALUES (63, '财务管理', 'Finace', 'money', 0, 60, 1, '');
INSERT INTO `fly_sys_menu` VALUES (64, '资金注入抽取', '统计分析', '/erp/FinCapitalRecord/fin_capital_record_show/', 63, 41, 1, '');
INSERT INTO `fly_sys_menu` VALUES (65, '财务类型', '财务类型', 'finance', 1, 42, 1, '');
INSERT INTO `fly_sys_menu` VALUES (66, '付款管理', '付款管理', 'pay', 63, 43, 1, '');
INSERT INTO `fly_sys_menu` VALUES (67, '回款管理', '回款管理', 'back', 63, 44, 1, '');
INSERT INTO `fly_sys_menu` VALUES (68, '收入开支', '收入开支', '收入开支', 63, 45, 1, '');
INSERT INTO `fly_sys_menu` VALUES (69, '费用收入类型', 'income', '/erp/FinIncomeType/fin_income_type_show/', 65, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (70, '费用开支类型', 'income', '/erp/FinExpensesType/fin_expenses_type_show/', 65, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (71, '银行帐号管理', '银行帐号管理', '/erp/FinBankAccount/fin_bank_account_show/', 65, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (72, '付款计划', 'FinPayPlan', '/erp/FinPayPlan/fin_pay_plan_show/', 66, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (73, '付款记录', '付款记录', '/erp/FinPayRecord/fin_pay_record_show/', 66, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (74, '收票记录', '收票记录', '/erp/FinInvoiceRece/fin_invoice_rece_show/', 66, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (75, '回款计划', '回款计划', '/erp/FinRecePlan/fin_rece_plan_show/', 67, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (76, '回款记录', '回款记录', '/erp/FinReceRecord/fin_rece_record_show/', 67, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (77, '开票记录', '开票记录', '/erp/FinInvoicePay/fin_invoice_pay_show/', 67, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (78, '报销单审核', '报销单审核', '报销单审核', 68, 1, 0, '');
INSERT INTO `fly_sys_menu` VALUES (79, '其它收入单', '其它收入单', '/erp/FinIncomeRecord/fin_income_record_show/', 68, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (80, '费用支出单', '费用支出单', '/erp/FinExpensesRecord/fin_expenses_record_show/', 68, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (81, '邮件群发', 'email', 'email', 1, 20, 0, '');
INSERT INTO `fly_sys_menu` VALUES (82, '发送地址', 'sendFrom', '/tools/EmailSend/email_from_show/', 81, 0, 1, '');
INSERT INTO `fly_sys_menu` VALUES (83, '接收地址', 'sendFrom', '/tools/EmailSend/email_receiver_show/', 81, 0, 1, '');
INSERT INTO `fly_sys_menu` VALUES (84, '方案定制', 'sendFrom', '/tools/EmailSend/email_scheme_show/', 81, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (85, '邮件模板', 'moban', '/tools/EmailSend/email_mb_show/', 81, 0, 1, '');
INSERT INTO `fly_sys_menu` VALUES (86, '日志跟踪', 'schemeLog', '/tools/EmailSend/email_scheme_log_show/', 81, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (87, '帐户流水记录', 'Flow', '/erp/FinFlowRecord/fin_flow_record_show/', 63, 46, 1, '');
INSERT INTO `fly_sys_menu` VALUES (88, '网站管理', 'website', '/crm/CstWebsite/cst_website_show/', 2, 232, 1, '');
INSERT INTO `fly_sys_menu` VALUES (89, '字典分类', '栏目名称', '/crm/CstDictType/cst_dict_type_show/', 7, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (90, '基础数据', '', '/basicData', 0, 100, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (91, '数据字典', '', '/basicData/dictionary', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (92, '字典分类', '', '/basicData/dictionary/classification', 91, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (93, '字典管理', '', '/basicData/dictionary/management', 91, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (94, '地区管理', '', '/basicData/regional', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (95, '财务类型', '', '/basicData/financial', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (96, '费用收入类型', '', '/basicData/financial/incomeType', 95, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (97, '费用开支类型', '', '/basicData/financial/expenseType', 95, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (98, '银行账号管理', '', '/basicData/financial/bankAccount', 95, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (99, '仓库管理', '', '/basicData/warehouse', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (100, '商品管理', '', '/basicData/product', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (101, '商品品牌', '', '/basicData/product/brand', 100, 12, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (102, '商品类型', '', '/basicData/product/type', 100, 13, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (103, '商品分类', '', '/basicData/product/classification', 100, 14, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (104, '商品规格', '', '/basicData/product/specification', 100, 15, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (105, '商品维护', '', '/basicData/product/maintenace', 100, 16, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (106, '商品SKU', '', '/basicData/product/SKU', 100, 17, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (107, '客户管理', '', '/customer', 0, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (108, '我的客户', '', '/customer/client', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (109, '下属客户', '', '/customer/subCustomers', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (110, '公海客户', '', '/customer/seasClients', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (111, '联系人', '', '/customer/links', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (112, '服务记录', '', '/customer/serviceRecord', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (113, '资金管理', 'Fund Management', '/fund', 0, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (114, '资金注入抽取', 'Fund Injection Extraction', '/fund/injectionExtraction', 113, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (115, '回款管理', 'Collection Management', '/fund/collection', 113, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (116, '收入开支', 'Income Expense', '/fund/incomeExpense', 113, 2, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (117, '账户流水记录', 'Account Transaction Record', '/fund/records', 113, 3, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (118, '付款管理', 'Payment Management', '/fund/payment', 113, 4, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (119, '回款计划', 'Collection Plan', '/fund/collection/collectionPlan', 115, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (120, '回款记录', 'Collection Record', '/fund/collection/collectionRecords', 115, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (121, '开票记录', 'Invoice Record', '/fund/collection/invoiceRecords', 115, 2, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (122, '其他收入单', 'Other Income', '/fund/incomeExpense/income', 116, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (123, '费用支出单', 'Cost Expenses', '/fund/incomeExpense/expense', 116, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (124, '付款计划', 'Payment Plan', '/fund/payment/plan', 118, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (125, '付款记录', 'Payment Record', '/fund/payment/paymentRecords', 118, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (126, '收票记录', 'Receipt Record', '/fund/payment/ticketRecords', 118, 2, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (127, '个人首页', 'Homepage', '/homepage', 0, 0, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (128, '公告通知', 'Notice', '/homepage/notice', 127, 0, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (129, '消息通知', 'Message', '/homepage/message', 127, 1, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (130, '修改密码', 'Change Password', '/homepage/password', 127, 2, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (131, '编辑资料', 'Edit Information', '/homepage/information', 127, 3, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (132, '库存管理', 'Inventory', '/inventory', 0, 0, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (133, '库存清单', 'Inventory List', '/inventory/inventoryList', 132, 0, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (134, '入库单', 'Storage Receipt', '/inventory/storageReceipt', 132, 1, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (135, '入库明细', 'Stock Storage Details', '/inventory/StockStorageDetails', 132, 2, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (136, '出库单', 'Warehousing Details', '/inventory/WarehousingDetails', 132, 3, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (137, '出库明细', 'Out storage details', '/inventory/outstoragedetails', 132, 4, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (138, '组织结构', 'Organization', '/organization', 0, 0, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (139, '部门管理', 'Department Management', '/organization/department', 138, 0, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (140, '岗位管理', 'Post Management', '/organization/post', 138, 1, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (141, '角色管理', 'Role Management', '/organization/role', 138, 2, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (142, '用户管理', 'User Management', '/organization/user', 138, 3, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (143, '销售管理', 'Sale Management', '/sale', 0, 0, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (144, '销售机会', 'Sales Opportunity', '/sale/opportunity', 143, 0, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (145, '跟踪记录', 'Tracking Records', '/sale/trackRecords', 143, 1, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (146, '销售合同', 'Sales Contract', '/sale/saleContract', 143, 2, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (147, '销售简报', 'Sales Kit', '/sale/saleKit', 143, 3, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (148, '供应商管理', 'Supplier Management', '/supplier', 0, 0, 1, 'IconVan');
INSERT INTO `fly_sys_menu` VALUES (149, '供应商列表', 'Supplier List', '/supplier/list', 148, 0, 1, 'IconVan');
INSERT INTO `fly_sys_menu` VALUES (150, '供应商联系人', 'Supplier Contacts', '/supplier/contact', 148, 1, 1, 'IconVan');
INSERT INTO `fly_sys_menu` VALUES (151, '系统管理', 'System Management', '/system', 0, 0, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (152, '系统参数', 'System Parameters', '/system/parameter', 151, 0, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (153, '菜单管理', 'Menu Management', '/system/menu', 151, 1, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (154, '权限管理', 'Permission Management', '/system/power', 151, 2, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (155, '字段扩展', 'Field Extension', '/system/field', 151, 3, 1, 'IconSetting');
/*!40000 ALTER TABLE `fly_sys_menu` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=106 DEFAULT CHARSET=utf8 COMMENT='系统方法';

DELETE FROM `fly_sys_method`;
/*!40000 ALTER TABLE `fly_sys_method` DISABLE KEYS */;
INSERT INTO `fly_sys_method` VALUES (1, 99, '增加仓库', '/j3-controller-warehouse/add-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (2, 99, '删除仓库', '/j3-controller-warehouse/delete-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (3, 99, '获取仓库下拉列表', '/j3-controller-warehouse/getStoreSelect', 0, 1);
INSERT INTO `fly_sys_method` VALUES (4, 99, '导入仓库', '/j3-controller-warehouse/import-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (5, 99, '修改仓库信息', '/j3-controller-warehouse/modify-store-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (6, 99, '查询仓库', '/j3-controller-warehouse/query-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (7, 94, '删除地区', '/j3-area/deleteArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (8, 94, '新增地区', '/j3-area/insertArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (9, 94, '修改地区', '/j3-area/modifyArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (10, 94, '获取区域列表', '/j3-area/query-list-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (11, 94, '获取区域名称结构树', '/j3-area/query-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (12, 94, '获取区域下拉列表', '/j3-area/select-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (13, 108, '获取客户名称列表', '/customer-mycustomer/get-customername', 0, 1);
INSERT INTO `fly_sys_method` VALUES (14, 108, '获取客户列表', '/customer-mycustomer/get-customer', 0, 1);
INSERT INTO `fly_sys_method` VALUES (15, 108, '获取客户详细信息', '/customer-mycustomer/query-customer-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (16, 108, '获取客户基础信息表单数据项', '/customer-mycustomer/get-base-custormer-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (17, 108, '添加客户', '/customer-mycustomer/post-customers', 0, 1);
INSERT INTO `fly_sys_method` VALUES (18, 108, '修改客户基础信息', '/customer-mycustomer/put-customers', 0, 1);
INSERT INTO `fly_sys_method` VALUES (19, 108, '删除客户', '/customer-mycustomer/delete-custormer', 0, 1);
INSERT INTO `fly_sys_method` VALUES (20, 108, '投入公海', '/customer-mycustomer/inves-hightsea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (21, 108, '导出客户', '/customer-mycustomer/get-customername', 0, 1);
INSERT INTO `fly_sys_method` VALUES (22, 108, '上传导入文件', '/customer-mycustomer/upload-customer-file', 0, 1);
INSERT INTO `fly_sys_method` VALUES (23, 110, '领取客户', '/crm-c2-customer-publiccustomer/receive-custormer', 0, 1);
INSERT INTO `fly_sys_method` VALUES (24, 111, '获取联系人名称', '/customer-contact/query-contact-name', 0, 1);
INSERT INTO `fly_sys_method` VALUES (25, 111, '获取联系人列表', '/customer-contact/query-contact-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (26, 111, '获取联系人表单数据项', '/customer-contact/get-contact-field', 0, 1);
INSERT INTO `fly_sys_method` VALUES (27, 111, '添加联系人', '/customer-contact/add-contact', 0, 1);
INSERT INTO `fly_sys_method` VALUES (28, 111, '修改联系人', '/customer-contact/modify-contact', 0, 1);
INSERT INTO `fly_sys_method` VALUES (29, 111, '删除联系人', '/customer-contact/remove-contact', 0, 1);
INSERT INTO `fly_sys_method` VALUES (30, 111, '导出联系人', '/customer-contact/query-contact-file', 0, 1);
INSERT INTO `fly_sys_method` VALUES (31, 111, '发送短信接口', '/customer-contact/send-sms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (32, 111, '发送邮件接口', '/customer-contact/send-email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (33, 112, '分页查询服务记录', '/customer-servicerecords/service-note', 0, 1);
INSERT INTO `fly_sys_method` VALUES (34, 112, '添加服务记录', '/customer-servicerecords/add-service', 0, 1);
INSERT INTO `fly_sys_method` VALUES (35, 112, '修改服务记录', '/customer-servicerecords/modify-service', 0, 1);
INSERT INTO `fly_sys_method` VALUES (36, 112, '删除服务记录(批量)', '/customer-servicerecords/remove-service{service_id_s}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (37, 112, '导出服务记录', '/customer-servicerecords/export-servicenote', 0, 1);
INSERT INTO `fly_sys_method` VALUES (38, 112, '发送短信接口', '/customer-servicerecords/send-sms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (39, 112, '发送邮件接口', '/customer-servicerecords/send-email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (40, 144, '获取销售机会列表(分页+条件)', '/sales-opportunities/query-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (41, 144, '添加销售机会', '/sales-opportunities/insert-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (42, 144, '修改销售机会', '/sales-opportunities/update-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (43, 144, '删除销售机会(支持批量删除)', '/sales-opportunities/delete-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (44, 144, '获取销售机名称会列表(用于输入表单下拉列表)', '/sales-opportunities/sales-oppo-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (45, 144, '导出销售机会', '/sales-opportunities/export-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (46, 144, '发邮件(支持批量)', '/sales-opportunities/salesContract/Mail/', 0, 1);
INSERT INTO `fly_sys_method` VALUES (47, 144, '发短信(支持批量)', '/sales-opportunities/salesContract/Sms/', 0, 1);
INSERT INTO `fly_sys_method` VALUES (48, 145, '增加跟踪记录', '/crm-c4-sales-man/add-trace', 0, 1);
INSERT INTO `fly_sys_method` VALUES (49, 145, '修改跟踪记录', '/crm-c4-sales-man/modify-trace', 0, 1);
INSERT INTO `fly_sys_method` VALUES (50, 145, '获取跟踪记录', '/crm-c4-sales-man/get', 0, 1);
INSERT INTO `fly_sys_method` VALUES (51, 145, '单独删除跟踪记录', '/crm-c4-sales-man/delete-trace/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (52, 145, '批量删除跟踪记录', '/crm-c4-sales-man/delete-tracelist', 0, 1);
INSERT INTO `fly_sys_method` VALUES (53, 145, '下载跟踪记录文件', '/crm-c4-sales-man/downloadfile-trace', 0, 1);
INSERT INTO `fly_sys_method` VALUES (54, 145, '单独删除跟踪记录', '/crm-c4-sales-man/record/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (55, 145, '导出跟踪记录', '/crm-c4-sales-man/recordsfile/download', 0, 1);
INSERT INTO `fly_sys_method` VALUES (56, 145, '获取销售榜', '/crm-c4-sales-man/querySalesChart', 0, 1);
INSERT INTO `fly_sys_method` VALUES (57, 147, '进行数量统计', '/crm-c4-sales-man/queryNumberCounting', 0, 1);
INSERT INTO `fly_sys_method` VALUES (58, 147, '查询跟踪记录', '/crm-c4-sales-man/await/query', 0, 1);
INSERT INTO `fly_sys_method` VALUES (59, 147, '', '/crm-c4-sales-man/await/queryC', 0, 1);
INSERT INTO `fly_sys_method` VALUES (60, 145, '发送预约提醒短信(支持批量)', '/crm-c4-sales-man/sendms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (61, 145, '发送预约提醒邮件(支持批量)', '/crm-c4-sales-man/sendem', 0, 1);
INSERT INTO `fly_sys_method` VALUES (62, 146, '获取销售合同列表数据(用于输入表单下拉列表)', '/sales-contract/sales-cont-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (63, 146, '获取销售合同唯一编号', '/sales-contract/get-salesNo/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (64, 146, '获取销售合同列表(分页+条件)', '/sales-contract/get-sales-contract-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (65, 146, '获取合同详情', '/sales-contract/get-sales-contract-detail-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (66, 146, '获取合同清单', '/sales-contract/get-contract-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (67, 146, '添加销售合同', '/sales-contract/add-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (68, 146, '删除销售合同', '/sales-contract/delete-contract/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (69, 146, '修改销售合同基础信息', '/sales-contract/modify-basic-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (70, 146, '修改交付状态', '/sales-contract/modify-deliver-status', 0, 1);
INSERT INTO `fly_sys_method` VALUES (71, 146, '录入明细', '/sales-contract/input-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (72, 146, '删除明细', '/sales-contract/delete-contract-details/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (73, 146, '添加合同附件', '/sales-contract/contractfile/upload', 0, 1);
INSERT INTO `fly_sys_method` VALUES (74, 146, '生成出库单', '/sales-contract/add-out_stock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (75, 146, '导出销售合同', '/sales-contract/ExportSales', 0, 1);
INSERT INTO `fly_sys_method` VALUES (76, 146, '发短信(支持批量)', '/sales-contract/sms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (77, 146, '发邮件(支持批量)', '/sales-contract/email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (78, 115, '修改回款计划', '/collection-man/update-pay-plan', 0, 1);
INSERT INTO `fly_sys_method` VALUES (79, 115, '确认回款计划', '/collection-man/update-confirm-plan', 0, 1);
INSERT INTO `fly_sys_method` VALUES (80, 115, '获取回款列表', '/collection-man/collectionplans/get-collectionplans', 0, 1);
INSERT INTO `fly_sys_method` VALUES (81, 115, '添加回款计划', '/collection-man/collectionplans/add-collection', 0, 1);
INSERT INTO `fly_sys_method` VALUES (82, 115, '查询回款记录', '/collection-man/collectionRecord/qurery', 0, 1);
INSERT INTO `fly_sys_method` VALUES (83, 115, '新增回款记录', '/collection-man/collectionRecord/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (84, 115, '删除回款记录', '/collection-man/collectionRecord/delete', 0, 1);
INSERT INTO `fly_sys_method` VALUES (85, 115, '导出回款记录', '/collection-man/collectionRecord/export', 0, 1);
INSERT INTO `fly_sys_method` VALUES (86, 115, '删除回款计划', '/collection-man/payback-manage/del-payplan', 0, 1);
INSERT INTO `fly_sys_method` VALUES (87, 115, '获取金额信息', '/collection-man/payback-manage/select-amountinfo', 0, 1);
INSERT INTO `fly_sys_method` VALUES (88, 115, '删除开票记录(支持批量删除)', '/collection-man/BillingRecords/DelBillingRecords', 0, 1);
INSERT INTO `fly_sys_method` VALUES (89, 115, '导出开票记录', '/collection-man/BillingRecords/ExportBillingRecords', 0, 1);
INSERT INTO `fly_sys_method` VALUES (90, 115, '分页查询开票', '/collection-man/Invoice/qurery', 0, 1);
INSERT INTO `fly_sys_method` VALUES (91, 115, '新增开票', '/collection-man/Invoice/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (92, 116, '删除单据', '/financial-manager/delete-expenditures-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (93, 116, '导出单据', '/financial-manager/export-expenditures-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (94, 116, '新增单据', '/financial-manager/add-expenditures-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (95, 116, '查询单据', '/financial-manager/query-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (96, 116, '删除单据', '/financial-manager/delete-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (97, 116, '导出收入单', '/financial-manager/export-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (98, 117, '查询流水记录', '/financial-manager/query-flowrecord', 0, 1);
INSERT INTO `fly_sys_method` VALUES (99, 117, '导出流水记录', '/financial-manager/export-flowrecord', 0, 1);
INSERT INTO `fly_sys_method` VALUES (100, 116, '新增收入单', '/financial-manager/insert-income', 0, 1);
INSERT INTO `fly_sys_method` VALUES (101, 116, '分页查询收入单', '/financial-manager/query-income', 0, 1);
INSERT INTO `fly_sys_method` VALUES (102, 132, '获取入库明细项列表(分页+条件)', '/inventory-manager/query-storage-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (103, 132, '导出入库明细', '/inventory-manager/export-storage-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (104, 132, '确认入库', '/inventory-manager/modify-ConfirmStorage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (105, 132, '删除入库单', '/inventory-manager/delete-storage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (106, 132, '获取出库明细项列表', '/inventory-manager/query-outbound-detail', 0, 1);
INSERT INTO `fly_sys_method` VALUES (107, 132, '导出出库明细', '/inventory-manager/export-outbound-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (108, 132, '获取入库单列表(分页+条件)', '/inventory-manager/query-instorage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (109, 132, '查询入库明细', '/inventory-manager/query-instorage_details/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (110, 132, '添加入库单', '/inventory-manager/add-instorage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (111, 132, '获取库存列表(分页+条件)', '/inventory-manager/query-inventory-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (112, 132, '导出库存列表信息', '/inventory-manager/export-inventory-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (113, 132, '确认出库', '/inventory-manager/confirm-outstock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (114, 132, '删除出库单', '/inventory-manager/delete-outstock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (115, 132, '获取出库单项列表(分页+条件)', '/inventory-manager/query-out-stock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (116, 132, '添加出库单', '/inventory-manager/add-out_stock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (117, 132, '获取出库单明细', '/inventory-manager/out-stock-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (118, 114, '获取银行账户列表数据', '/fin-capital-record/query-bank-account', 0, 1);
INSERT INTO `fly_sys_method` VALUES (119, 114, '查询资金注入抽取单号记录', '/fin-capital-record/query-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (120, 114, '添加资金注入抽取单号记录', '/fin-capital-record/add-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (121, 114, '导出资金注入抽取单号记录(批量)', '/fin_capital_record/export-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (122, 114, '删除资金注入抽取单号(批量)', '/fin-capital-record/remove-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (123, 0, '获取供应商名称列表', '/common/query-supplier-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (124, 0, '获取供应商联系人名称列表', '/common/query-linkman-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (125, 0, '获取仓库名称列表', '/common/warehouse', 0, 1);
INSERT INTO `fly_sys_method` VALUES (126, 0, '获取区域名称列表', '/common/area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (127, 0, '获取部门名称列表', '/common/department-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (128, 0, '获取岗位名称列表', '/common/position-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (129, 0, '获取角色名称列表', '/common/role-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (130, 0, '系统用户名称列表', '/common/sys-user-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (131, 0, '获取客户名称列表', '/common/client-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (132, 0, '获取联系人名称列表', '/common/query-contact-name', 0, 1);
INSERT INTO `fly_sys_method` VALUES (133, 0, '获取费用收入类型名称列表', '/common/cost-income-type-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (134, 0, '获取费用开支类型名称列表', '/common/cost-expense-type-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (135, 0, '获取银行账户列表', '/common/bank-account-1ist', 0, 1);
INSERT INTO `fly_sys_method` VALUES (136, 0, '获取指定字典分类对应字典列表', '/common/data-dict-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (137, 0, '获取销售机会名称列表', '/common/sale-opportunity-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (138, 0, '获取销售合同名称列表', '/common/sale-contract-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (139, 0, '获取商品分类名称列表', '/common/goods-category-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (140, 148, '修改供应商', '/supplier-manage/supplier/modify-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (141, 148, '获取供应商基础信息表单数据项', '/supplier-manage/supplier/query-sup-form-item', 0, 1);
INSERT INTO `fly_sys_method` VALUES (142, 148, '获取供应商列表(分页+条件)', '/supplier-manage/supplier/get-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (143, 148, '添加供应商', '/supplier-manage/supplier/add-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (144, 148, '删除供应商', '/supplier-manage/supplier/remove-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (145, 148, '导出供应商联系人', '/supplier-manage/supplier-linkman/export-linkman', 0, 1);
INSERT INTO `fly_sys_method` VALUES (146, 148, '批量发短信', '/supplier-manage/supplier-linkman/send-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (147, 148, '修改供应商联系人', '/supplier-manage/supplier-linkman/modify-link-man', 0, 1);
INSERT INTO `fly_sys_method` VALUES (148, 148, '删除供应商联系人', '/supplier-manage/supplier-linkman/remove-linkman', 0, 1);
INSERT INTO `fly_sys_method` VALUES (149, 148, '获取供应商联系人基础信息表单数据项', '/supplier-manage/supplier-linkman/basic-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (150, 148, '批量发邮件', '/supplier-manage/supplier-linkman/send-email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (151, 148, '获取供应商联系人名称列表', '/supplier-manage/supplier-linkman/query-name-pull-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (152, 148, '获取供应商联系人列表(分页+条件)', '/supplier-manage/supplier-linkman/query-linkman-page', 0, 1);
INSERT INTO `fly_sys_method` VALUES (153, 148, '添加供应商联系人', '/supplier-manage/supplier-linkman/add-linkman', 0, 1);
INSERT INTO `fly_sys_method` VALUES (154, 0, '授权登录', '/login/auth-login', 0, 1);
INSERT INTO `fly_sys_method` VALUES (155, 0, '获取当前用户', '/login/current-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (156, 0, '获取菜单', '/login/get-menus', 0, 1);
INSERT INTO `fly_sys_method` VALUES (157, 0, '退出登录', '/login/logout', 0, 1);
INSERT INTO `fly_sys_method` VALUES (158, 0, '刷新登录', '/login/refresh-token', 0, 1);
INSERT INTO `fly_sys_method` VALUES (159, 0, '分页查询系统提示消息', '/sysindex/system-message/query-all-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (160, 0, '分页查询系统公告', '/sysindex/system-message/query-all-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (161, 0, '编号查询系统提示消息', '/sysindex/system-message/query-byid-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (162, 0, '编号查询系统公告', '/sysindex/system-message/query-byid-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (163, 0, '根据商机预计销售额统计商机数量', '/sysindex/count-business-money', 0, 1);
INSERT INTO `fly_sys_method` VALUES (164, 0, '根据商机销售状态分类统计商机数量', '/sysindex/count-business-salestage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (165, 0, '根据商机预计成功率统计商机数量', '/sysindex/count-business-successrate', 0, 1);
INSERT INTO `fly_sys_method` VALUES (166, 0, '根据客户等级统计数量', '/sysindex/count-customer-grade', 0, 1);
INSERT INTO `fly_sys_method` VALUES (167, 0, '根据客户行业统计数量', '/sysindex/count-customer-industryr', 0, 1);
INSERT INTO `fly_sys_method` VALUES (168, 0, '统计客户数量', '/sysindex/count-customer-number', 0, 1);
INSERT INTO `fly_sys_method` VALUES (169, 0, '根据客户来源统计数量', '/sysindex/count-customer-source', 0, 1);
INSERT INTO `fly_sys_method` VALUES (170, 0, '标记通知为已读', '/sysindex/mark-as-read', 0, 1);
INSERT INTO `fly_sys_method` VALUES (171, 0, '查询公告通知提醒列表', '/sysindex/query-announcement-notices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (172, 151, '获取字段类型', '/CstPlus/gettype', 0, 1);
INSERT INTO `fly_sys_method` VALUES (173, 151, 'updateField', '/CstPlus/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (174, 151, '获取可扩展表单列表（分页）', '/systemmanagement/cst-field-ext-plus/list-page', 0, 1);
INSERT INTO `fly_sys_method` VALUES (175, 151, '添加扩展字段', '/systemmanagement/cst-field-ext/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (176, 151, '获取可扩展表单列表', '/systemmanagement/cst-field-ext/list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (177, 151, '删除扩展字段', '/systemmanagement/cst-field-ext/remove-by-id', 0, 1);
INSERT INTO `fly_sys_method` VALUES (178, 151, '批量删除扩展字段', '/systemmanagement/cst-field-ext/remove-by-ids', 0, 1);
INSERT INTO `fly_sys_method` VALUES (179, 151, '获取系统参数', '/systemmanagement/fly-sys-config/list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (180, 151, '更新系统参数', '/systemmanagement/fly-sys-config/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (181, 151, '添加系统菜单', '/systemmanagement/fly-sys-menu/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (182, 151, '删除菜单和子菜单', '/systemmanagement/fly-sys-menu/delete/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (183, 151, '修改菜单', '/systemmanagement/fly-sys-menu/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (184, 151, '添加权限', '/systemmanagement/fly-sys-method/add-method', 0, 1);
INSERT INTO `fly_sys_method` VALUES (185, 151, '删除权限', '/systemmanagement/fly-sys-method/deletemethod', 0, 1);
INSERT INTO `fly_sys_method` VALUES (186, 151, '获取权限列表', '/systemmanagement/fly-sys-method/getMethodList', 0, 1);
INSERT INTO `fly_sys_method` VALUES (187, 151, '修改权限', '/systemmanagement/fly-sys-method/modify-method', 0, 1);
INSERT INTO `fly_sys_method` VALUES (188, 151, '查询菜单名称树', '/menu/tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (189, 151, '查询菜单列表', '/menu/{id}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (190, 138, '新增岗位', '/orgstructure/position/position/add-position', 0, 1);
INSERT INTO `fly_sys_method` VALUES (191, 138, '删除岗位', '/orgstructure/position/position/delete-position', 0, 1);
INSERT INTO `fly_sys_method` VALUES (192, 138, '获取岗位名称结构树', '/orgstructure/position/position/list-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (193, 138, '获取岗位列表 (分页+条件)', '/orgstructure/position/position/query-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (194, 138, '获取岗位名称列表数据 (用于输入表单下拉列表)', '/orgstructure/position/position/query-name-all\r\n', 0, 1);
INSERT INTO `fly_sys_method` VALUES (195, 138, '修改岗位', '/orgstructure/position/position/update-position', 0, 1);
INSERT INTO `fly_sys_method` VALUES (196, 138, '新增用户', '/orgstructure/user/user/add-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (197, 138, '删除用户', '/orgstructure/user/user/delete-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (198, 138, '导出用户', '/orgstructure/user/user/export-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (199, 138, '系统用户名列表数据 (用于输入表单下拉列表)', '/orgstructure/user/user/get-userName-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (200, 138, '导入用户', '/orgstructure/user/user/import-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (201, 138, '冻结-解冻用户', '/orgstructure/user/user/modify-user-status', 0, 1);
INSERT INTO `fly_sys_method` VALUES (202, 138, '获取用户列表 (分页+条件)', '/orgstructure/user/user/query-all-by-deptid-or-name', 0, 1);
INSERT INTO `fly_sys_method` VALUES (203, 138, '修改用户', '/orgstructure/user/user/update-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (204, 138, '新增角色', '/orgstructure/role/role/add-role', 0, 1);
INSERT INTO `fly_sys_method` VALUES (205, 138, '获取角色名称结构树', '/orgstructure/role/role/list-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (206, 138, '修改角色', '/orgstructure/role/role/modify-role', 0, 1);
INSERT INTO `fly_sys_method` VALUES (207, 138, '获取角色列表 (分页+条件)', '/orgstructure/role/role/query-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (208, 138, '获取角色名称列表数据 (用于输入表单下拉列表)', '/orgstructure/role/role/query-name-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (209, 138, '删除角色', '/orgstructure/role/role/remove-role', 0, 1);
INSERT INTO `fly_sys_method` VALUES (210, 138, '获取角色菜单权限树形数据', '/orgstructure/role/role-menu/role-check-power', 0, 1);
INSERT INTO `fly_sys_method` VALUES (211, 138, '修改角色菜单权限', '/orgstructure/role/role-menu/role-check-power-save', 0, 1);
INSERT INTO `fly_sys_method` VALUES (212, 138, '新增部门', '/orgstructure/dept/dept/add-dept', 0, 1);
INSERT INTO `fly_sys_method` VALUES (213, 138, '获取部门名称列表数据 (用于输入表单下拉列表)', '/orgstructure/dept/dept/list-name-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (214, 138, '获取部门名称结构树', '/orgstructure/dept/dept/list-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (215, 138, '修改部门', '/orgstructure/dept/dept/modify-dept', 0, 1);
INSERT INTO `fly_sys_method` VALUES (216, 138, '获取部门列表 (分页+条件)', '/orgstructure/dept/dept/query-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (217, 138, '删除部门', '/orgstructure/dept/dept/remove-dept', 0, 1);
INSERT INTO `fly_sys_method` VALUES (218, 0, '添加采购合同', '/purchasemanagement/contract/pos-contract/add-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (219, 0, '导出采购合同', '/purchasemanagement/contract/pos-contract/export-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (220, 0, '获取合同详情', '/purchasemanagement/contract/pos-contract/get-contract-detail', 0, 1);
INSERT INTO `fly_sys_method` VALUES (221, 0, '获取合同清单', '/purchasemanagement/contract/pos-contract/get-contract-inventory', 0, 1);
INSERT INTO `fly_sys_method` VALUES (222, 0, '获取合同列表 (分页+条件)', '/purchasemanagement/contract/pos-contract/get-contract-list-with-page-condition', 0, 1);
INSERT INTO `fly_sys_method` VALUES (223, 0, '获取合同唯一编号', '/purchasemanagement/contract/pos-contract/getContractNo', 0, 1);
INSERT INTO `fly_sys_method` VALUES (224, 0, '修改采购合同基本信息', '/purchasemanagement/contract/pos-contract/modify-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (225, 0, '导出采购合同明细', '/purchasemanagement/contract/pos-contract-list/export-contract-detail', 0, 1);
INSERT INTO `fly_sys_method` VALUES (226, 0, '获取合同列表 (分页+条件)', '/purchasemanagement/contract/pos-contract-list/get-contract-list-page', 0, 1);
INSERT INTO `fly_sys_method` VALUES (227, 127, '编辑资料', '/j3-owner-info/modify-owner-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (228, 127, '修改密码', '/j3-owner-info/modify-password', 0, 1);
INSERT INTO `fly_sys_method` VALUES (229, 127, '发布公告', '/j3-notice-remind/add-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (230, 127, '查看指定公告详情', '/j3-notice-remind/get-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (231, 127, '获取系统公告', '/j3-notice-remind/query-notion', 0, 1);
INSERT INTO `fly_sys_method` VALUES (232, 127, '删除公告（可批量删除）', '/j3-notice-remind/remove-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (233, 127, '标记已读公告（可批量标记）', '/j3-notice-remind/update-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (234, 127, '标记消息已读（批量操作）', '/j3-message-remind/mark-read-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (235, 127, '发布消息', '/j3-message-remind/publish-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (236, 127, '消息删除', '/j3-message-remind/deleteMassage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (237, 127, '根据分页条件获取消息列表', '/j3-message-remind/queryMessage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (238, 127, '查看消息详情', '/j3-message-remind/{id}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (239, 94, '删除地区', '/j3-area/deleteArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (240, 94, '新增地区', '/j3-area/insertArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (241, 94, '修改地区', '/j3-area/modifyArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (242, 94, '获取区域列表', '/j3-area/query-list-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (243, 94, '获取区域名称结构树', '/j3-area/query-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (244, 94, '获取区域下拉列表', '/j3-area/select-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (245, 99, '导出仓库', '/j3-controller-warehouse/export-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (246, 100, '删除sku', '/goods/commoditySku/del-sku', 0, 1);
INSERT INTO `fly_sys_method` VALUES (247, 100, '修改SKU', '/goods/commoditySku/edit-sku', 0, 1);
INSERT INTO `fly_sys_method` VALUES (248, 100, '获取SKU列表(分页+条件)', '/goods/commoditySku/query-sku', 0, 1);
INSERT INTO `fly_sys_method` VALUES (249, 100, '新增商品分类', '/goods/category/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (250, 100, '获取商品分类', '/goods/category/get/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (251, 100, '分页获取商品分类', '/goods/category/list-goods-category', 0, 1);
INSERT INTO `fly_sys_method` VALUES (252, 100, '获取商品分类名称树', '/goods/category/list-goods-category-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (253, 100, '修改商品分类', '/goods/category/modify', 0, 1);
INSERT INTO `fly_sys_method` VALUES (254, 100, '删除商品分类', '/goods/category/remove/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (255, 100, '添加品牌', '/goods/commodityBrand/add-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (256, 100, '修改品牌', '/goods/commodityBrand/modify-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (257, 100, '获取品牌列表条件查询', '/goods/commodityBrand/query-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (258, 100, '删除品牌列表', '/goods/commodityBrand/remove-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (259, 100, '添加类型', '/goods/type/add-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (260, 100, '删除类型', '/goods/type/delete-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (261, 100, '查询详细信息', '/goods/type/find-detailed-type\r\n', 0, 1);
INSERT INTO `fly_sys_method` VALUES (262, 100, '查询简单信息', '/goods/type/find-simple-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (263, 100, '修改详细信息', '/goods/type/modify-detailed-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (264, 100, '发布商品', '/goods/maintenance/add-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (265, 100, '删除商品(支持批量操作)', '/goods/maintenance/delete-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (266, 100, '获取商品详细信息', '/goods/maintenance/get-content/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (267, 100, '获取商品类型名称列表 (用于输入表单下拉列表)', '/goods/maintenance/get-goodsNames', 0, 1);
INSERT INTO `fly_sys_method` VALUES (268, 100, '分页查询', '/goods/maintenance/list-goods-pages', 0, 1);
INSERT INTO `fly_sys_method` VALUES (269, 100, '推荐-取消推荐(支持批量操作)', '/goods/maintenance/recommend-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (270, 100, '修改商品', '/goods/maintenance/update-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (271, 100, '上架-下架商品(支持批量操作)', '/goods/maintenance/update-state', 0, 1);
INSERT INTO `fly_sys_method` VALUES (272, 100, '增加商品规格', '/goods/commoditySpec/add-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (273, 100, '删除商品规格', '/goods/commoditySpec/delete-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (274, 100, '获取商品规格列表(分页+条件)', '/goods/commoditySpec/get-commodity-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (275, 100, '修改商品规格', '/goods/commoditySpec/modify-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (276, 118, '查询付款计划', '/payment/pay-plan/query', 0, 1);
INSERT INTO `fly_sys_method` VALUES (277, 118, '删除收票记录(可批量)', '/payment/receipt-record/delete{record_id}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (278, 118, '添加付款记录', '/payment/payrecord', 0, 1);
INSERT INTO `fly_sys_method` VALUES (279, 118, '增加收票记录', '/payment/invoice/post', 0, 1);
INSERT INTO `fly_sys_method` VALUES (280, 118, '删除付款记录', '/payment/pay-record/delete', 0, 1);
INSERT INTO `fly_sys_method` VALUES (281, 118, '导出付款记录', '/payment/pay-record/export', 0, 1);
INSERT INTO `fly_sys_method` VALUES (282, 118, '获取收票记录列表(分页+条件)', '/payment/invoice/query', 0, 1);
INSERT INTO `fly_sys_method` VALUES (283, 118, '', '/payment/capital/export:', 0, 1);
INSERT INTO `fly_sys_method` VALUES (284, 118, '删除付款计划', '/payment/pay-plan/del/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (285, 118, '确认付款', '/payment/pay-plan/confirm/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (286, 118, '修改付款计划', '/payment/pay-plan/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (287, 118, '添加付款计划', '/payment/pay-plan/post', 0, 1);
INSERT INTO `fly_sys_method` VALUES (288, 118, '', '/payment/pay-record/page-query:', 0, 1);
INSERT INTO `fly_sys_method` VALUES (289, 118, '', '/payment/contray/query:', 0, 1);
INSERT INTO `fly_sys_method` VALUES (290, 0, '消息服务', 'message_service', 1, 0);
INSERT INTO `fly_sys_method` VALUES (291, 0, '消息服务', 'message_service', 1, 0);
INSERT INTO `fly_sys_method` VALUES (292, 0, '消息服务', 'message_service', 1, 0);


SET FOREIGN_KEY_CHECKS = 1;

/*!40000 ALTER TABLE `fly_sys_method` ENABLE KEYS */;

CREATE TABLE `fly_sys_position` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `parentID` int(11) NOT NULL DEFAULT '0',
  `sort` int(11) NOT NULL DEFAULT '0',
  `visible` tinyint(2) NOT NULL DEFAULT '1',
  `intro` varchar(1024) CHARACTER SET utf8 DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=armscii8 COMMENT='职位表';

DELETE FROM `fly_sys_position`;
/*!40000 ALTER TABLE `fly_sys_position` DISABLE KEYS */;
INSERT INTO `fly_sys_position` (`id`, `name`, `parentID`, `sort`, `visible`, `intro`) VALUES
	(2, '董事会', 0, 1, 1, '董事会，管理全公司的信息的'),
	(3, '总经理', 2, 10, 1, ''),
	(4, '财务总监', 3, 20, 1, ''),
	(5, '人事总监', 3, 21, 0, ''),
	(7, '技术总监', 3, 31, 1, '');
/*!40000 ALTER TABLE `fly_sys_position` ENABLE KEYS */;

CREATE TABLE `fly_sys_power` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `master` varchar(64) NOT NULL DEFAULT '' COMMENT '权限类型，如role,user',
  `master_value` varchar(64) NOT NULL DEFAULT '' COMMENT '权限类型值',
  `access` varchar(64) NOT NULL DEFAULT '' COMMENT '权限属性名称 meun method',
  `access_value` text COMMENT '权限属性名称值',
  `operation` varchar(64) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=59 DEFAULT CHARSET=utf8 COMMENT='权限功能关联表';

DELETE FROM `fly_sys_power`;
/*!40000 ALTER TABLE `fly_sys_power` DISABLE KEYS */;
INSERT INTO `fly_sys_power` (`id`, `master`, `master_value`, `access`, `access_value`, `operation`) VALUES
	(53, 'role', '', 'SYS_MENU', '1,4,15,61,16,17,20,19,8,5,21,23,22,24,7,89,29,6,25,53,27,26,28,18,65,69,70,71,30,39,41,49,2,37,50,11,38,40,42,43,46,88,12,51,52,13,54,55,14,56,57,58,59,60,3,10,47,48,63,64,66,72,73,74,67,75,76,77,68,79,80,87,92,93,94,95,96,97,98,99', NULL),
	(7, 'role', '12', 'SYS_MENU', '1,4,15,61,16,17,18,20,19,5,21,23,22,24,7,89,29,30,31,32,33,34,35,36,6,25,27,26,28,81,85,83,82,86,84,2,8,37,38,39,40,41,9,42,43,44,45,10,46,88,47,48,11,49,50,3,12,51,52,53,13,54,55,14,56,57,58,59,60,63,64,87,65,69,70,71,66,72,73,74,67,75,76,77,68,78,79,80', ''),
	(8, 'role', '12', 'SYS_METHOD', 'dept_add,dept_modify,dept_del,role_add,role_modify,role_del,position_add,position_del,postion_del,user_add,user_modify,user_del,pro_dict_add,pro_type_add,pro_type_modify,pro_type_del,product_add,product_modify,product_del,customer_add,customer_modify,customer_del,cst_linkman_add,cst_linkman_modify,cst_linkman_del,cst_service_add,cst_service_modify,cst_service_del,cst_chance_add,cst_chance_modify,cst_chance_del,cst_trace_add,cst_trace_del,cst_trace_modify,cst_quoted_add,cst_quoted_modify,cst_quoted_del,cst_filing_add,cst_filing_modify,cst_filing_del', ''),
	(9, 'role', '12', 'SYS_AREA', '0', ''),
	(10, 'role', '13', 'SYS_MENU', '1,7,29,30,31,32,33,34,35,36,6,25,27,26,28,2,8,37,38,39,40,41,9,42,43,44,45', ''),
	(12, 'role', '13', 'SYS_AREA', '0', ''),
	(13, 'role', '14', 'SYS_MENU', '65,69,70,71,2,8,37,38,39,40,41,9,42,43,44,45,10,46,47,48,11,49,50,63,64,66,72,73,74,67,75,76,77,68,78,79,80,87', ''),
	(14, 'role', '14', 'SYS_METHOD', 'customer_add,customer_modify,customer_del,cst_linkman_add,cst_linkman_modify,cst_linkman_del,cst_service_add,cst_service_modify,cst_service_del,cst_chance_add,cst_chance_modify,cst_chance_del,cst_trace_add,cst_trace_del,cst_trace_modify,cst_quoted_add,cst_quoted_modify,cst_quoted_del,cst_filing_add,cst_filing_modify,cst_filing_del', ''),
	(15, 'role', '14', 'SYS_AREA', '', ''),
	(16, 'role', '13', 'SYS_METHOD', 'dept_add,dept_del,role_add,role_modify,role_del,position_add,position_del,user_add,user_modify,user_del,pro_dict_add,pro_type_add,pro_type_modify,pro_type_del,product_add,product_modify,product_del,customer_add,customer_modify,customer_del,cst_linkman_add,cst_linkman_modify,cst_linkman_del,cst_service_add,cst_service_modify,cst_service_del,cst_chance_add,cst_chance_modify,cst_chance_del,cst_trace_add,cst_trace_del,cst_trace_modify,cst_quoted_add,cst_quoted_modify,cst_quoted_del,cst_filing_add,cst_filing_modify,cst_filing_del', ''),
	(54, 'role', '', 'SYS_METHOD', 'dept_add,dept_modify,dept_del,role_add,role_modify,role_del,role_check_power,position_add,position_del,postion_del,user_add,user_modify,user_del,cst_dict_add,cst_dict_modify,cst_dict_del,cst_dict_type_modify,cst_dict_type_add,cst_dict_type_del,pro_dict_add,pro_type_add,pro_type_modify,pro_type_del,product_add,product_modify,product_del,cst_customer_add,cst_customer_modify,cst_customer_del,cst_linkman_add,cst_linkman_modify,cst_linkman_del,cst_service_add,cst_service_modify,cst_service_del,cst_chance_add,cst_chance_modify,cst_chance_del,cst_trace_add,cst_trace_del,cst_trace_modify,sal_contract_add,sal_contract_modify,sal_contract_del,cst_website_add,cst_website_modify,cst_website_del,sup_supplier_add,sup_supplier_modify,sup_supplier_del,sup_linkman_add,sup_linkman_modify,sup_linkman_del,pos_contract_add,pos_contract_modify,pos_contract_del,fin_capital_add,fin_capital_del,fin_pay_plan_add,fin_pay_plan_modify,fin_pay_plan_del,fin_pay_plan_sure,fin_pay_record_add,fin_pay_record_del,fin_invoice_rece_add,fin_invoice_rece_del,fin_rece_plan_add,fin_rece_plan_modify,fin_rece_plan_del,fin_rece_record_add,fin_rece_record_modify,fin_invoice_rece_add,fin_invoice_rece_del,fin_income_record_add,fin_income_record_del,fin_expenses_record_add,fin_expenses_record_del', NULL),
	(57, 'role', '1', 'SYS_MENU', '2,37,50,11,38,40,42,43,46,88,12,51,52,13,54,55,14,56,57,58,59,60,3,10,47,48,63,64,66,72,73,74,67,75,76,77,68,79,80,87,92,93,94,95,96,97,98,99,82,5,91,21,23,22,24,7,89,29,6,25,53,27,26,28,18,65,69,70,71,30,41,1,15,16,61,17,8,39,19,49,20', NULL),
	(58, 'role', '1', 'SYS_METHOD', 'cst_customer_add,cst_customer_modify,cst_customer_del,cst_linkman_add,cst_linkman_modify,cst_linkman_del,cst_service_add,cst_service_modify,cst_service_del,cst_chance_add,cst_chance_modify,cst_chance_del,cst_trace_add,cst_trace_del,cst_trace_modify,sal_contract_add,sal_contract_modify,sal_contract_del,cst_website_add,cst_website_modify,cst_website_del,sup_supplier_add,sup_supplier_modify,sup_supplier_del,sup_linkman_add,sup_linkman_modify,sup_linkman_del,pos_contract_add,pos_contract_modify,pos_contract_del,fin_capital_add,fin_capital_del,fin_pay_plan_add,fin_pay_plan_modify,fin_pay_plan_del,fin_pay_plan_sure,fin_pay_record_add,fin_pay_record_del,fin_invoice_rece_add,fin_invoice_rece_del,fin_rece_plan_add,fin_rece_plan_modify,fin_rece_plan_del,fin_rece_record_add,fin_rece_record_modify,fin_invoice_rece_add,fin_invoice_rece_del,fin_income_record_add,fin_income_record_del,fin_expenses_record_add,fin_expenses_record_del,dept_add,dept_modify,dept_del,role_add,role_modify,role_del,role_check_power,position_add,position_del,postion_del,user_add,user_modify,user_del,cst_dict_add,cst_dict_modify,cst_dict_del,cst_dict_type_modify,cst_dict_type_add,cst_dict_type_del,pro_dict_add,pro_type_add,pro_type_modify,pro_type_del,product_add,product_modify,product_del', NULL);
/*!40000 ALTER TABLE `fly_sys_power` ENABLE KEYS */;

CREATE TABLE `fly_sys_role` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `sort` int(16) NOT NULL DEFAULT '0',
  `visible` int(2) NOT NULL DEFAULT '0',
  `parentID` int(16) NOT NULL DEFAULT '0',
  `name` varchar(32) DEFAULT '',
  `intro` varchar(1024) DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8 COMMENT='权限列表';

DELETE FROM `fly_sys_role`;
/*!40000 ALTER TABLE `fly_sys_role` DISABLE KEYS */;
INSERT INTO `fly_sys_role` (`id`, `sort`, `visible`, `parentID`, `name`, `intro`) VALUES
	(1, 1, 1, 0, '超级管理员', '权限介绍,这是最高管理权限'),
	(13, 11, 1, 1, '总经理', '一般管理员'),
	(14, 10, 1, 1, '组员', '这个酒店还是不错哟'),
	(15, 3, 1, 1, '一般管理员', '222'),
	(16, 1, 1, 1, '主管', '222');
/*!40000 ALTER TABLE `fly_sys_role` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8 COMMENT='系统用户表';

DELETE FROM `fly_sys_user`;
/*!40000 ALTER TABLE `fly_sys_user` DISABLE KEYS */;
INSERT INTO `fly_sys_user` (`id`, `account`, `password`, `name`, `gender`, `tel`, `mobile`, `qicq`, `address`, `zipcode`, `email`, `roleID`, `deptID`, `positionID`, `intro`, `adt`, `identity`) VALUES
	(1, '07fly', 'a7fdb8c58349c96e82d6e82ab7932700', '枭哥', '1', '', '18030402705', '1871720801', '', '', 'goodmuzi@qq.com', '1', 1, 2, '零起飞网络工作室，是一个具有专业水平和非凡创意的制作者的组合~', NULL, 'SYS0001'),
	(3, 'test', 'test', 'test', '1', '02868133149', '1871720801', '', '成都市', '', 'mai@163.com', '13', 2, 2, '', '0000-00-00 00:00:00', NULL),
	(4, 'admin', '7fef6171469e80d32c0559f88b377245', '管理员', '1', '', '1366789876', '', '', '', '', '15', 1, 7, '', '0000-00-00 00:00:00', NULL),
	(7, 'cw', 'cw', 'cw', '1', '', '13800000000', '', '', '', '', '14', 2, 4, '', '2017-06-26 15:59:39', NULL);
/*!40000 ALTER TABLE `fly_sys_user` ENABLE KEYS */;

CREATE TABLE `fly_sys_user_notice` (
  `id` int(16) NOT NULL AUTO_INCREMENT,
  `title` varchar(256) NOT NULL DEFAULT '' COMMENT '标题',
  `content` text COMMENT '通知内容',
  `status` int(2) NOT NULL DEFAULT '-1' COMMENT '-1=未查看，1=查看',
  `owner_user_id` int(2) NOT NULL DEFAULT '0' COMMENT '接收人员编号',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '发布人员的编号',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=70 DEFAULT CHARSET=utf8 COMMENT='系统员工通知信息';

DELETE FROM `fly_sys_user_notice`;
/*!40000 ALTER TABLE `fly_sys_user_notice` DISABLE KEYS */;
INSERT INTO `fly_sys_user_notice` (`id`, `title`, `content`, `status`, `owner_user_id`, `create_user_id`, `create_time`) VALUES
	(29, '明天在家一起开会了哟', '明天在家一起开会了哟，不要忘了', 1, 1, 1, '2019-03-09 22:45:06'),
	(27, '明天下午开会了', '请大家带好笔记本之类的东西哟', 1, 1, 1, '2019-03-09 18:07:48'),
	(26, '明天下午开会了', '请大家带好笔记本之类的东西哟', 1, 1, 1, '2019-03-09 18:07:48'),
	(25, '明天下午开会了', '请大家带好笔记本之类的东西哟', 1, 1, 1, '2019-03-09 18:07:48'),
	(28, '明天下午开会了', '请大家带好笔记本之类的东西哟', 1, 1, 1, '2019-03-09 18:07:48'),
	(66, '全体员工今天开会了哟', '全体员工今天开会了哟', 1, 1, 1, '2020-04-06 12:03:40'),
	(67, '全体员工今天开会了哟', '全体员工今天开会了哟', -1, 3, 1, '2020-04-06 12:03:40'),
	(68, '全体员工今天开会了哟', '全体员工今天开会了哟', -1, 4, 1, '2020-04-06 12:03:40'),
	(69, '全体员工今天开会了哟', '全体员工今天开会了哟', -1, 7, 1, '2020-04-06 12:03:40');
/*!40000 ALTER TABLE `fly_sys_user_notice` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=168 DEFAULT CHARSET=utf8 COMMENT='员工档案';

DELETE FROM `hrm_staff`;
/*!40000 ALTER TABLE `hrm_staff` DISABLE KEYS */;
INSERT INTO `hrm_staff` (`id`, `staff_no`, `name`, `gender`, `idcard`, `age`, `dept_id`, `position_id`, `marriage`, `politics`, `degree`, `major`, `qualification`, `position`, `social`, `mobile`, `qicq`, `email`, `zipcode`, `address`, `intro`, `create_user_id`, `create_time`) VALUES
	(164, 'XZ2543', 'XZ2543', 1, '511929198005127894', 100, '2', '4', '未婚', '团员', '本科', '电子商务', '计算机', '经理', '协会员', '18030402705', '1871720801', 'goodmuzi@qq.com', '', '成都市天河路', '这是一个好员工的呀', 0, '2020-03-31 10:15:42'),
	(167, 'DSA215455', 'DSA215455', 1, '511929198005127894', 100, '2', '4', '未婚', '团员', '本科', '电子商务', '计算机', '经理', '协会员', '18030402705', '1871720801', 'goodmuzi@qq.com', '', '这是那时呀', '这是一个好员工的呀', 0, '2020-03-31 10:11:09');
/*!40000 ALTER TABLE `hrm_staff` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=156 DEFAULT CHARSET=utf8 COMMENT='员工工作业绩';

DELETE FROM `hrm_staff_achiev`;
/*!40000 ALTER TABLE `hrm_staff_achiev` DISABLE KEYS */;
INSERT INTO `hrm_staff_achiev` (`id`, `staff_id`, `name`, `work_date`, `content`, `remark`, `create_user_id`, `create_time`) VALUES
	(155, 164, '零起飞科技 001', '2020-03-30', '零起飞科技 零起飞科技 零起飞科技 232323', '说明输入法2323', 1, '2020-03-31 08:24:32');
/*!40000 ALTER TABLE `hrm_staff_achiev` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=162 DEFAULT CHARSET=utf8 COMMENT='员工个人证书';

DELETE FROM `hrm_staff_certified`;
/*!40000 ALTER TABLE `hrm_staff_certified` DISABLE KEYS */;
INSERT INTO `hrm_staff_certified` (`id`, `staff_id`, `name`, `company`, `gettime`, `remark`, `create_user_id`, `create_time`) VALUES
	(157, 164, 'offic办工软件', '零起飞', '2020-03-31', '学校去考的哟', 1, '2020-03-31 08:53:50'),
	(158, 164, '12121212', '成都市', '2020-03-31', '还不晓得吧', 1, '2020-03-31 13:53:57'),
	(159, 167, '23', '2323', '2025-07-09', '', 1, '2020-03-31 13:55:29'),
	(160, 167, '23', '2323', '2025-07-09', '2323', 1, '2020-03-31 13:55:30'),
	(161, 164, '模压', '阿斯蒂芬', '2025-07-10', '', 1, '2020-03-31 13:55:49');
/*!40000 ALTER TABLE `hrm_staff_certified` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=160 DEFAULT CHARSET=utf8 COMMENT='员工劳动合作';

DELETE FROM `hrm_staff_contract`;
/*!40000 ALTER TABLE `hrm_staff_contract` DISABLE KEYS */;
INSERT INTO `hrm_staff_contract` (`id`, `staff_id`, `begin_date`, `end_date`, `content`, `remark`, `create_time`, `create_user_id`) VALUES
	(158, 164, '2020-03-31', '2030-12-27', '1、要要好好保存出来哟', '还不是的哟', '2020-03-31 10:00:06', 1),
	(159, 167, '2020-01-28', '2025-07-16', '这是一个长期的合同', '你要相恍如隔世哟', '2020-03-31 14:21:12', 1);
/*!40000 ALTER TABLE `hrm_staff_contract` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=159 DEFAULT CHARSET=utf8 COMMENT='员工用工记录';

DELETE FROM `hrm_staff_employ`;
/*!40000 ALTER TABLE `hrm_staff_employ` DISABLE KEYS */;
INSERT INTO `hrm_staff_employ` (`id`, `staff_id`, `position`, `work_date`, `content`, `remark`, `create_user_id`, `create_time`) VALUES
	(156, 164, '技术', '2020-03-31', '这是好个的荼内容吧', '没的说明', 1, '2020-03-31 08:40:38'),
	(157, 167, '总经办', '2020-03-31', '这是测试', '这是好', 1, '2020-03-31 11:57:36'),
	(158, 164, '商务', '2020-03-31', '测试', '测试备注说明', 1, '2020-03-31 13:48:31');
/*!40000 ALTER TABLE `hrm_staff_employ` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=160 DEFAULT CHARSET=utf8 COMMENT='员工考核记录';

DELETE FROM `hrm_staff_examine`;
/*!40000 ALTER TABLE `hrm_staff_examine` DISABLE KEYS */;
INSERT INTO `hrm_staff_examine` (`id`, `staff_id`, `exa_time`, `score`, `results`, `remark`, `create_user_id`, `create_time`) VALUES
	(158, 164, '2020-03-31', '100', '通过', '还可以哈', 1, '2020-03-31 09:07:49'),
	(159, 167, '2025-07-16', '345', '过了', '好的哈', 1, '2020-03-31 13:59:52');
/*!40000 ALTER TABLE `hrm_staff_examine` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=160 DEFAULT CHARSET=utf8 COMMENT='员工奖罚记录';

DELETE FROM `hrm_staff_reward`;
/*!40000 ALTER TABLE `hrm_staff_reward` DISABLE KEYS */;
INSERT INTO `hrm_staff_reward` (`id`, `staff_id`, `type`, `content`, `gettime`, `remark`, `create_user_id`, `create_time`) VALUES
	(158, 164, '奖励', '月度优秀员工', '2020-03-31', '一月一次', 1, '2020-03-31 09:26:39'),
	(159, 167, '处罚', '好的哈，不错的哟', '2020-03-31', '我们是中国人', 1, '2020-03-31 14:14:26');
/*!40000 ALTER TABLE `hrm_staff_reward` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=158 DEFAULT CHARSET=utf8 COMMENT='员工学习经历';

DELETE FROM `hrm_staff_school`;
/*!40000 ALTER TABLE `hrm_staff_school` DISABLE KEYS */;
INSERT INTO `hrm_staff_school` (`id`, `staff_id`, `name`, `begin_date`, `end_date`, `position`, `intro`, `create_time`) VALUES
	(155, 164, '电子科技大学校', '2020-01-28', '2029-07-12', '学生会', '', '2020-03-30 16:41:45'),
	(156, 164, 'SIP行业解决方案', '2020-01-27', '2029-11-22', '工好的', '', '2020-03-30 16:59:08'),
	(157, 164, '东软慧鼎HCM人力资源管理平台', '2020-01-27', '2024-06-11', '学生会的哟', '', '2020-03-30 17:05:34');
/*!40000 ALTER TABLE `hrm_staff_school` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=160 DEFAULT CHARSET=utf8 COMMENT='员工谈话记录';

DELETE FROM `hrm_staff_talk`;
/*!40000 ALTER TABLE `hrm_staff_talk` DISABLE KEYS */;
INSERT INTO `hrm_staff_talk` (`id`, `staff_id`, `name`, `content`, `gettime`, `remark`, `create_user_id`, `create_time`) VALUES
	(158, 164, '老板', '谈工资的事', '2020-03-31', '还是可以吧', 1, '2020-03-31 09:35:32'),
	(159, 167, '总经理', '这是测试谈的', '2020-03-31', '好吧', 1, '2020-03-31 14:18:19');
/*!40000 ALTER TABLE `hrm_staff_talk` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=160 DEFAULT CHARSET=utf8 COMMENT='员工工作经历';

DELETE FROM `hrm_staff_work`;
/*!40000 ALTER TABLE `hrm_staff_work` DISABLE KEYS */;
INSERT INTO `hrm_staff_work` (`id`, `staff_id`, `name`, `begin_date`, `end_date`, `position`, `intro`, `create_time`) VALUES
	(156, 0, 'SIP行业解决方案', '2020-03-30', '2030-11-06', '总经理', '', '2020-03-30 16:54:10'),
	(155, 0, '成都零起飞', '2009-11-12', '2020-03-03', '当官的2224444', '', '2020-03-30 16:31:50'),
	(157, 164, '医疗', '2020-01-28', '2024-06-11', '城55546', '', '2020-03-30 16:58:10'),
	(158, 164, '公司资质', '2020-01-28', '2025-07-10', '铃声 ', '', '2020-03-30 16:58:47'),
	(159, 164, '公司资质', '2020-01-28', '2025-07-10', '铃声 ', '', '2020-03-30 16:58:48');
/*!40000 ALTER TABLE `hrm_staff_work` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='采购合同';

DELETE FROM `pos_contract`;
/*!40000 ALTER TABLE `pos_contract` DISABLE KEYS */;
INSERT INTO `pos_contract` (`contract_id`, `contract_no`, `supplier_id`, `linkman_id`, `chance_id`, `website_id`, `start_date`, `end_date`, `our_user_id`, `money`, `goods_money`, `zero_money`, `back_money`, `owe_money`, `pay_money`, `unpaid_money`, `invoice_money`, `title`, `intro`, `status`, `back_status`, `pay_status`, `deliver_status`, `invoice_status`, `rece_status`, `create_user_id`, `create_time`) VALUES
	(1, '2106021696', 12, 1, 0, 0, '2021-06-02', '2021-12-31', 4, 2000.00, 0.00, 0.00, 0.00, 1499.50, 500.50, 0.00, 0.00, '天河一期', '', 2, 1, 2, 1, 1, 5, 1, '2021-06-02 16:46:56'),
	(2, '2106021754', 12, 1, 0, 0, '2021-06-02', '2020-01-28', 1, 5000.00, 0.00, 0.00, 0.00, 5000.00, 0.00, 0.00, 0.00, '天河二期', '', 1, 1, 1, 1, 1, 1, 1, '2021-06-02 18:00:10');
/*!40000 ALTER TABLE `pos_contract` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=72 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='采购合同附件';

DELETE FROM `pos_contract_file`;
/*!40000 ALTER TABLE `pos_contract_file` DISABLE KEYS */;
INSERT INTO `pos_contract_file` (`id`, `contract_id`, `name`, `type`, `remarks`, `filepath`, `create_user_id`, `create_time`) VALUES
	(70, 2, '2342342', '', '', '/upload/images/210603/20210603113256397.png', 0, NULL),
	(71, 2, '2342342', '', '', '/upload/images/210603/20210603113256912.png', 0, NULL);
/*!40000 ALTER TABLE `pos_contract_file` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='采购订单商品表';

DELETE FROM `pos_contract_list`;
/*!40000 ALTER TABLE `pos_contract_list` DISABLE KEYS */;
INSERT INTO `pos_contract_list` (`list_id`, `contract_id`, `goods_id`, `goods_name`, `sku_id`, `sku_name`, `sale_price`, `cost_price`, `num`, `into_num`, `owe_num`, `owe_money`, `adjust_money`, `goods_money`, `goods_picture`, `remarks`, `create_user_id`, `create_time`) VALUES
	(1, 1, 76, '老人鞋子', 25, '颜色:黑色,尺寸:40码', 0.00, 100.00, '10', '10', '0', 0.00, 0.00, 1000.00, 0, '', 1, '2021-06-02 17:56:59'),
	(2, 1, 76, '老人鞋子', 24, '颜色:黑色,尺寸:35码', 0.00, 100.00, '10', '10', '0', 0.00, 0.00, 1000.00, 0, '', 1, '2021-06-02 17:56:59');
/*!40000 ALTER TABLE `pos_contract_list` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='销售合同';

DELETE FROM `sal_contract`;
/*!40000 ALTER TABLE `sal_contract` DISABLE KEYS */;
INSERT INTO `sal_contract` (`contract_id`, `title`, `contract_no`, `customer_id`, `linkman_id`, `chance_id`, `website_id`, `start_date`, `end_date`, `our_user_id`, `money`, `goods_money`, `zero_money`, `back_money`, `owe_money`, `deliver_money`, `invoice_money`, `intro`, `status`, `back_status`, `deliver_status`, `invoice_status`, `renew_status`, `create_user_id`, `create_time`) VALUES
	(1, '天河项目订单', '2106021686', 1, 1, 0, 0, '2021-06-02', '2023-01-01', 1, 2000.00, 0.00, 0.00, 0.00, 2000.00, 0.00, 0.00, '', 2, 1, 5, 1, 1, 1, '2021-06-02 16:37:58'),
	(2, '', '', 0, 0, 0, 0, '2021-06-02', '2023-01-01', 0, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, '', 1, 1, 1, 1, 1, 1, '2021-06-03 10:49:59');
/*!40000 ALTER TABLE `sal_contract` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=70 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='销售合同明附件';

DELETE FROM `sal_contract_file`;
/*!40000 ALTER TABLE `sal_contract_file` DISABLE KEYS */;
INSERT INTO `sal_contract_file` (`id`, `contract_id`, `name`, `type`, `remarks`, `filepath`, `create_user_id`, `create_time`) VALUES
	(69, 1, '11111', '', '', '/upload/images/210603/20210603112117314.png', 0, NULL);
/*!40000 ALTER TABLE `sal_contract_file` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=67 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='销售合同明细表';

DELETE FROM `sal_contract_list`;
/*!40000 ALTER TABLE `sal_contract_list` DISABLE KEYS */;
INSERT INTO `sal_contract_list` (`list_id`, `contract_id`, `goods_id`, `goods_name`, `sku_id`, `sku_name`, `sale_price`, `cost_price`, `num`, `out_num`, `owe_num`, `owe_money`, `adjust_money`, `goods_money`, `goods_picture`, `remarks`, `create_user_id`, `create_time`) VALUES
	(65, 1, 76, '老人鞋子', 25, '颜色:黑色,尺寸:40码', 150.00, 0.00, 1, 1, 0, 0.00, 0.00, 150.00, 0, '', 1, '2021-06-02 17:58:26'),
	(66, 1, 76, '老人鞋子', 24, '颜色:黑色,尺寸:35码', 160.00, 0.00, 1, 1, 0, 0.00, 0.00, 160.00, 0, '', 1, '2021-06-02 17:58:26'),
	(64, 93, 76, '老人鞋子', 22, '颜色:白色,尺寸:35码', 300.00, 0.00, 1, 3, -3, -1200.00, 0.00, 300.00, 0, '', 1, '2021-06-02 15:00:06'),
	(63, 93, 76, '老人鞋子', 23, '颜色:白色,尺寸:40码', 160.00, 0.00, 1, 3, -3, -640.00, 0.00, 160.00, 0, '', 1, '2021-06-02 15:00:06');
/*!40000 ALTER TABLE `sal_contract_list` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=481 COMMENT='库存清单';

DELETE FROM `stock_goods_sku`;
/*!40000 ALTER TABLE `stock_goods_sku` DISABLE KEYS */;
INSERT INTO `stock_goods_sku` (`stock_goods_sku_id`, `sku_id`, `store_id`, `goods_id`, `goods_name`, `sku_name`, `sale_price`, `cost_price`, `total_cost_money`, `total_sale_money`, `total_profit_money`, `stock`, `code`, `create_time`, `update_time`) VALUES
	(1, 25, 8, 76, '老人鞋子', '颜色:黑色,尺寸:40码', 150.00, 94.44, 850.00, 1350.00, 500.00, 9, '', '2021-06-02 17:57:18', '2021-06-02 17:58:45'),
	(2, 24, 8, 76, '老人鞋子', '颜色:黑色,尺寸:35码', 160.00, 93.33, 840.00, 1440.00, 600.00, 9, '', '2021-06-02 17:57:18', '2021-06-02 17:58:45');
/*!40000 ALTER TABLE `stock_goods_sku` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='入库单';

DELETE FROM `stock_into`;
/*!40000 ALTER TABLE `stock_into` DISABLE KEYS */;
INSERT INTO `stock_into` (`into_id`, `store_id`, `contract_id`, `title`, `money`, `number`, `intro`, `status`, `into_user_id`, `into_time`, `into_type`, `create_user_id`, `create_time`) VALUES
	(1, 8, 1, '天河一期', 2000.00, 20, '', 1, 1, '2021-06-02 17:57:18', '采购入库', 1, '2021-06-02 17:57:04');
/*!40000 ALTER TABLE `stock_into` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='入库单明细表';

DELETE FROM `stock_into_list`;
/*!40000 ALTER TABLE `stock_into_list` DISABLE KEYS */;
INSERT INTO `stock_into_list` (`list_id`, `into_id`, `contract_id`, `contract_list_id`, `store_id`, `goods_id`, `goods_name`, `sku_id`, `sku_name`, `number`, `price`, `money`, `remarks`, `create_user_id`, `create_time`, `into_user_id`, `into_time`) VALUES
	(1, 1, 1, 1, 8, 76, '老人鞋子', 25, '颜色:黑色,尺寸:40码', '10', 100.00, 1000.00, '', 1, '2021-06-02 17:57:04', 1, '2021-06-02 17:57:18'),
	(2, 1, 1, 2, 8, 76, '老人鞋子', 24, '颜色:黑色,尺寸:35码', '10', 100.00, 1000.00, '', 1, '2021-06-02 17:57:04', 1, '2021-06-02 17:57:18');
/*!40000 ALTER TABLE `stock_into_list` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='入库单';

DELETE FROM `stock_out`;
/*!40000 ALTER TABLE `stock_out` DISABLE KEYS */;
INSERT INTO `stock_out` (`out_id`, `store_id`, `contract_id`, `title`, `money`, `number`, `intro`, `status`, `out_user_id`, `out_time`, `out_type`, `create_user_id`, `create_time`) VALUES
	(1, 8, 1, '天河项目订单', 310.00, 2, '', 1, 1, '2021-06-02 17:58:45', '销售出库', 1, '2021-06-02 17:58:32');
/*!40000 ALTER TABLE `stock_out` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 AVG_ROW_LENGTH=289 COMMENT='入库单明细表';

DELETE FROM `stock_out_list`;
/*!40000 ALTER TABLE `stock_out_list` DISABLE KEYS */;
INSERT INTO `stock_out_list` (`list_id`, `out_id`, `contract_id`, `contract_list_id`, `store_id`, `goods_id`, `goods_name`, `sku_id`, `sku_name`, `number`, `price`, `money`, `remarks`, `create_user_id`, `create_time`, `out_user_id`, `out_time`) VALUES
	(1, 1, 1, 65, 8, 76, '老人鞋子', 25, '颜色:黑色,尺寸:40码', '1', 0.00, 150.00, '', 1, '2021-06-02 17:58:32', 1, '2021-06-02 17:58:45'),
	(2, 1, 1, 66, 8, 76, '老人鞋子', 24, '颜色:黑色,尺寸:35码', '1', 0.00, 160.00, '', 1, '2021-06-02 17:58:32', 1, '2021-06-02 17:58:45');
/*!40000 ALTER TABLE `stock_out_list` ENABLE KEYS */;

CREATE TABLE `stock_store` (
  `store_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '名称',
  `create_user_id` int(11) NOT NULL DEFAULT '0' COMMENT '创建人员',
  `sort` smallint(2) NOT NULL DEFAULT '0',
  `visible` smallint(2) NOT NULL DEFAULT '0',
  `intro` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`store_id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COMMENT='仓库管理';

DELETE FROM `stock_store`;
/*!40000 ALTER TABLE `stock_store` DISABLE KEYS */;
INSERT INTO `stock_store` (`store_id`, `name`, `create_user_id`, `own_user_id`, `sort`, `visible`, `create_time`) VALUES
	(8, '一号仓库12456', 0, '', 1, 1, '2019-05-20 09:39:27'),
	(10, '222444', 1, '', 22, 1, '2019-05-20 09:39:27');
/*!40000 ALTER TABLE `stock_store` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8 COMMENT='供应商联系人';

DELETE FROM `sup_linkman`;
/*!40000 ALTER TABLE `sup_linkman` DISABLE KEYS */;
INSERT INTO `sup_linkman` (`linkman_id`, `supplier_id`, `name`, `gender`, `postion`, `tel`, `mobile`, `qicq`, `email`, `zipcode`, `address`, `intro`, `create_time`, `create_user_id`) VALUES
	(1, 12, '枭哥', 1, '技术部', '02888641234', '13688868655', '1585925559', 'web@07fly.com', '610000', '成都市新路', '这个小伙子不错,一个很好的人的呀', '2013-09-06 10:26:59', 0),
	(2, 12, '二娃', 1, '1', '12345678', '12345678', '', '1@1.com', '', '', '', '2013-09-23 14:16:55', 0),
	(3, 12, '三娃', 1, '1', '12345678', '12345678', '', '1@1.com', '', '', '', '2013-09-23 14:17:00', 0),
	(4, 13, '李大爷', 1, '经理', '12', '18030402705', '123', 'muziii@163.com', '', '成都校园路100号', '', '2016-04-24 22:07:37', 0),
	(5, 0, '李大哥', 0, '', '02832145678', '', '', '', '', '', '', '2018-12-21 17:43:35', 4),
	(6, 17, '李大哥', 0, '', '02832145678', '', '', '', '', '', '', '2018-12-21 17:44:47', 4),
	(7, 13, '李大二', 1, '村长', '12', '18030402705', '', '', '', '', '', '2018-12-21 22:17:14', 4),
	(8, 13, '李大二', 1, '村长', '12', '18030402705', '', '', '', '', '', '2018-12-21 22:17:48', 4),
	(9, 0, '李大二', 1, '村长', '12', '18030402705', '', '', '', '', '', '2018-12-21 22:17:58', 4),
	(10, 20, '11', 0, '', '1', '', '', '', '', '', '', '2019-05-04 17:26:59', 1),
	(11, 13, 'dadfadf', 1, '123', '123', 'a1123', '123', '123', '', '123', '', '2019-05-04 18:08:18', 1);
/*!40000 ALTER TABLE `sup_linkman` ENABLE KEYS */;

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
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8 COMMENT='供应商';

DELETE FROM `sup_supplier`;
/*!40000 ALTER TABLE `sup_supplier` DISABLE KEYS */;
INSERT INTO `sup_supplier` (`supplier_id`, `name`, `area_id`, `create_user_id`, `level`, `ecotype`, `trade`, `satisfy`, `credit`, `address`, `linkman`, `website`, `zipcode`, `tel`, `fax`, `email`, `intro`, `create_time`, `test`) VALUES
	(1, '山西太原', 0, 0, 0, 27, 24, 3, 3, '', '', 'http://www.07fly.com', '', '02987651123', '', '', '', '2013-09-05 15:29:12', NULL),
	(12, '上海八达', 0, 0, 0, 30, 48, 3, 3, ' 上海市', '李小姐', 'http://www.00808.com', '', '61833149', '', '', '这还是一家不错的公司的哟', '2013-09-05 15:29:12', NULL),
	(13, '成都零起飞网络', 0, 0, 0, 28, 24, 3, 3, '', '李先生', 'http://www.07fly.com', '', '18030402705', '', '', '这个公司还是不错哟', '2016-04-24 22:06:47', NULL),
	(16, '成都百度科技', 0, 4, 0, 25, 24, 3, 3, '成都市大天路', '李大哥', '', '', '02832145678', '024854', 'goodmuzi@qq.com', '', '2018-12-21 17:44:12', NULL);

SET FOREIGN_KEY_CHECKS=1;
