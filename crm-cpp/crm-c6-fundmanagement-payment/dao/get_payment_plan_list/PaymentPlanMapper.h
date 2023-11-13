#pragma once
/*
 @Author: linglan
 @Date: 2023/10/24 19:00:28

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
#ifndef _PAYMENTPLANMAPPER_H_
#define _PAYMENTPLANMAPPER_H_

#include "Mapper.h"
#include "domain/do/payment_plan/PaymentPlanDO.h"

//查询付款计划信息(分页) 负责人：灵岚
class PaymentPlanMapper : public Mapper<PaymentPlanDO>
{
public:
	PaymentPlanDO mapper(ResultSet* resultSet) const override
	{
		PaymentPlanDO data;
		// 映射编号
		data.setPlan_id(resultSet->getUInt64(1));
		// 映射采购订单号
		data.setContract_id(resultSet->getUInt64(2));
		// 映射采购合同名称
		data.setContract_name(resultSet->getString(3));
		// 映射供应商号
		data.setSupplier_id(resultSet->getUInt64(4));
		// 映射供应商名称
		data.setSupplier_name(resultSet->getString(5));
		// 映射关联银行帐号
		data.setBank_id(resultSet->getUInt64(6));
		// 映射金额
		data.setMoney(resultSet->getUInt64(7));
		// 映射计划付款日期
		data.setPlan_date(resultSet->getString(8));
		// 映射期次
		data.setStages(resultSet->getUInt64(9));
		// 映射是否付款
		data.setIfpay(resultSet->getString(10));
		// 映射备注
		data.setIntro(resultSet->getString(11));
		// 映射创建人id
		data.setCreate_user_id(resultSet->getUInt64(12));
		// 映射创建时间
		data.setCreate_time(resultSet->getString(13));

		return data;
	}

};

#endif // !_PAYMENTPLANMAPPER_H_
