#include "stdafx.h"
#include "ExportPayRecordService.h"
#include "domain/do/export-pay-record/ExportPayRecordDO.h"
#include <sstream>
#include "dao/export-pay-record/ExportPayRecordDAO.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
#include "Macros.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
//#include "CharsetConvertHepler.h"
#include <time.h>
#include <CharsetConvertHepler.h>

std::string ExportPayRecordService::exportPayRecord(const oatpp::List<ExportPayRecordDTO::Wrapper>& dto)
{
	// 组装DO数据
	/*ExportPayRecordDO data;
	stringstream stream;
	for (auto i = dto->begin(); i != dto->end(); i++)
	{
		if (i != dto->begin())	
			stream << ",";
		stream << (*i)->record_id.getValue(1);
	}
	string ids;
	stream >> ids;
	data.setRecordId(ids);*/
	// 执行查询
	ExportPayRecordDAO dao;
	auto resList = dao.selectByID(dto);
	// 组装数据
	vector<vector<std::string>> data{};
	vector<string> title = { u8"付款记录ID",u8"供应商名称",u8"采购合同",u8"付款时间",u8"期次",u8"金额",u8"去零",u8"创建人",u8"创建时间",u8"备注"};
	data.push_back(title);
	
	for (const auto& i : resList)
	{
		vector<string> row{};
		row.push_back(to_string(i.getRecordId()));
		row.push_back(i.getSupplierName());
		row.push_back(i.getContractnName());
		row.push_back(i.getPayDate());
		row.push_back(to_string(i.getStages()));
		row.push_back(to_string(i.getMoney()));
		row.push_back(to_string(i.getZeroMoney()));
		//row.push_back(to_string(i.getCreateUserId()));
		row.push_back(i.getCreateUser());
		row.push_back(i.getCreateTime());
		row.push_back(i.getIntro());
		data.push_back(row);
	}
	/*for ( vector<std::string> i : data)
	{
		for (std::string j : i)
			std::cout << j << "\t";
		std::cout << std::endl;
	}*/
	//生成excel
	stringstream sLocalFileName;
	sLocalFileName << "./public/excel/";
	sLocalFileName << time(NULL);
	sLocalFileName << ".xlsx";
	string localFileName=sLocalFileName.str();
	//std::cout <<"localFileName: "<< localFileName << endl;
	//sLocalFileName >> localFileName;
	//std::string sheetName = CharsetConvertHepler::ansiToUtf8("工作簿1");
	ExcelComponent excel;
	excel.writeVectorToFile(localFileName, "sheet1", data);
	//上传服务器
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	std::string dfsFileName = client.uploadFile(localFileName);
	//构建下载路径
	std::string downloadUrl = urlPrefix + dfsFileName;
	//返回下载路径
	return downloadUrl;
}
