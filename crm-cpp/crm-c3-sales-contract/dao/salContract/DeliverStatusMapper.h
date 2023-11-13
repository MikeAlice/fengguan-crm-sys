#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/28

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
#ifndef _DELIVERSTATUSMAPPER_H_
#define _DELIVERSTATUSMAPPER_H_

#include "Mapper.h"
#include "domain/do/salContract/DeliverStatusDO.h"

/**
 * 销售合同交付状态列表字段匹配映射
 * 负责人：咫尺之书
 */
class DeliverStatusMapper : public Mapper<DeliverStatusDO>
{
public:
	DeliverStatusDO mapper(ResultSet* resultSet) const override
	{
		DeliverStatusDO data;

		data.setContractID(resultSet->getInt(1));
		data.setDeliverStatus(resultSet->getInt(2));
		return data;
	}
};

#endif // !_DELIVERSTATUSMAPPER_H_