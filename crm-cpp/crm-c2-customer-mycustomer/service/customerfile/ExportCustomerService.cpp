/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#include "ExportCustomerService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include <cstdio>
#include "FastDfsClient.h"
#include "NacosClient.h"


list<ExportCustomerDTO::Wrapper> ExportCustomerService::listAll(const ExportCustomerQuery::Wrapper& query)
{
	// �������ض���,���ؿͻ���Ϣ
	auto data = list<ExportCustomerDTO::Wrapper>();

	ExportCustomerDAO dao;

	list<CustomerDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (CustomerDO sub : result)
	{
		auto dto = ExportCustomerDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, create_user_id, Create_User_Id, \
			create_user_name, Create_User_Name, owner_user_id, Owner_User_Id, owner_user_name, Owner_User_Name, \
			create_time, Create_Time, next_time, Next_Time, conn_time, Conn_Time, conn_body, Conn_Body);
		
		data.push_back(dto);
	}
	return data;

}

String ExportCustomerService::uploadExportFile(list<ExportCustomerDTO::Wrapper>& dtolist)
{
	// ת���ͻ���Ϣ��ʽΪ��ά����
	vector<vector<std::string>> data;
	//stringstream ss;
	for (auto dto : dtolist)
	{
		vector<std::string> row;

		row.push_back(dto->name);
		row.push_back(dto->create_user_name);
		row.push_back(dto->owner_user_name);
		row.push_back(dto->create_time);
		row.push_back(dto->next_time);
		row.push_back(dto->conn_time);
		row.push_back(dto->conn_body);
		
		data.push_back(row);
	}
	
	data.insert(data.begin(), {
	ZH_WORDS_GETTER("customer.field.name") ,
	ZH_WORDS_GETTER("customer.field.create_user_name") ,
	ZH_WORDS_GETTER("customer.field.owner_user_name") ,
	ZH_WORDS_GETTER("customer.field.create_time") ,
	ZH_WORDS_GETTER("customer.field.next_time") ,
	ZH_WORDS_GETTER("customer.field.conn_time") ,
	ZH_WORDS_GETTER("customer.field.conn_body") ,
		});

	//�����ļ�����ҳ����
	time_t mytime = time(NULL);
	stringstream ss;
	ss << mytime;
	string fileName = "./public/excel/" + ss.str() + ".xlsx";
	//string sheetName = CharsetConvertHepler::ansiToUtf8("�ͻ���Ϣ_" + ss.str());
	string sheetName = "Sheet1";
	//cout << fileName << endl;
	// ����ͻ���Ϣ��Excel�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	string fieldName = client.uploadFile(fileName);
	if (fieldName == "") {
		return "upload fail";
	}
	//cout << fieldName << endl;
	// ��������·��
	string downloadUrl = urlPrefix + fieldName;
	// �������·��
	//std::cout << "download url: " << downloadUrl << std::endl;
	int count = 0;
	while (remove(fileName.c_str()) != 0 && count++ < 3);

	return downloadUrl;
}