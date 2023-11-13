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
/*
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
*/
#ifndef _CST_CHANCE_DO_
#define _CST_CHANCE_DO_
#include "../DoInclude.h"

/**
 * 销售机会数据库实体类
 */
class Cst_chanceDO
{
	// 销售机会id
	CC_SYNTHESIZE(int, chance_id, Chance_id);
	// 客户ID
	CC_SYNTHESIZE(int, customer_id, Customer_id);
	//客户姓名
	CC_SYNTHESIZE(string, customer_name, Customer_name);
	// 联系人id
	CC_SYNTHESIZE(string, linkman_id, Linkman_id);
	//联系人姓名
	CC_SYNTHESIZE(string, linkman_name, Linkman_name);
	// 发现时间
	CC_SYNTHESIZE(string, find_date, Find_date);
	// 预计签单时间
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 谈判状态
	CC_SYNTHESIZE(int32_t, salestage, Salestage);
	// 预计金额
	CC_SYNTHESIZE(int64_t, money, Money);
	// 预计可能性成功率
	CC_SYNTHESIZE(int32_t, success_rate, Success_rate);
	// userID
	CC_SYNTHESIZE(int32_t, userID, UserID);
	// 主题
	CC_SYNTHESIZE(string, name, Name);
	// intro
	CC_SYNTHESIZE(string, intro, Intro);
	// status
	CC_SYNTHESIZE(int32_t, status, Status);
	// create_user_id
	CC_SYNTHESIZE(int32_t, create_user_id, Create_user_id);
	// create_time
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	Cst_chanceDO() {
		chance_id = 0;//主键、自增长
		customer_id = 0;
		linkman_id = '0';
		find_date = "";
		bill_date = "";
		salestage = 0;
		money = 0;
		success_rate = 0;
		userID = 0;
		name = "";
		intro = "";
		status = 1;
		create_user_id = 0;
		create_time = "";  //NULL NOT
	}
};

#endif // !_CST_CHANCE_DO_