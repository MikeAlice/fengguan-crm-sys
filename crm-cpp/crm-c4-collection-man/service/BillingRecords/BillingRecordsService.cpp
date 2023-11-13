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
	//组装数据--------------------------------------------
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

	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = "./public/excel/ExportBillingRecords.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("开票列表");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// 测试覆盖第一个页签
	sheetName = CharsetConvertHepler::ansiToUtf8("开票列表");
	data.insert(data.begin(), {
		CharsetConvertHepler::ansiToUtf8("客户名称") ,
		CharsetConvertHepler::ansiToUtf8("合同单号") ,
		CharsetConvertHepler::ansiToUtf8("发票金额") ,
		CharsetConvertHepler::ansiToUtf8("发票编号") ,
		CharsetConvertHepler::ansiToUtf8("开票时间") ,
		CharsetConvertHepler::ansiToUtf8("期次") ,
		CharsetConvertHepler::ansiToUtf8("创建人") ,
		CharsetConvertHepler::ansiToUtf8("备注") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);

	/*
	// 测试使用FastDFS
	// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	std::cout << "download url: " << downloadUrl << std::endl;

	return downloadUrl;
	*/
}