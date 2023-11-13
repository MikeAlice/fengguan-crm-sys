#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/27 22:50:56

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
#ifndef _SAVESUPLINKMANSERVICE_H_
#define _SAVESUPLINKMANSERVICE_H_

#include "domain/dto/supplierLinkman/SupplierLinkmanDTO.h"

/**
 * 新增供应商联系人service业务逻辑层
 * 负责人: Andrew
 */
class SaveSupLinkmanService
{
public:
	/**
	 * 新增供应商联系人
	 * @param const AddSupplierLinkmanDTO::Wrapper&: 传入DTO领域模型, 用于解析新增数据
	 * @param const PayloadDTO&: 用于获取用户信息
	 * @return UInt64: 返回新增供应商联系人唯一标识ID
	 */
	uint64_t saveSupLinkman(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_SAVESUPLINKMANSERVICE_H_