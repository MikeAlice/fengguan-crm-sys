#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/29 13:44:48

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
#ifndef _FININVOICERECEIVEPAGEJSONVO_H_
#define _FININVOICERECEIVEPAGEJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/query-invoice-receive/FinInvoiceReceivePageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class FinInvoiceReceivePageJsonVO : public JsonVO<FinInvoiceReceivePageDTO::Wrapper>
{
	DTO_INIT(FinInvoiceReceivePageJsonVO, JsonVO<FinInvoiceReceivePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_FININVOICERECEIVEPAGEJSONVO_H_