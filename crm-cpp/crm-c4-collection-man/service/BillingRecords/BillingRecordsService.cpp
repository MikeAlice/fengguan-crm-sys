#include "stdafx.h"
#include"service/BillingRecords/BillingRecordsService.h"
#include"dao/BillingRecords/BillingRecordsDAO.h"
//#include"Macros.h"
#include "Macros.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include <vector>

bool BillingRecordsService::removeData(uint64_t id)
{
	BillingRecordsDAO dao;
	return dao.deleteById(id) == 1;
}

void BillingRecordsService::writeVectorToFile(const oatpp::List<oatpp::UInt64>& dto)
{
	BillingRecordsDAO dao;
	auto list = dao.selectbyID(dto);
	//��װ����--------------------------------------------
	std::vector<std::vector<std::string>> data;
	for (auto& record : list) {
		vector<std::string> row;
		row.push_back((record.getCustomer_name()));
		row.push_back(std::to_string(record.getContract_id()));
		row.push_back(std::to_string(record.getMoney()));
		row.push_back((record.getInvoice_no()));
		row.push_back(record.getPay_date());
		row.push_back(std::to_string(record.getStages()));
		row.push_back(record.getName());
		row.push_back(record.getIntro());
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	// ע�⣺�ļ������ƺ��ļ�·�����ܳ�������
	std::string fileName = "./public/excel/ExportBillingRecords.xlsx";
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("��Ʊ�б�");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// ���Ը��ǵ�һ��ҳǩ
	sheetName = CharsetConvertHepler::ansiToUtf8("��Ʊ�б�");
	data.insert(data.begin(), {
		CharsetConvertHepler::ansiToUtf8("�ͻ�����") ,
		CharsetConvertHepler::ansiToUtf8("��ͬ����") ,
		CharsetConvertHepler::ansiToUtf8("��Ʊ���") ,
		CharsetConvertHepler::ansiToUtf8("��Ʊ���") ,
		CharsetConvertHepler::ansiToUtf8("��Ʊʱ��") ,
		CharsetConvertHepler::ansiToUtf8("�ڴ�") ,
		CharsetConvertHepler::ansiToUtf8("������") ,
		CharsetConvertHepler::ansiToUtf8("��ע") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);

	/*
	// ����ʹ��FastDFS
	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;

	return downloadUrl;
	*/
}