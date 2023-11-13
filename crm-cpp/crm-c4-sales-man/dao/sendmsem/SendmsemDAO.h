#pragma once
#include "BaseDAO.h"
#include "domain/do/sendmsem/SendmsemDO.h"
/*
 Copyright Zero One Star. All rights reserved.

 @Author: william
 @Date: 2023/10/25 11:03:20

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
#ifndef _SENDMSEMDAO_H_
#define _SENDMSEMDAO_H_

class SendmsemDAO : public BaseDAO
{
public:
	// 通过id查询数据
	list<SendmsemDO> selectByid(int id);
};

#endif // !_SENDMSEMDAO_H_