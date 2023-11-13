/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/10/19 20:34:51

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
#include "stdafx.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "BillingRecordsController.h"
#include <ErrorHandler.h>
#include <oatpp-websocket/Handshaker.hpp>
#include"service/BillingRecords/BillingRecordsService.h"

#include "Macros.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include <vector>

Uint64JsonVO::Wrapper BillingRecordsController::execDelBillingRecords(const oatpp::List<oatpp::UInt64>& dto)
{
	//���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	//��������------------------------------------------------------------
	if (dto->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto i = dto->begin(); i != dto->end(); i++)
	{
		if (i->getValue(0) <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//�����������------------------------------------------------------


	// ����һ��Service
	BillingRecordsService service;
	//ִ������ɾ��

	for (auto i = dto->begin(); i != dto->end(); i++)
	{
		if (service.removeData((*i).getValue(0))) {
			jvo->success((*i));
		}
		else
		{
			jvo->fail((*i));
		}
	}

	// ��Ӧ���
	
	return jvo;
}

/*
StringJsonVO::Wrapper BillingRecordsController::execExportBillingRecords(const oatpp::List<oatpp::UInt64>& dto)
{
	auto jvo = StringJsonVO::createShared();

	//��������------------------------------------------------------------
	if (dto->empty())
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto i = dto->begin(); i != dto->end(); i++)
	{
		if (i->getValue(0) <= 0)
		{
			jvo->init(String("-1"), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//�����������------------------------------------------------------
	
	BillingRecordsService service;

	string downloadUrl = service.exportBillingRecords(dto);

	jvo->success(downloadUrl);

	return jvo;
}
*/

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> BillingRecordsController::execExportBillingRecords(const oatpp::List<oatpp::UInt64>& dto)
{
	BillingRecordsService service;

	service.writeVectorToFile(dto);

	string fullPath = "./public/excel/ExportBillingRecords.xlsx";
	
	string fileName = "ExportBillingRecords.xlsx";
	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + fileName);

	// Ӱ��ɹ����
	return response;
}
