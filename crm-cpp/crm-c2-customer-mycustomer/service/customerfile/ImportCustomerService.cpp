/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#include "ImportCustomerService.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "domain/dto/customerfile/ExportCustomerDTO.h"
#include <CharsetConvertHepler.h>
#include "dao/customerfile/ImportCustomerDAO.h"
#include "NacosClient.h"

String ImportCustomerService::uploadImportFile(std::shared_ptr<oatpp::web::protocol::http::incoming::Request>& request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// �����ļ���
	time_t mytime = time(NULL);
	stringstream ss;
	ss << mytime;
	// ���ڷ���ȫ·�������\/���������صؽ�ȡ������Ϊ�����ļ���
	string returnName = ss.str() + ".xlsx";
	string fileName = "./public/static/" + ss.str() + ".xlsx";

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_FILE(reader, "file", fileName);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	/* �����ļ��Ƿ��ȡ�� */
	OATPP_ASSERT_HTTP(partfile, Status::CODE_400, "file is null");

	// ��ȡԭ�ļ���
	string filename = partfile->getFilename().getValue("");
	//cout << filename << endl;
	
	// ��ȡԭ�ļ�������λ�ַ�
	string suffix = filename.substr(filename.size() - 5, filename.size() - 1);
	//cout << suffix << endl;
	
	// �ж��ļ���ʽ�Ƿ���ȷ
	if (suffix.compare(".xlsx") != 0) 
	{
		remove(fileName.c_str());
		return "format error";
	}
	/* ��ӡ�ļ�����·�� */
	OATPP_LOGD("Multipart", "file save path: %s", partfile->getPayload()->getLocation()->c_str());

	return returnName;
}

ImportResultDTO::Wrapper ImportCustomerService::importCustomer(String& fileName)
{
	// ������������
	vector<vector<std::string>> data;
	// ���浽�ļ�
	ExcelComponent excel;
	// ����ҳǩ��ΪĬ�ϵ�һҳ
	string sheetName = "Sheet1";
	fileName = "./public/static/" + fileName;
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);

	int count = 0;
	while (remove(fileName.getValue("").c_str()) != 0 && count++ < 3);

	auto dtolist = list<ExportCustomerDTO::Wrapper>();

	// ���ļ��ж�ȡ�����ݱ��浽DTO��
	for(int i = 1; i < readData.size(); i++)
	{
		auto row = readData[i];
		auto dto = ExportCustomerDTO::createShared();

		dto->name = row[0];
		dto->create_user_name = row[1];
		dto->owner_user_name = row[2];
		dto->create_time = row[3];
		dto->next_time = row[4];
		dto->conn_time = row[5];
		dto->conn_body = row[6];

		dtolist.push_back(dto);
	}
	// ͨ��������ѯ������Ա�������Ա��ID
	ImportCustomerDAO dao;
	for (auto dto : dtolist) 
	{
		dto->create_user_id = dao.selectUserIdByName(dto->create_user_name);
		dto->owner_user_id = dao.selectUserIdByName(dto->owner_user_name);
	}

	Int32 success_count = 0;
	Int32 fail_count = 0;
	// ��DTOת����DO�������뵽���ݿ���
	for (auto dto : dtolist)
	{
		auto customer_do = CustomerDO();

		ZO_STAR_DOMAIN_DTO_TO_DO(customer_do, dto, Name, name, Create_User_Id, create_user_id, \
			Create_User_Name, create_user_name, Owner_User_Id, owner_user_id, Owner_User_Name, owner_user_name, \
			Create_Time, create_time, Next_Time, next_time, Conn_Time, conn_time, Conn_Body, conn_body);
			
		if (dao.insert(customer_do) != 0) 
		{
			success_count = success_count + 1;
		}
		else 
		{
			fail_count = fail_count + 1;
		}
	}

	auto res_dto = ImportResultDTO::createShared();
	res_dto->success_count = success_count;
	res_dto->fail_count = fail_count;

	return res_dto;
}
