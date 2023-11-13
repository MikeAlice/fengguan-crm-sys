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
  `find_date` date DEFAULT NULL COMMENT '����ʱ��',
  `bill_date` date DEFAULT NULL COMMENT 'Ԥ��ǩ��ʱ��',
  `salestage` int(4) NOT NULL DEFAULT '0' COMMENT '̸��״̬',
  `money` decimal(20,2) NOT NULL DEFAULT '0.00' COMMENT 'Ԥ�ƽ��',
  `success_rate` int(2) NOT NULL DEFAULT '0' COMMENT 'Ԥ�ƿ����Գɹ���',
  `userID` int(16) NOT NULL DEFAULT '0',
  `name` varchar(256) NOT NULL DEFAULT '' COMMENT '����',
  `intro` varchar(256) NOT NULL DEFAULT '',
  `status` smallint(1) NOT NULL DEFAULT '1',
  `create_user_id` int(16) NOT NULL DEFAULT '0',
  `create_time` datetime NOT NULL,
  PRIMARY KEY (`chance_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COMMENT='���ۻ���';
*/
#ifndef _CST_CHANCE_DO_
#define _CST_CHANCE_DO_
#include "../DoInclude.h"

/**
 * ���ۻ������ݿ�ʵ����
 */
class Cst_chanceDO
{
	// ���ۻ���id
	CC_SYNTHESIZE(int, chance_id, Chance_id);
	// �ͻ�ID
	CC_SYNTHESIZE(int, customer_id, Customer_id);
	//�ͻ�����
	CC_SYNTHESIZE(string, customer_name, Customer_name);
	// ��ϵ��id
	CC_SYNTHESIZE(string, linkman_id, Linkman_id);
	//��ϵ������
	CC_SYNTHESIZE(string, linkman_name, Linkman_name);
	// ����ʱ��
	CC_SYNTHESIZE(string, find_date, Find_date);
	// Ԥ��ǩ��ʱ��
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// ̸��״̬
	CC_SYNTHESIZE(int32_t, salestage, Salestage);
	// Ԥ�ƽ��
	CC_SYNTHESIZE(int64_t, money, Money);
	// Ԥ�ƿ����Գɹ���
	CC_SYNTHESIZE(int32_t, success_rate, Success_rate);
	// userID
	CC_SYNTHESIZE(int32_t, userID, UserID);
	// ����
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
		chance_id = 0;//������������
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