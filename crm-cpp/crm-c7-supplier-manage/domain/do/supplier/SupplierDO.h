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
 * 供应商数据库实体类
 * 负责人: Andrew
 */
class SupplierDO
{
	// 供应商ID
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// 供应商名称
	CC_SYNTHESIZE(string, name, Name);
	// 所在地区
	CC_SYNTHESIZE(uint64_t, area_id, AreaId);
	// 客户等级
	CC_SYNTHESIZE(uint64_t, level, Level);
	// 经济类型
	CC_SYNTHESIZE(uint64_t, ecotype, Ecotype);
	// 行业
	CC_SYNTHESIZE(uint64_t, trade, Trade);
	// 满意度（1-5），默认为3
	CC_SYNTHESIZE(uint8_t, satisfy, Satisfy);
	// 信用度（1-5），默认为3
	CC_SYNTHESIZE(uint8_t, credit, Credit);
	// 网站
	CC_SYNTHESIZE(uint64_t, website, Website);
	// 供应商联系人ID
	CC_SYNTHESIZE(uint64_t, linkman, Linkman);
	// 供应商联系人名称
	CC_SYNTHESIZE(string, linkman_name, LinkmanName);
	// 座机
	CC_SYNTHESIZE(string, tel, Tel);
	// 传真
	CC_SYNTHESIZE(string, fax, Fax);
	// 邮箱
	CC_SYNTHESIZE(string, email, Email);
	// 地址
	CC_SYNTHESIZE(string, address, Address);
	// 介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 邮政编码
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 创建用户ID
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	// 扩展字段
	CC_SYNTHESIZE_MAP(string, string, ext_fields, ExtFields);
};

#endif // !_SUPPLIERDO_H_