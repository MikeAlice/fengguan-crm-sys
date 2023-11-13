#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 12:05:22

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
#ifndef _QUERYRECEIPTRECORDQUERY_H_
#define _QUERYRECEIPTRECORDQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询收票记录
 */
class QueryInvoiceReceiveQuery : public PageQuery
{
	DTO_INIT(QueryInvoiceReceiveQuery, PageQuery);
	//收票日期、创建日期、合同标题、供应商名称、金额
	API_DTO_FIELD_DEFAULT(String, rece_date, ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date"));
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("fin_invoice_rece.field.create_time"));
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name"));
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name"));
	API_DTO_FIELD_DEFAULT(UInt64, money, ZH_WORDS_GETTER("fin_invoice_rece.field.money"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_QUERYRECEIPTRECORDQUERY_H_