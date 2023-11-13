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

	// 构建返回对象,返回信息
	auto data = list<ListCapitalRecordDTO::Wrapper>();

	//ExportCapitalRecordDAO dao;

	//list<FinCapitalRecordDO> result = dao.selectAll(query);
	//// 将DO转换成DTO
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
	//Service层创建dao对象进行dao层操作
	ExportCapitalRecordDAO dao;
	//在Service把dto往dao层传
	auto DOList = dao.selectWithIdList(dto);

	// 获取标题行
	auto title = getTitles();//vector<string>类型

	// 添加标题行
	vector<vector<std::string>> data{};//创建二维数组
	data.push_back(title);//给二维数组第一行赋值

	// 添加数据行
	for (const auto& i : DOList)
	{
		vector<string> row{};//创建一维数组
		//row.push_back(to_string(i.getRecordId()));//把第一行的id放进去
		//if(i.getTypeId() == 1)
		//{
		//	row.push_back(u8"资金注入");
		//}else if (i.getTypeId() == -1)
		//{
		//	row.push_back(u8"资金抽取");
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
	//二维数组全部搞定
	// 创建Excel并上传到Nacos
	//useExcel::createExcelFile(data)返回文件名字
	std::string excelFile= useExcel::createExcelFile(data);
	// useFastDFS::useDfsWithNacos(excelFile)返回链接
	string downloadURL = useFastDFS::useDfsWithNacos(excelFile);
	cout << downloadURL << endl;
	//删除本地文件
	const char* p = excelFile.c_str();
	if (remove(p) != 0) { // 尝试删除文件
		cout << "Failed to delete file." << endl;
	}
	else {
		cout << "File deleted successfully." << endl;
	}
	 
	return downloadURL;
}

//bool ExportCapitalRecordService::deleteExportFile(string filePath)
//{
//	// 定义DFS客户端对象和URL前缀
//	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
//
//	//// 获取删除文件路径
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
	/*title.push_back(u8"单号");
	title.push_back(u8"支出类型");
	title.push_back(u8"金额");
	title.push_back(u8"银行账号");
	title.push_back(u8"产生日期");
	title.push_back(u8"创建人");
	title.push_back(u8"创建时间");
	title.push_back(u8"备注");*/

	title.push_back(CharsetConvertHepler::ansiToUtf8("供应商"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("创建时间"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("合同标题"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("发票内容"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("发票编号"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("金额"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("收票时间"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("期次"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("创建人"));
	title.push_back(CharsetConvertHepler::ansiToUtf8("备注"));


	return title;
}

std::string ExportCapitalRecordService::getExcelFileName()
{
	string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}
