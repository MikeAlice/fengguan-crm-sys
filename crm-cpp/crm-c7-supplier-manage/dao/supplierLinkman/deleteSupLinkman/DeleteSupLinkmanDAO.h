#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/30 12:15:34

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
#ifndef _DELETESUPLINKMANDAO_H_
#define _DELETESUPLINKMANDAO_H_

#include "BaseDAO.h"

/**
 * 删除供应商联系人DAO层
 * 负责人: Andrew
 */
class DeleteSupLinkmanDAO : public BaseDAO
{
public:
	/**
	 * 执行删除单个数据操作
	 * @param const uint64_t id: 将要删除的id
	 * @return bool: 是否删除成功
	 */
	bool deleteSupLinkman(const uint64_t id);
};

#endif // !_DELETESUPLINKMANDAO_H_