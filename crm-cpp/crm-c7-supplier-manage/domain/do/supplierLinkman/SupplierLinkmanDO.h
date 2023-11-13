#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/24 19:14:21

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
#ifndef _SUPPLIERLINKMANDO_H_
#define _SUPPLIERLINKMANDO_H_

#include "../DoInclude.h"

/**
 * ��Ӧ����ϵ�����ݿ�ʵ����
 * ������: Andrew
 */
class SupplierLinkmanDO
{
	// ��ϵ��ID
	CC_SYNTHESIZE(uint64_t, linkman_id, LinkmanId);
	// ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// ��ϵ������
	CC_SYNTHESIZE(string, name, Name);
	// ��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	// �Ա�
	CC_SYNTHESIZE(uint64_t, gender, Gender);
	// ְλ
	CC_SYNTHESIZE(string, position, Position);
	// ����
	CC_SYNTHESIZE(string, tel, Tel);
	// �ֻ���
	CC_SYNTHESIZE(string, mobile, Mobile);
	// QQ
	CC_SYNTHESIZE(string, qicq, Qicq);
	// ����
	CC_SYNTHESIZE(string, email, Email);
	// ��������
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// ��ַ
	CC_SYNTHESIZE(string, address, Address);
	// ����
	CC_SYNTHESIZE(string, intro, Intro);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// �����û�ID
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	// ��չ�ֶ�
	CC_SYNTHESIZE_MAP(string, string, ext_fields, ExtFields);
};

#endif // !_SUPPLIERLINKMANDO_H_