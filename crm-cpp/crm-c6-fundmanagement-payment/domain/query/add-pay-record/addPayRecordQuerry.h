#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _ADD_PAY_RECORD_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class AddPayRecordQuerry : public oatpp::DTO
{
	DTO_INIT(AddPayRecordQuerry,DTO);
	// ��ͬ
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("addPayRecord.field.contract_id");
	}
	// ��Ӧ��
	DTO_FIELD(UInt64, supplier_id);
	DTO_FIELD_INFO(supplier_id) {
		info->description = ZH_WORDS_GETTER("addPayRecord.field.supplier_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_