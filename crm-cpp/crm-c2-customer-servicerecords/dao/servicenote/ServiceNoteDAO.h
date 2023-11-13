#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huipaodeyu
 @Date: 2023/10/25 10:36:07

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
#ifndef _SERVICENOTE_DAO_
#define _SERVICENOTE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/service/ServiceDO.h"
#include "../../domain/query/service/ServiceQuery.h"
/**
 * �����¼�����ݿ����ʵ��
 */
class ServiceNoteDAO : public BaseDAO
{
public:

	// ͳ����������
	uint64_t count(const ServiceQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ServiceDO> selectWithPage(const ServiceQuery::Wrapper& query);
	// ͨ�����Ʋ�ѯ����
	//list<ServiceDO> selectByName(const string& name);
};
#endif // !_SERVICENOTE_DAO_