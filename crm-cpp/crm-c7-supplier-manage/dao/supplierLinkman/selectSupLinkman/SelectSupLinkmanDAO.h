#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/01 0:20:25

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
#ifndef _SELECTSUPLINKMANDAO_H_
#define _SELECTSUPLINKMANDAO_H_

#include "BaseDAO.h"
#include "domain/query/supplierLinkman/SupplierLinkmanQuery.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"

/**
 * 获取供应商联系人列表数据持久层
 * 负责人: Andrew
 */
class SelectSupLinkmanDAO : public BaseDAO
{
public:
	// 条件查询数据总行数
	uint64_t count(const SupplierLinkmanQuery::Wrapper& query);
	// 分页条件查询数据
	std::list<SupplierLinkmanDO> selectAll(const SupplierLinkmanQuery::Wrapper& query, const std::list<std::string>& extends);
	// 查询供应商联系人扩展字段
	std::list<std::string> selectExtField();
};

#endif // !_SELECTSUPLINKMANDAO_H_