#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _CUSTOMER_DO_
#define _CUSTOMER_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类  cst_customer表
 */
//cst_customer
class CustomerDO
{
	//客户id
	CC_SYNTHESIZE(int, customer_id, CusId);
	//客户名称
	CC_SYNTHESIZE(string, name, CName);
public:
	CustomerDO() {
		name = "abc";
		customer_id = 123;
	}
};

#endif // !_CUSTOMER_DO_