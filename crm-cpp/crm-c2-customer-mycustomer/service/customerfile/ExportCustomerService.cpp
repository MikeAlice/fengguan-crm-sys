/*
* 负责人：老菌
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
	// 构建返回对象,返回客户信息
	auto data = list<ExportCustomerDTO::Wrapper>();

	ExportCustomerDAO dao;

	list<CustomerDO> result = dao.selectAll(query);
	// 将DO转换成DTO
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
	// 转换客户信息格式为二维数组
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

	//构建文件名及页表名
	time_t mytime = time(NULL);
	stringstream ss;
	ss << mytime;
	string fileName = "./public/excel/" + ss.str() + ".xlsx";
	//string sheetName = CharsetConvertHepler::ansiToUtf8("客户信息_" + ss.str());
	string sheetName = "Sheet1";
	//cout << fileName << endl;
	// 保存客户信息到Excel文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	string fieldName = client.uploadFile(fileName);
	if (fieldName == "") {
		return "upload fail";
	}
	//cout << fieldName << endl;
	// 构建下载路径
	string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	//std::cout << "download url: " << downloadUrl << std::endl;
	int count = 0;
	while (remove(fileName.c_str()) != 0 && count++ < 3);

	return downloadUrl;
}