#pragma once
/*
 @Author: linglan
 @Date: 2023/10/26 20:21:26

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
#ifndef _RECEIPTRECORDJSONVO_H_
#define _RECEIPTRECORDJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/remove_receipt_record/ReceiptRecordDTO.h"
#include "oatpp/codegen/dto/base_define.hpp"

//删除收票记录（可批量） 负责人：灵岚
class ReceiptRecordJsonVO : public JsonVO<ReceiptRecordDTO::Wrapper>
{
public:
	DTO_INIT(ReceiptRecordJsonVO, JsonVO<ReceiptRecordDTO::Wrapper>);
};

#endif // !_RECEIPTRECORDJSONVO_H_