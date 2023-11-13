#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 15:04:19

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
#ifndef _QUERYINVOICERECEIVESERVICE_H_
#define _QUERYINVOICERECEIVESERVICE_H_

#include "domain/dto/query-invoice-receive/FinInvoiceReceivePageDTO.h"
#include "domain/query/query-invoice-receive/QueryInvoiceReceiveQuery.h"
#include "dao/query-invoice-receive/QueryInvoiceReceiveDAO.h"
#include "domain/do/query-invoice-receive/FinInvoiceReceiveDO.h"

class QueryInvoiceReceiveService
{
public:
	// ��ҳ��ѯ
	FinInvoiceReceivePageDTO::Wrapper listAll(const QueryInvoiceReceiveQuery::Wrapper& query)
	{
		// �������ض���
		auto pages = FinInvoiceReceivePageDTO::createShared();
		pages->pageIndex = query->pageIndex;
		pages->pageSize = query->pageSize;

		// ��ѯ����������
		QueryInvoiceReceiveDAO dao;
		uint64_t count = dao.count(query);
		if (count <= 0)
		{
			return pages;
		}

		// ��ҳ��ѯ����
		pages->total = count;
		pages->calcPages();
		list<FinInvoiceReceiveDO> result = dao.selectWithPage(query);
		// DO��DTO��PageDTO
		for (FinInvoiceReceiveDO sub : result)
		{
			auto dto = FinInvoiceReceiveDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, RecordId, supplier_name, SupplierName, contract_name, ContractName, name, Name, invoice_no, InvoiceNo, money, Money, rece_date, ReceDate, stages, Stages, create_user, CreateUser, intro, Intro)
			pages->addData(dto);

		}
		return pages;
	}
};

#endif // !_QUERYINVOICERECEIVESERVICE_H_