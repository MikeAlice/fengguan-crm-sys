#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/30 12:28:37

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

#ifndef _CONTACTLIST_DO_
#define _CONTACTLIST_DO_
#include "../DoInclude.h"

/**
 * ��ϵ�����ݿ�ʵ����
 */
class ContactListDO
{
	// ��ϵ�˱��
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkman_id);
	// �ͻ����
	CC_SYNTHESIZE(uint64_t, customer_id, Customer_id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(uint64_t, gender, Gender);
	// ְλ
	CC_SYNTHESIZE(string, postion, Postion);
	// ����
	CC_SYNTHESIZE(string, tel, Tel);
	// �ֻ�
	CC_SYNTHESIZE(string, mobile, Mobile);
	// qq
	CC_SYNTHESIZE(string, qicq, Qicq);
	// ��������
	CC_SYNTHESIZE(string, email, Email);
	// ��������
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// ��ַ
	CC_SYNTHESIZE(string, address, Address);
	// ����
	CC_SYNTHESIZE(string, intro, Intro);
	// ������id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	ContactListDO() {
		linkman_id = 1;
		customer_id = 1;
		name = "";
		gender = 1;
		postion = "";
		tel = "";
		mobile = "";
		qicq = "";
		email = "";
		zipcode = "";
		address = "";
		intro = "";
		create_user_id = 1;
		create_time = "";
	}
};
#endif // !_CONTACTLIST_DO_