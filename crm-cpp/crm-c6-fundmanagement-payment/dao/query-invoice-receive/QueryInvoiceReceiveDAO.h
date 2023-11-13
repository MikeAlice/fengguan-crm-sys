#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 15:12:48

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
#ifndef _QUERYINVOICERECEIVEDAO_H_
#define _QUERYINVOICERECEIVEDAO_H_

#include "BaseDAO.h"
#include "domain/query/query-invoice-receive/QueryInvoiceReceiveQuery.h"
#include "domain/do/query-invoice-receive/FinInvoiceReceiveDO.h"

class QueryInvoiceReceiveDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const QueryInvoiceReceiveQuery::Wrapper& query);
	// 分页查询数据
	list<FinInvoiceReceiveDO> selectWithPage(const QueryInvoiceReceiveQuery::Wrapper& query);
};

#endif // !_QUERYINVOICERECEIVEDAO_H_