#include "stdafx.h"
#include "ExportCapitalRecordService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"

#include "uselib/fastdfs/useFastDFS.h"
#include "uselib/excel/useExcel.h"
#include "FastDfsClient.h"
#include <cstdio>
#include "dao/export_fin_invoice_recefile/ExportCapitalRecordDAO.h"

list<ListCapitalRecordDTO::Wrapper> ExportCapitalRecordService::listAll(const ExportCapitalRecordQuery::Wrapper& query)
{

	// �������ض���,������Ϣ
	auto data = list<ListCapitalRecordDTO::Wrapper>();

	//ExportCapitalRecordDAO dao;

	//list<FinCapitalRecordDO> result = dao.selectAll(query);
	//// ��DOת����DTO
	//for (FinCapitalRecordDO sub : result)
	//{
	//	auto dto = ListCapitalRecordDTO::createShared();

	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, RecordId, type_id, TypeId, money, Money, bank_id, BankId, happen_date, HappenDate, create_user_id, CreateUserId, create_time, CreateTime, intro, Intro)
	//	data.push_back(dto);
	//}
	return data;

}

string ExportCapitalRecordService::uploadExportFile(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto)
{
	//Service�㴴��dao�������dao�����
	ExportCapitalRecordDAO dao;
	//��Service��dto��dao�㴫
	auto DOList = dao.selectWithIdList(dto);

	// ��ȡ������
	auto title = getTitles();//vector<string>����

	// ��ӱ�����
	vector<vector<std::string>> data{};//������ά����
	data.push_back(title);//����ά�����һ�и�ֵ

	// ���������
	for (const auto& i : DOList)
	{
		vector<string> row{};//����һά����
		//row.push_back(to_string(i.getRecordId()));//�ѵ�һ�е�id�Ž�ȥ
		//if(i.getTypeId() == 1)
		//{
		//	row.push_back(u8"�ʽ�ע��");
		//}else if (i.getTypeId() == -1)
		//{
		//	row.push_back(u8"�ʽ��ȡ");
		//}
		//row.push_back(to_string(i.getMoney()));
		//row.push_back(to_string(i.getBankId()));
		//row.push_back(i.getHappenDate());
		//row.push_back(to_string(i.getCreateUserId()));
		//row.push_back(i.getCreateTime());
		//row.push_back(i.getIntro());

		row.push_back(i.getSupplierName());
		row.push_back(i.getCreateTime());
		row.push_back(i.getContractName());
		row.push_back(i.getName());
		row.push_back(to_string(i.getInvoiceNo()));
		row.push_back(CharsetConvertHepler::ansiToUtf8(to_string(i.getMoney())));
		row.push_back(i.getReceDate());
		row.push_back(to_string(i.getStages()));
		row.push_back(to_string(i.getCreateUserId()));
		row.push_back(i.getIntro());
		data.push_back(row);
	}
	//��ά����ȫ���㶨
	// ����Excel���ϴ���Nacos
	//useExcel::createExcelFile(data)�����ļ�����
	std::string excelFile= useExcel::createExcelFile(data);
	// useFastDFS::useDfsWithNacos(excelFile)��������
	string downloadURL = useFastDFS::useDfsWithNacos(excelFile);
	cout << downloadURL << endl;
	//ɾ�������ļ�
	const char* p = excelFile.c_str();
	if (remove(p) != 0) { // ����ɾ���ļ�
		cout << "Failed to delete file." << endl;
	}
	else {
		cout << "File deleted successfully." << endl;
	}
	 
	return downloadURL;
}

//bool ExportCapitalRecordService::deleteExportFile(string filePath)
//{
//	// ����DFS�ͻ��˶����URLǰ׺
//	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
//
//	//// ��ȡɾ���ļ�·��
//	int pre_size = urlPrefix.size();
//	int total_size = filePath.size();
//	string fileName = filePath.substr(pre_size, total_size - 1);
//	cout << fileName << endl;
//
//	bool result = false;
//	int count = 0;
//	while (!result && count < 5) {
//		result = client.deleteFile(fileName);
//		count++;
//	}
//
//	return result;
//}

vector<string> ExportCapitalRecordService::getTitles()
{
	vector<string> title;
	/*title.push_back(u8"����");
	title.push_back(u8"֧������");
	title.push_back(u8"���");
	title.push_back(u8"�����˺�");
	title.push_back(u8"��������");
	title.push_back(u8"������");
	title.push_back(u8"����ʱ��");
	title.push_back(u8"��ע");*/

	title.push_back(CharsetConvertHepler::ansiToUtf8("��Ӧ��"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("����ʱ��"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("��ͬ����"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("��Ʊ����"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("��Ʊ���"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("���"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("��Ʊʱ��"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("�ڴ�"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("������"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("��ע"));


	return title;
}

std::string ExportCapitalRecordService::getExcelFileName()
{
	string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//תΪ�ַ���
	std::stringstream ss;
	// ���Էֱ��Բ�ͬ����ʽ������ʾ
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}
