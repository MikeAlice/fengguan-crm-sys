#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/24 20:06:41

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
#ifndef _SUPPLIERDO_H_
#define _SUPPLIERDO_H_

#include "../DoInclude.h"

/**
 * ��Ӧ�����ݿ�ʵ����
 * ������: Andrew
 */
class SupplierDO
{
	// ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// ��Ӧ������
	CC_SYNTHESIZE(string, name, Name);
	// ���ڵ���
	CC_SYNTHESIZE(uint64_t, area_id, AreaId);
	// �ͻ��ȼ�
	CC_SYNTHESIZE(uint64_t, level, Level);
	// ��������
	CC_SYNTHESIZE(uint64_t, ecotype, Ecotype);
	// ��ҵ
	CC_SYNTHESIZE(uint64_t, trade, Trade);
	// ����ȣ�1-5����Ĭ��Ϊ3
	CC_SYNTHESIZE(uint8_t, satisfy, Satisfy);
	// ���öȣ�1-5����Ĭ��Ϊ3
	CC_SYNTHESIZE(uint8_t, credit, Credit);
	// ��վ
	CC_SYNTHESIZE(uint64_t, website, Website);
	// ��Ӧ����ϵ��ID
	CC_SYNTHESIZE(uint64_t, linkman, Linkman);
	// ��Ӧ����ϵ������
	CC_SYNTHESIZE(string, linkman_name, LinkmanName);
	// ����
	CC_SYNTHESIZE(string, tel, Tel);
	// ����
	CC_SYNTHESIZE(string, fax, Fax);
	// ����
	CC_SYNTHESIZE(string, email, Email);
	// ��ַ
	CC_SYNTHESIZE(string, address, Address);
	// ����
	CC_SYNTHESIZE(string, intro, Intro);
	// ��������
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// �����û�ID
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	// ��չ�ֶ�
	CC_SYNTHESIZE_MAP(string, string, ext_fields, ExtFields);
};

#endif // !_SUPPLIERDO_H_