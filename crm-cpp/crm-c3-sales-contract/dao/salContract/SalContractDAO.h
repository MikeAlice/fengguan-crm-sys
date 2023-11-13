#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
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
 * ���ۺ�ͬDAOʵ��
 */
class SalContractDAO : public BaseDAO
{
public:
	/**
	 * ���ۺ�ͬ - �޸����ۺ�ͬ������ϢDAOʵ��
	 * ���ܣ�ָ�����ۺ�ͬΨһ��ʶ�޸����ۺ�ͬ������Ϣ����
	 */
	bool modifySalContractBasicInfo(const SalContractBasicInfoDO& data);
	/**
	 * ���ۺ�ͬ - �޸Ľ���״̬DAOʵ��
	 * ���ܣ�ָ�����ۺ�ͬΨһ��ʶ�޸Ľ���״̬����
	 */
	bool modifyDeliverStatus(const DeliverStatusDO& data);
};

#endif // !_SALCONTRACTDAO_H_