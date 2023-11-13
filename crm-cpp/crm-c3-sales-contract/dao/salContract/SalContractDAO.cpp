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
#include "SalContractDAO.h"
#include "SalContractBasicInfoMapper.h"
#include "DeliverStatusMapper.h"

/**
 * 销售合同基础信息修改条件匹配宏
 */
#define UPDATE_TERAM_PARSE(__DO__, __SQL__) \
SqlParams params; \
if (__DO__.getTitle() != "") { \
	__SQL__ << " `title`=?,"; \
	SQLPARAMS_PUSH(params, "s", string, __DO__.getTitle()); \
} \
if (__DO__.getCustomerID() != -1) { \
	__SQL__ << " `customer_id`=?,"; \
	SQLPARAMS_PUSH(params, "i", int, __DO__.getCustomerID()); \
} \
if (__DO__.getLinkmanID() != -1) { \
	__SQL__ << " `linkman_id`=?,"; \
	SQLPARAMS_PUSH(params, "i", int, __DO__.getLinkmanID()); \
} \
if (__DO__.getStartDate() != "") { \
	__SQL__ << " `start_date`=?,"; \
	SQLPARAMS_PUSH(params, "s", string, __DO__.getStartDate()); \
} \
if (__DO__.getEndDate() != "") { \
	__SQL__ << " `end_date`=?,"; \
	SQLPARAMS_PUSH(params, "s", string, __DO__.getEndDate()); \
} \
if (__DO__.getMoney() != -1) { \
	__SQL__ << " `money`=?,"; \
	SQLPARAMS_PUSH(params, "d", double, __DO__.getMoney()); \
} \
if (__DO__.getIntro() != "") { \
	__SQL__ << " `intro`=?,"; \
	SQLPARAMS_PUSH(params, "s", string, __DO__.getIntro()); \
} \
if (__DO__.getOurUserID() != -1) { \
	__SQL__ << " `our_user_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, __DO__.getOurUserID()); \
} 
 /**
  * 销售合同交付状态修改条件匹配宏
  */
#define UPDATE_TERAM_PARSE2(__DO__, __SQL__) \
SqlParams params; \
if (__DO__.getDeliverStatus() != 0) { \
	__SQL__ << " `deliver_status`=?"; \
	SQLPARAMS_PUSH(params, "i", int, __DO__.getDeliverStatus()); \
} 
bool SalContractDAO::modifySalContractBasicInfo(const SalContractBasicInfoDO& data)
{
	stringstream ss;
	ss << "UPDATE `sal_contract` SET ";
	UPDATE_TERAM_PARSE(data, ss);
	ss << " WHERE `contract_id`=? ";
	SQLPARAMS_PUSH(params, "i", int, data.getContractID());

	string sql = ss.str();
	return sqlSession->executeUpdate(sql, params);
}

bool SalContractDAO::modifyDeliverStatus(const DeliverStatusDO& data)
{
	stringstream ss;
	ss << "UPDATE `sal_contract` SET ";
	UPDATE_TERAM_PARSE2(data, ss);
	ss << " WHERE `contract_id`=? ";
	SQLPARAMS_PUSH(params, "i", int, data.getContractID());

	string sql = ss.str();
	return sqlSession->executeUpdate(sql, params);
}
