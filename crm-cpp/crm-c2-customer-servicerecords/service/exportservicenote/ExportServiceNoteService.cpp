#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huipaodeyu
 @Date: 2023/10/25 10:36:07

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
#include "ExportServiceNoteService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include <cstdio>
#include<string>

list<ServiceDetailDTO::Wrapper> ExportServiceNoteService::listAll(const ExportServiceNoteQuery::Wrapper& query)
{
	// �������ض���,���ط����¼��Ϣ
	auto data = list<ServiceDetailDTO::Wrapper>();

	ExportServiceNoteDAO dao;

	list<ServiceDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (ServiceDO sub : result)
	{
		auto dto = ServiceDetailDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, customer_name, Customer_name,services,Services, servicesmodel, Servicesmodel, service_time, Service_time, tlen, Tlen, content, Content);

		data.push_back(dto);
	}
	return data;

}

String ExportServiceNoteService::uploadExportFile(list<ServiceDetailDTO::Wrapper>& dtolist)
{
	// ת���ͻ���Ϣ��ʽΪ��ά����
	vector<vector<std::string>> data;
	//stringstream ss;
	//string services1[4] = { "Ͷ��","��ѵ","����","ά��"};
	//string servicesmodel[4] = { "�绰","	QQ","�ֳ�","����" };
	for (auto dto : dtolist)
	{
		vector<std::string> row;
		
		row.push_back(dto->customer_name);
		row.push_back(to_string(dto->services.getValue(0)));
		row.push_back(to_string(dto->servicesmodel.getValue(0)));
		row.push_back(dto->service_time);
		row.push_back(dto->tlen);
		row.push_back(dto->content);

		data.push_back(row);
	}

	data.insert(data.begin(), {
	ZH_WORDS_GETTER("xlnt.field.customer_name"),
	ZH_WORDS_GETTER("xlnt.field.services"),
	ZH_WORDS_GETTER("xlnt.field.servicesmodel"),
	ZH_WORDS_GETTER("xlnt.field.service_time"),
	ZH_WORDS_GETTER("xlnt.field.tlen"),
	ZH_WORDS_GETTER("xlnt.field.content"),
		});

	//�����ļ�����ҳ����
	time_t mytime = time(NULL);
	stringstream ss;
	ss << mytime;
	string fileName = "./public/excel/" + ss.str() + ".xlsx";
	//string sheetName = CharsetConvertHepler::ansiToUtf8("�����¼��Ϣ_" + ss.str());
	string sheetName = "Sheet1";
	//cout << fileName << endl;
	// ����ͻ���Ϣ��Excel�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	string fieldName = client.uploadFile(fileName);
	//cout << fieldName << endl;
	// ��������·��
	string downloadUrl = urlPrefix + fieldName;
	// �������·��
	//std::cout << "download url: " << downloadUrl << std::endl;
	int count = 0;
	while (remove(fileName.c_str()) != 0 && count++ < 3);

	return downloadUrl;
}
