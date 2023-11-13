#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/27

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
#ifndef _SALCONTRACTBASICINFOMAPPER_H_
#define _SALCONTRACTBASICINFOMAPPER_H_

#include "Mapper.h"
#include "domain/do/salContract/SalContractBasicInfoDO.h"

/**
 * 销售合同基础信息列表字段匹配映射
 * 负责人：咫尺之书
 */
class SalContractBasicInfoMapper : public Mapper<SalContractBasicInfoDO>
{
public:
	SalContractBasicInfoDO mapper(ResultSet* resultSet) const override
	{
		SalContractBasicInfoDO data;

		data.setContractID(resultSet->getInt(1));
		//data.setContractNO(resultSet->getString(2));
		data.setTitle(resultSet->getString(2));
		data.setCustomerID(resultSet->getInt(3));
		data.setLinkmanID(resultSet->getInt(4));
		data.setStartDate(resultSet->getString(5));
		data.setEndDate(resultSet->getString(6));
		data.setMoney(resultSet->getDouble(7));
		data.setIntro(resultSet->getString(8));
		data.setOurUserID(resultSet->getInt(9));

		return data;
	}
};

#endif // !_SALCONTRACTBASICINFOMAPPER_H_