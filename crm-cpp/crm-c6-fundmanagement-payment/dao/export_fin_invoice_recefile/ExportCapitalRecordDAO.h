#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/25
 @FileName: ExportCapitalRecordDAO
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
#ifndef _EXPORT_CAPITAL_RECORD_DAO_
#define _EXPORT_CAPITAL_RECORD_DAO_
#include "BaseDAO.h"
#include "domain/do/fin_invoice_rece/FinCapitalRecordDO.h"
#include "domain/query/export_fin_invoice_recefile/ExportCapitalRecordQuery.h"
#include "dao/export_fin_invoice_recefile/ExportCapitalRecordMapper.h"
#include "domain/dto/fin_invoice_rece/ExportCapitalRecordDTO.h"

class ExportCapitalRecordDAO : public BaseDAO
{
public:
	list<FinCapitalRecordDO> selectAll(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto);
	list<FinCapitalRecordDO> selectWithIdList(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto);
};

#endif