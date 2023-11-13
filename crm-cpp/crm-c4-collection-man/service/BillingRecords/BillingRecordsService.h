#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _BillingRecordsService_
#define _BillingRecordsService_
#include <list>
#include"domain/do/BillingRecords/BillingRecordsDO.h"

#include "stdafx.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "controller/BillingRecords/BillingRecordsController.h"
#include <ErrorHandler.h>
#include <oatpp-websocket/Handshaker.hpp>
#include"service/BillingRecords/BillingRecordsService.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class BillingRecordsService
{
public:
	// ͨ��IDɾ������
	bool removeData(uint64_t id);

	// ����id�����б����������
	void writeVectorToFile(const oatpp::List<oatpp::UInt64>& dto);
	
};

#endif // 

