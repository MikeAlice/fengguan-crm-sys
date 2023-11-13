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
 * 供应商联系人数据库实体类
 * 负责人: Andrew
 */
class SupplierLinkmanDO
{
	// 联系人ID
	CC_SYNTHESIZE(uint64_t, linkman_id, LinkmanId);
	// 供应商ID
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// 联系人姓名
	CC_SYNTHESIZE(string, name, Name);
	// 供应商名称
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	// 性别
	CC_SYNTHESIZE(uint64_t, gender, Gender);
	// 职位
	CC_SYNTHESIZE(string, position, Position);
	// 座机
	CC_SYNTHESIZE(string, tel, Tel);
	// 手机号
	CC_SYNTHESIZE(string, mobile, Mobile);
	// QQ
	CC_SYNTHESIZE(string, qicq, Qicq);
	// 邮箱
	CC_SYNTHESIZE(string, email, Email);
	// 邮政编码
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// 地址
	CC_SYNTHESIZE(string, address, Address);
	// 介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 创建用户ID
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	// 扩展字段
	CC_SYNTHESIZE_MAP(string, string, ext_fields, ExtFields);
};

#endif // !_SUPPLIERLINKMANDO_H_