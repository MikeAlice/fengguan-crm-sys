#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/25
 @FileName: ExportCapitalRecordService
 @version: 1.0

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
#ifndef _EXPORT_CAPITAL_RECORD_SERVICE_
#define _EXPORT_CAPITAL_RECORD_SERVICE_
#include "domain/query/fincapitalrecord/ExportCapitalRecordQuery.h"
#include "domain/do/fincapitalrecord/CapitalRecordDO.h"
#include "domain/dto/fincapitalrecord/ExportCapitalRecordDTO.h"

class ExportCapitalRecordService
{
public:
	// 导出数据			负责人：超能
	std::string exportData(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto);
	// 获取excel文件名	负责人：超能
	std::string getExcelFileName();
};

#endif