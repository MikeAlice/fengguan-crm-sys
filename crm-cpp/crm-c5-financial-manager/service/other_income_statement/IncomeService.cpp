
/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/23 14:02:23

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
#include "IncomeService.h"
#include "../../dao/other_income_statement/IncomeDAO.h"



IncomePageDTO::Wrapper IncomeService::listAll(const IncomePageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = IncomePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	IncomeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<IncomeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (IncomeDO sub : result)
	{
		auto dto = IncomeDTO::createShared();
		dto->record_id = sub.getRecordId();
		dto->type_id = sub.getTypeId();
		dto->bank_id = sub.getBankId();
		dto->money = sub.getMoney();
		dto->intro = sub.getIntro();
		dto->happen_date = sub.getHappenDate();
		dto->create_user_id = sub.getCreateUserId();
		dto->create_time = sub.getCreateTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, RecordId, type_id, TypeId, bank_id, BankId, money, Money, intro, Intro, happen_date, HappenDate, create_user_id, CreateUserId, create_time, CreateTime);
		pages->addData(dto);

	}
	return pages;
}

uint64_t IncomeService::saveData(const IncomeDTO::Wrapper& dto)
{
	// 组装DO数据
	IncomeDO data;
	data.setRecordId(dto->record_id.getValue(0));
	data.setTypeId(dto->type_id.getValue(0));
	data.setBankId(dto->bank_id.getValue(0));
	data.setMoney(dto->money.getValue(0));
	data.setIntro(dto->intro.getValue(""));
	data.setHappenDate(dto->happen_date.getValue(""));
	data.setCreateUserId(dto->create_user_id.getValue(0));
	data.setCreateTime(dto->create_time.getValue(""));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RecordId, record_id, TypeId, type_id, BankId, bank_id, Money, money, Intro, intro, HappenDate, happen_date, CreateUserId, create_user_id, CreateTime, create_time);
		// 执行数据添加
	IncomeDAO dao;
	return dao.insert(data);
}

bool IncomeService::updateData(const IncomeDTO::Wrapper& dto)
{
	// 组装DO数据
	IncomeDO data;
	data.setRecordId(dto->record_id.getValue(0));
	data.setTypeId(dto->type_id.getValue(0));
	data.setBankId(dto->bank_id.getValue(0));
	data.setMoney(dto->money.getValue(0));
	data.setIntro(dto->intro.getValue(""));
	data.setHappenDate(dto->happen_date.getValue(""));
	data.setCreateUserId(dto->create_user_id.getValue(0));
	data.setCreateTime(dto->create_time.getValue(""));

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RecordId, record_id, TypeId, type_id, BankId, bank_id, Money, money, Intro, intro, HappenDate, happen_date, CreateUserId, create_user_id, CreateTime, create_time);
		// 执行数据修改
	IncomeDAO dao;
	return dao.update(data) == 1;
}

bool IncomeService::removeData(uint64_t id)
{
	IncomeDAO dao;
	return dao.deleteById(id) == 1;
}
