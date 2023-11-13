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
#ifndef _SALCONTRACTLISTDAO_H_
#define _SALCONTRACTLISTDAO_H_
#include "BaseDAO.h"
#include "domain/do/salContractList/SalContractListDO.h"

/**
 * 销售合同明细DAO实现
 */
class SalContractListDAO : public BaseDAO
{
public:
	/**
	 * 销售合同明细 - 录入明细DAO实现
	 * 功能：指定销售合同唯一标识录入明细
	 */
	bool inputList(const SalContractListDO& data);
};

#endif // !_SALCONTRACTLISTDAO_H_