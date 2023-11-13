/*
 @Author: linglan
 @Date: 2022/10/25 11:13:11

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
#include "PaymentPlanService.h"
#include "domain/do/payment_plan/PaymentPlanDO.h"
#include "dao/get_payment_plan_list/PaymentPlanDAO.h"

PaymentPlanPageDTO::Wrapper PaymentPlanService::listAll(const PaymentPlanQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PaymentPlanPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PaymentPlanDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PaymentPlanDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PaymentPlanDO sub : result)
	{
		auto dto = PaymentPlanDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			plan_id, Plan_id, contract_id, Contract_id, contract_name, Contract_name, supplier_id, Supplier_id,
			supplier_name, Supplier_name, bank_id, Bank_id, money, Money,
			plan_date, Plan_date, stages, Stages, ifpay, Ifpay,
			intro, Intro, create_user_id, Create_user_id, create_time, Create_time)

		pages->addData(dto);

	}
	return pages;
}

