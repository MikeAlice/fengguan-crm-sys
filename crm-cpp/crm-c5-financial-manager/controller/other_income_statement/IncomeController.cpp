/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/24 11:52:21

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
#include "IncomeController.h"
#include "../../service/other_income_statement/IncomeService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper IncomeController::execInsertIncome(const IncomeDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->record_id|| !dto->type_id || !dto->bank_id || !dto->money || !dto->intro || !dto->happen_date || !dto->create_user_id || !dto->bank_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->money < 0 || dto->intro->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	IncomeService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

IncomePageJsonVO::Wrapper IncomeController::execQueryIncome(const IncomePageQuery::Wrapper& query, const PayloadDTO& payload)
{ 
	// ����һ��Service
	IncomeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = IncomePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


Uint64JsonVO::Wrapper IncomeController::execModifyIncome(const IncomeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->money < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	IncomeService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper IncomeController::execRemoveIncome(const UInt64& record_id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!record_id || record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	IncomeService service;
	// ִ������ɾ��
	if (service.removeData(record_id.getValue(0))) {
		jvo->success(record_id);
	}
	else
	{
		jvo->fail(record_id);
	}
	// ��Ӧ���
	return jvo;
}





