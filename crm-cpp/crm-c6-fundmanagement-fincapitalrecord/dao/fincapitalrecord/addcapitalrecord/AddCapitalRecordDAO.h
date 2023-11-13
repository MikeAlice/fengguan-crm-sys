#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/23
 @FileName: AddCapitalRecordDAO
 @version: 1.0

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
#ifndef _ADD_CAPITAL_RECORD_DAO_
#define _ADD_CAPITAL_RECORD_DAO_
#include "BaseDAO.h"
#include "domain/do/fincapitalrecord/AddCapitalRecordDO.h"
#include "domain/query/fincapitalrecord/CapitalRecordPageQuery.h"

/**
 * fin_capital_record ���ݿ����ʵ��
 */
class AddCapitalRecordDAO : public BaseDAO
{
public:
	// ��������	�����ˣ�����
	uint64_t insert(const AddCapitalRecordDO& Obj);
};
#endif