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
#include "stdafx.h"
#include "SalContractService.h"

bool SalContractService::modifySalContractBasicInfo(const ModifySalContractBasicInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO对象
	SalContractBasicInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		ContractID, contract_id,
		/*ContractNO, contract_no,*/
		Title, title,
		CustomerID, customer_id,
		LinkmanID, linkman_id,
		StartDate, start_date,
		EndDate, end_date,
		Money, money,
		Intro, intro,
		OurUserID, our_user_id
		);
	/*data.setUpdater(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format());*/
	// TODO: 调用dao操作数据库
	SalContractDAO dao;
	return dao.modifySalContractBasicInfo(data);
}

bool SalContractService::modifyDeliverStatus(const ModifyDeliverStatusDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO对象
	DeliverStatusDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		ContractID, contract_id,
		DeliverStatus, deliver_status
	);
	/*data.setUpdater(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format());*/
	// TODO: 调用dao操作数据库
	SalContractDAO dao;
	return dao.modifyDeliverStatus(data);
}







