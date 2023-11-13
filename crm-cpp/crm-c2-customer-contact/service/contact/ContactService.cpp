#include "stdafx.h"
#include "ContactService.h"
#include "../../dao/contact/ContactDAO.h"
#include "domain/dto/contact/AddContactDTO.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include <cstdio>
#include "CharsetConvertHepler.h"

bool ContactService::removeContact(uint64_t id) {
	ContactDAO dao;
	return dao.deleteById(id) == 1;
}

String ContactService::uploadContact(list<ExportContactDTO::Wrapper>& dtolist)
{
	// 转换客户信息格式为二维数组
	vector<vector<std::string>> data;
	//stringstream ss;
	for (auto dto : dtolist)
	{
		vector<std::string> row;
		//string str;
		//std::cout << *(dto->gender) << std::endl;
		//str = (char)(dto->gender.getValue(1));
		//std::cout << "dto->customer_name:" << (string)dto->customer_name << std::endl;
		row.push_back(dto->customer_name);
		//std::cout << "dto->linkman_name:" << (string)dto->linkman_name << std::endl;
		row.push_back(dto->linkman_name);


		if (*(dto->gender) == 1)
			row.push_back(u8"男");
		else if (*(dto->gender) == 0)
			row.push_back(u8"女");
		else 
			row.push_back(u8"其他");

		//std::cout << "dto->postion:" << (string)dto->postion << std::endl;
		row.push_back(dto->postion);
		//std::cout << "dto->tel:" << (string)dto->tel << std::endl;
		row.push_back(dto->tel);
		//std::cout << "dto->mobile:" << (string)dto->mobile << std::endl;
		row.push_back(dto->mobile);
		//std::cout << "dto->email:" << (string)dto->email << std::endl;
		row.push_back(dto->email);
		//std::cout << "dto->zipcode:" << (string)dto->zipcode << std::endl;
		row.push_back(dto->zipcode);
		//std::cout << "dto->address:" << (string)dto->address << std::endl;
		row.push_back(dto->address);
		//std::cout << "dto->intro:" << (string)dto->intro << std::endl;
		row.push_back(dto->intro);
		//std::cout << "dto->owner_user_name:" << (string)dto->owner_user_name << std::endl;
		row.push_back(dto->owner_user_name);
		//std::cout << "dto->create_time:" << (string)dto->create_time << std::endl;
		row.push_back(dto->create_time);

		data.push_back(row);
	}

	data.insert(data.begin(), {
	ZH_WORDS_GETTER("xlnt.field.customer_name"),
	ZH_WORDS_GETTER("xlnt.field.linkman_name"),
	ZH_WORDS_GETTER("xlnt.field.gender"),
	ZH_WORDS_GETTER("xlnt.field.postion"),
	ZH_WORDS_GETTER("xlnt.field.tel"),
	ZH_WORDS_GETTER("xlnt.field.mobile"),
	ZH_WORDS_GETTER("xlnt.field.email"),
	ZH_WORDS_GETTER("xlnt.field.zipcode"),
	ZH_WORDS_GETTER("xlnt.field.address"),
	ZH_WORDS_GETTER("xlnt.field.intro"),
	ZH_WORDS_GETTER("xlnt.field.ower_user_name"),
	ZH_WORDS_GETTER("xlnt.field.create_time")
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
	//cout << fieldName << endl;
	// 构建下载路径
	string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	//std::cout << "download url: " << downloadUrl << std::endl;
	int count = 0;
	while (remove(fileName.c_str()) != 0 && count++ < 3);

	return downloadUrl;
}


bool ContactService::updateContact(const UpdateContactDTO::Wrapper& dto) {
	ContactDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Linkman_id, linkman_id, Customer_id, customer_id,
		Linkman_name, linkman_name, Gender, gender, Postion, postion, Tel, tel, Mobile, mobile,
		Qicq, qicq, Email, email, Zipcode, zipcode, Address, address, Intro, intro);
	ContactDAO dao;
	return dao.update(data);
}

list<ExportContactDTO::Wrapper> ContactService::listContact(const ExportContactQuery::Wrapper& query)
{
	// 构建返回对象,返回客户信息
	auto data = list<ExportContactDTO::Wrapper>();

	ContactDAO dao;

	list<ContactDO> result = dao.selectAll(query);
	for (int i = 0; i < query->linkman_id->size(); i ++ ) 
	{
		list<ContactDO> res = dao.selectAllById(query->linkman_id[i].getValue(0));
		// 没有找到如何取出list中元素，所以这样写
		for (ContactDO i : res) {
			result.push_back(i);
		}
	}
	// 将DO转换成DTO
	for (ContactDO sub : result)
	{
		auto dto = ExportContactDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, customer_name, Customer_name, linkman_name, Linkman_name, 
			gender, Gender, postion, Postion, tel, Tel, mobile, Mobile, qicq, Qicq, email, Email,
			zipcode, Zipcode, address, Address, intro, Intro, owner_user_name, Owner_user_name, create_time, Create_time);
		data.push_back(dto);
	}
	return data;
}

uint64_t ContactService::saveContact(const AddContactDTO::Wrapper& dto, const PayloadDTO& playload) {
	ContactDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Customer_id, customer_id, Linkman_name, linkman_name, 
		Gender, gender, Postion, postion, Tel, tel, Mobile, mobile, Qicq, qicq,
		Email, email, Zipcode, zipcode, Address, address, Intro, intro);
	data.setCreate_user_id(std::atoi(playload.getId().c_str()));
	data.setCreate_time(SimpleDateTimeFormat::format());

	ContactDAO dao;
	return dao.insert(data);
}