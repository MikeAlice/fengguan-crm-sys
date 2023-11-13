#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _TRACE_DAO_
#define _TRACE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/trace/AllDO.h"
#include "../../domain/query/gettrace/TraceQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class TraceDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TraceQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<AllDO> selectWithPage(const TraceQuery::Wrapper& query);
	// ͨ���ͻ����Ʋ�ѯ����
	list<AllDO> selectByName(const string& CusId);
	// ��������
	uint64_t insert(const AllDO& iObj);
	// �޸�����
	int update(const AllDO& uObj);

	int deleteById(uint64_t trace_id);
	list<TraceDO> seletctAll();
};
#endif // !_Trace_DAO_
