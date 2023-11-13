#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/29

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
#ifndef _SALCONTRACTLISTMAPPER_H_
#define _SALCONTRACTLISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/salContractList/SalContractListDO.h"

/**
 * 销售合同明细列表字段匹配映射
 * 负责人：咫尺之书
 */
class SalContractListMapper : public Mapper<SalContractListDO>
{
public:
	SalContractListDO mapper(ResultSet* resultSet) const override
	{
		SalContractListDO data;

		data.setContractID(resultSet->getInt(1));
		data.setGoodsName(resultSet->getString(2));
		data.setGoodsID(resultSet->getInt(3));
		data.setSkuID(resultSet->getInt(4));
		data.setSkuName(resultSet->getString(5));
		data.setSalePrice(resultSet->getDouble(6));
		data.setNum(resultSet->getInt(7));
		data.setGoodsMoney(resultSet->getDouble(8));
		data.setRemarks(resultSet->getString(9));

		return data;
	}
};

#endif // !_SALCONTRACTLISTMAPPER_H_