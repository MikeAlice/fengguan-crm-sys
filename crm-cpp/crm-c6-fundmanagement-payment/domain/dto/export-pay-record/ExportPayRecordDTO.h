#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/28 14:41:03

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
#ifndef _EXPORTPAYRECORDDTO_H_
#define _EXPORTPAYRECORDDTO_H_

#include "../../GlobalInclude.h"
//#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

//根据id导出付款记录
class ExportPayRecordDTO : public oatpp::DTO
{
	DTO_INIT(ExportPayRecordDTO, DTO);
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("fin_pay_record.field.record_id"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTPAYRECORDDTO_H_