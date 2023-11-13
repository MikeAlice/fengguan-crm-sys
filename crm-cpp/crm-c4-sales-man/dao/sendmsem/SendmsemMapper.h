#pragma once
#include "domain/do/sendmsem/SendmsemDO.h"
#include "Mapper.h"
/*
 Copyright Zero One Star. All rights reserved.

 @Author: william
 @Date: 2023/10/25 13:32:35

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
#ifndef _SENDMSEMMAPPER_H_
#define _SENDMSEMMAPPER_H_

class SendmsemMapper : public Mapper<SendmsemDO>
{
public:
	SendmsemDO mapper(ResultSet* resultSet) const override
	{
		SendmsemDO data;
		data.setRecv_name(resultSet->getString(1));
		data.setPhone(resultSet->getString(2));
		data.setTime(resultSet->getString(3));
		data.setMail(resultSet->getString(4));
		return data;
	}
};
#endif // !_SENDMSEMMAPPER_H_