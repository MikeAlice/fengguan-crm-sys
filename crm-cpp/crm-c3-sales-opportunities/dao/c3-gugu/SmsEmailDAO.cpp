#include "stdafx.h"
#include <sstream>
#include "SmsMailDAO.h"
#include"SmsEmailMapper.h"

list<EmailDO> SmsEmailDAO::queryEmail(const int& chance_id)
{
    string sql = "SELECT `name`,`email` FROM `cst_linkman` WHERE `linkman_id` =(select `linkman_id` from `cst_chance` where `chance_id=?)\
     UNION select `name` from `cst_chance` where `chance_id=?";
    EmailMapper mapper;
    return sqlSession->executeQuery<EmailDO, EmailMapper>(sql, mapper, "%ui", chance_id);
}

list<SmsDO> SmsEmailDAO::queryMobile(const int& chance_id)
{
    string sql = "SELECT `name`,`mobile` FROM `cst_linkman` WHERE `linkman_id` =(select `linkman_id` from `cst_chance` where `chance_id=?)\
        UNION select `name` from `cst_chance` where `chance_id=?";

    SmsMapper mapper;
    return sqlSession->executeQuery<SmsDO, SmsMapper>(sql, mapper, "%ui", chance_id);
}
/*

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


*/