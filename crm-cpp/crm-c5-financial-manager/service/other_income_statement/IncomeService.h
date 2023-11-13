#pragma once
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
#ifndef _INCOME_SERVICE_
#define _INCOME_SERVICE_
#include <list>
#include "domain/vo/other_income_statement/IncomePageJsonVO.h"
#include "domain/query/other_income_statement/IncomeQuery.h"
#include "domain/dto/other_income_statement/IncomeDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class IncomeService
{
public:
	// ��ҳ��ѯ��������
	IncomePageDTO::Wrapper listAll(const IncomePageQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const IncomeDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const IncomeDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_INCOME_SERVICE_