#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 19:53:22

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
#ifndef _SUPPLIERLINKMANMAPPER_H_
#define _SUPPLIERLINKMANMAPPER_H_

#include "Mapper.h"
#include <map>
#include <string>
#include "domain/do/Sales/Cst_chanceDO.h"
#include "domain/do/CstFieldExt/CstFieldExtDO.h"

class SalesOpportunityMapper : public Mapper<Cst_chanceDO>
{
public:
	Cst_chanceDO mapper(ResultSet* resultSet) const override
	{
		Cst_chanceDO data;
		data.setChance_id(resultSet->getUInt64(1));
		data.setCustomer_id(resultSet->getUInt64(2));
		data.setLinkman_id(resultSet->getString(3));
		data.setFind_date(resultSet->getString(4));
		data.setBill_date(resultSet->getString(5));
		data.setSalestage(resultSet->getUInt64(6));
		data.setMoney(resultSet->getUInt64(7));
		data.setSuccess_rate(resultSet->getUInt64(8));
		data.setUserID(resultSet->getUInt64(9));
		data.setName(resultSet->getString(10));
		data.setIntro(resultSet->getString(11));
		data.setStatus(resultSet->getUInt(12));
		data.setCreate_user_id(resultSet->getUInt(13));
		data.setCreate_time(resultSet->getString(14));
		return data;
	}
};

#endif // !_SUPPLIERLINKMANMAPPER_H_