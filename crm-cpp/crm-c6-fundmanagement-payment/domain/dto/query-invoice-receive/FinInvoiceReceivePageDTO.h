#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 14:13:09

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
#ifndef _FININVOICERECEIVEPAGEDTO_H_
#define _FININVOICERECEIVEPAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*DTO响应对象*/

class FinInvoiceReceiveDTO : public oatpp::DTO
{
	//收票记录ID	供应商名称	合同标题	发票内容/编号/金额	收票时间	期次	创建人	备注
	DTO_INIT(FinInvoiceReceiveDTO, DTO);
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("fin_invoice_rece.field.record_id"));
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name"));
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("fin_invoice_rece.field.name"));
	API_DTO_FIELD_DEFAULT(UInt64, invoice_no, ZH_WORDS_GETTER("fin_invoice_rece.field.invoice_no"));
	API_DTO_FIELD_DEFAULT(UInt64, money, ZH_WORDS_GETTER("fin_invoice_rece.field.money"));
	API_DTO_FIELD_DEFAULT(String, rece_date, ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date"));
	API_DTO_FIELD_DEFAULT(UInt64, stages, ZH_WORDS_GETTER("fin_invoice_rece.field.stages"));
	API_DTO_FIELD_DEFAULT(String, create_user, ZH_WORDS_GETTER("fin_invoice_rece.field.create_user"));
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("fin_invoice_rece.field.intro"));

};

class FinInvoiceReceivePageDTO : public PageDTO<FinInvoiceReceiveDTO::Wrapper>
{
	DTO_INIT(FinInvoiceReceivePageDTO, PageDTO<FinInvoiceReceiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FININVOICERECEIVEPAGEDTO_H_