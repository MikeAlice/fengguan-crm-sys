#include "stdafx.h"
#include "DictClassifyService.h"
#include "../../dao/dictclassify/DictClassifyDAO.h"
#include"domain/do/dictclassify/DictClassifyDO.h"

DictClassifyPageDTO::Wrapper DictClassifyService::listAll(const DictClassifyQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DictClassifyPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	DictClassifyDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<DictClassifyDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// ��װDO����
	DictClassifyDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, TypeName, typeName, Typedir, typedir,Typetag, typetag, Sort, sort, Visible, visible, Intro, intro, Seotitle, seotitle, Keywords, keywords)
		// ִ���������
		DictClassifyDAO dao;
	return dao.insert(data);
}

bool DictClassifyService::updateData(const DictClassifyDTO::Wrapper& dto)
{
	// ��װDO����
	DictClassifyDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, TypeName, typeName, Typedir, typedir, Typetag, typetag, Sort, sort, Visible, visible, Intro, intro, Seotitle, seotitle, Keywords, keywords)
		// ִ�������޸�
		DictClassifyDAO dao;
	return dao.update(data) == 1;
}

bool DictClassifyService::removeData(uint64_t id)
{
	DictClassifyDAO dao;
	return dao.deleteById(id) == 1;
}

//��ȡ�����б�
//��ȡ�����б�
oatpp::List<DictClassifyListDTO::Wrapper> DictClassifyService::getlistAll(const DictClassifyListQuery::Wrapper& query)
{
	//���ڷ��ؽ��
	auto ans = oatpp::List<DictClassifyListDTO::Wrapper>::createShared();

	DictClassifyDAO dao;
	if (query->typeName == nullptr) {
		auto reslist = dao.selectPage();//���ط�������list --DO


		for (auto& name : reslist)
		{
			auto t = DictClassifyListDTO::createShared();
			t->id = name.getId();
			t->typeName = name.getTypeName();//��������
			t->typetag = name.getTypetag();
			ans->push_back(t);
			//List
		}
		//���ؽ��
		return ans;
	}

	auto res = dao.selectByName(query->typeName);//���ط�������list --DO
	if (query->typeName) {
		for (auto& name : res)
		{
			auto t = DictClassifyListDTO::createShared();
			t->id = name.getId();
			t->typeName = name.getTypeName();//��������
			t->typetag = name.getTypetag();
			ans->push_back(t);
			//List
		}
		//���ؽ��
		return ans;
	}
}
