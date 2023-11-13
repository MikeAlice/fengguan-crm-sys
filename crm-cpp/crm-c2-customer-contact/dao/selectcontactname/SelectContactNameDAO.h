#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/30 10:38:29

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
#ifndef _GETCUSTOMERNAME_DAO_
#define _GETCUSTOMERNAME_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contact/ContactListDO.h"
#include "../../domain/query/contact/ListContectNameQuery.h"

/**
 * 示例表数据库操作实现
 */
class SelectContactNameDAO : public BaseDAO
{
public:
	// 通过客户id查询数据
	std::list<ContactListDO> selectByName(const string& name, const ListContactNameQuery::Wrapper& query);
};
#endif // !_GETCUSTOMERNAME_DAO_

