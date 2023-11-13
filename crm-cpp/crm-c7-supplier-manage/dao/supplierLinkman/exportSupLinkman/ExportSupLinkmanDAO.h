#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 19:21:52

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
#ifndef _EXPORTSUPLINKMANDAO_H_
#define _EXPORTSUPLINKMANDAO_H_

#include "BaseDAO.h"
#include <list>
#include <vector>
#include "domain/query/supplierLinkman/ExportSupLinkmanQuery.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"

class ExportSupLinkmanDAO : public BaseDAO
{
public:
	// 获取导出数据
	std::list<SupplierLinkmanDO> selectAll(const ExportSupLinkmanQuery::Wrapper& query, const std::list<std::string>& extends);
	// 获取表头
	std::list<std::string> selectField(const std::string& table);
	// 获取扩展字段
	std::list<std::string> selectExtField();
};

#endif // !_EXPORTSUPLINKMANDAO_H_