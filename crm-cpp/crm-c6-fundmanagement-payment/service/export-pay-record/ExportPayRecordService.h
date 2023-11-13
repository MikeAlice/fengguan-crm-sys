#pragma once
/*


 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/27 17:52:58

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
#ifndef _EXPORTPAYRECORDSERVICE_H_
#define _EXPORTPAYRECORDSERVICE_H_


#include "domain/dto/export-pay-record/ExportPayRecordDTO.h"

class ExportPayRecordService
{
public:
	std::string exportPayRecord(const oatpp::List<ExportPayRecordDTO::Wrapper>& dto);
};

#endif // !_EXPORTPAYRECORDSERVICE_H_
//class ExportPayRecordService
//{
//};

