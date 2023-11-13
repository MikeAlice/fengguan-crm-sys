#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/27 18:17:43

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
#ifndef _EXPORTPAYRECORDDAO_H_
#define _EXPORTPAYRECORDDAO_H_

#include "BaseDAO.h"
#include "domain/do/export-pay-record/ExportPayRecordDO.h"
#include "domain/dto/export-pay-record/ExportPayRecordDTO.h"
//#include "domain/query/pay-record/ExportPayRecordQuery.h"

/**
 * 批量导出付款记录：id list
 */
class ExportPayRecordDAO : public BaseDAO
{
public:
	list<ExportPayRecordDO> selectByID(const oatpp::List<ExportPayRecordDTO::Wrapper>& dto);
};

#endif // !_EXPORTPAYRECORDDAO_H_
//class ExportPayRecordDao
//{
//};
//
