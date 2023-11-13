#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
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
#ifndef _DELIVERSTATUSDO_H_
#define _DELIVERSTATUSDO_H_

#include "../DoInclude.h"

/**
 * ���ۺ�ͬ������Ϣ���ݿ�ʵ����
 */

class DeliverStatusDO
{
	// ��ͬID
	CC_SYNTHESIZE(int, contract_id, ContractID);
	// ����״̬
	CC_SYNTHESIZE(int, deliver_status, DeliverStatus);
public:
	DeliverStatusDO()
	{
		contract_id = 1;
		deliver_status = 1;
	}
};

#endif // !_DELIVERSTATUSDO_H_