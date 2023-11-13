#pragma once
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
#ifndef _INCOME_DAO_
#define _INCOME_DAO_
#include "BaseDAO.h"
#include "../../domain/do/other_income_statement/IncomeDO.h"
#include "../../domain/query/other_income_statement/IncomeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class IncomeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const IncomePageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<IncomeDO> selectWithPage(const IncomePageQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<IncomeDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const IncomeDO& iObj);
	// �޸�����
	int update(const IncomeDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_INCOME_DAO_
