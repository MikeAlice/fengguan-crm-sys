#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 19:12:25

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
#ifndef _EXPORTSUPLINKMANSERVICE_H_
#define _EXPORTSUPLINKMANSERVICE_H_

#include <string>
#include <list>
#include "domain/query/supplierLinkman/ExportSupLinkmanQuery.h"

/**
 * 导出供应商联系人Service
 * 负责人: Andrew
 */
class ExportSupLinkmanService
{
	const std::string redis_title = "sup_linkman_ext_field";
public:
	std::string exportSupLinkman(const ExportSupLinkmanQuery::Wrapper& query);
};

#endif // !_EXPORTSUPLINKMANSERVICE_H_