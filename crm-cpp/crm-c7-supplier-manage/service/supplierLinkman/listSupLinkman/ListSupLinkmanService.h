#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/01 0:13:41

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
#ifndef _LISTSUPLINKMANSERVICE_H_
#define _LISTSUPLINKMANSERVICE_H_

#include "domain/query/supplierLinkman/SupplierLinkmanQuery.h"
#include "domain/dto/supplierLinkman/SupplierLinkmanDTO.h"

/**
 * 获取供应商联系人列表业务逻辑层
 * 负责人: Andrew
 */
class ListSupLinkmanService
{
	const std::string redis_title = "sup_linkman_ext_field";
public:
	/**
	 * 按分页条件查询供应商联系人列表
	 * @param const SupplierLinkmanQuery::Wrapper& query: 用于解析分页条件
	 * @return SupplierLinkmanPageDTO::Wrapper: 返回查询结果, 包装到分页DTO
	 */
	SupplierLinkmanPageDTO::Wrapper listAll(const SupplierLinkmanQuery::Wrapper& query);
};

#endif // !_LISTSUPLINKMANSERVICE_H_