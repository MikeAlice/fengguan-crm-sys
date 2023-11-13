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
#ifndef _SALCONTRACTDAO_H_
#define _SALCONTRACTDAO_H_
#include "BaseDAO.h"
#include "domain/do/salContract/SalContractBasicInfoDO.h"
#include "domain/do/salContract/DeliverStatusDO.h"

/**
 * 销售合同DAO实现
 */
class SalContractDAO : public BaseDAO
{
public:
	/**
	 * 销售合同 - 修改销售合同基础信息DAO实现
	 * 功能：指定销售合同唯一标识修改销售合同基础信息数据
	 */
	bool modifySalContractBasicInfo(const SalContractBasicInfoDO& data);
	/**
	 * 销售合同 - 修改交付状态DAO实现
	 * 功能：指定销售合同唯一标识修改交付状态数据
	 */
	bool modifyDeliverStatus(const DeliverStatusDO& data);
};

#endif // !_SALCONTRACTDAO_H_