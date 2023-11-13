#include "stdafx.h"
#include "DictClassifyService.h"
#include "../../dao/dictclassify/DictClassifyDAO.h"
#include"domain/do/dictclassify/DictClassifyDO.h"

DictClassifyPageDTO::Wrapper DictClassifyService::listAll(const DictClassifyQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DictClassifyPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	DictClassifyDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DictClassifyDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DictClassifyDO sub : result)
	{
		auto dto = DictClassifyDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,bank_id,Bank_Id, name, Name, card, Card, holders, Holders, sort, Sort, visible, Visible)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,id,Id,typeName, TypeName,typedir,Typedir, typetag, Typetag, sort, Sort, visible, Visible, intro, Intro, seotitle, Seotitle, keywords, Keywords)
			pages->addData(dto);

	}
	return pages;
}

uint64_t DictClassifyService::saveData(const DictClassifyDTO::Wrapper& dto)
{
	// 组装DO数据
	DictClassifyDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, TypeName, typeName, Typedir, typedir,Typetag, typetag, Sort, sort, Visible, visible, Intro, intro, Seotitle, seotitle, Keywords, keywords)
		// 执行数据添加
		DictClassifyDAO dao;
	return dao.insert(data);
}

bool DictClassifyService::updateData(const DictClassifyDTO::Wrapper& dto)
{
	// 组装DO数据
	DictClassifyDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, TypeName, typeName, Typedir, typedir, Typetag, typetag, Sort, sort, Visible, visible, Intro, intro, Seotitle, seotitle, Keywords, keywords)
		// 执行数据修改
		DictClassifyDAO dao;
	return dao.update(data) == 1;
}

bool DictClassifyService::removeData(uint64_t id)
{
	DictClassifyDAO dao;
	return dao.deleteById(id) == 1;
}

//获取下拉列表
//获取下拉列表
oatpp::List<DictClassifyListDTO::Wrapper> DictClassifyService::getlistAll(const DictClassifyListQuery::Wrapper& query)
{
	//定于返回结果
	auto ans = oatpp::List<DictClassifyListDTO::Wrapper>::createShared();

	DictClassifyDAO dao;
	if (query->typeName == nullptr) {
		auto reslist = dao.selectPage();//返回分类名称list --DO


		for (auto& name : reslist)
		{
			auto t = DictClassifyListDTO::createShared();
			t->id = name.getId();
			t->typeName = name.getTypeName();//解析数据
			t->typetag = name.getTypetag();
			ans->push_back(t);
			//List
		}
		//返回结果
		return ans;
	}

	auto res = dao.selectByName(query->typeName);//返回分类名称list --DO
	if (query->typeName) {
		for (auto& name : res)
		{
			auto t = DictClassifyListDTO::createShared();
			t->id = name.getId();
			t->typeName = name.getTypeName();//解析数据
			t->typetag = name.getTypetag();
			ans->push_back(t);
			//List
		}
		//返回结果
		return ans;
	}
}
