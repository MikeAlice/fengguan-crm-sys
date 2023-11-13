#pragma once
/*
 @Author: linglan
 @Date: 2023/10/26 20:23:34

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
#ifndef _RECEIPTRECORDDTO_H_
#define _RECEIPTRECORDDTO_H_

#include "../../GlobalInclude.h"
#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

//删除收票记录（可批量） 负责人：灵岚
class ReceiptRecordDTO : public oatpp::DTO
{
public:
	DTO_INIT(ReceiptRecordDTO, DTO);

	// 收票记录编号
	API_DTO_FIELD_DEFAULT(List<UInt64>, record_id, ZH_WORDS_GETTER("receiptRecord.field.record_id"));

public:
	ReceiptRecordDTO() {
		this->record_id = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RECEIPTRECORDDTO_H_