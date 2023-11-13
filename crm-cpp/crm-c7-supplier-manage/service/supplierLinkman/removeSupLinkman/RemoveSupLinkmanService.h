#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/30 12:09:18

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
#ifndef _REMOVESUPLINKMANSERVICE_H_
#define _REMOVESUPLINKMANSERVICE_H_

#include "domain/dto/supplierLinkman/RemoveSupLinkmanDTO.h"
#include "domain/dto/PayloadDTO.h"

/**
 * 删除供应商联系人业务逻辑层
 * 负责人: Andrew
 */
class RemoveSupLinkmanService
{
public:
	/**
	 * 执行删除业务逻辑
	 * @param const RemoveSupLinkmanDTO::Wrapper&: 用于解析批量删除id
	 * @return bool: 是否删除成功
	 */
	bool removeSupLinkman(const RemoveSupLinkmanDTO::Wrapper& dto);
};

#endif // !_REMOVESUPLINKMANSERVICE_H_