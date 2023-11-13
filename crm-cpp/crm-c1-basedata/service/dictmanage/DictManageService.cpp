#pragma once
#include "stdafx.h"
#include "DictManageService.h"
#include "../../dao/dictmanage/DictManageDAO.h"
//��ѯ
DictPageDTO::Wrapper DictManageService::listAll(const DictQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DictPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	DictDAO dao;
	auto cnt = dao.count(query);//��ҳ ���Ʋ�ѯ������
	if (cnt == 0) 
	{
		//û������
		return pages;
	}
	//��ѯ��Ϣ
	pages->total = cnt;
	pages->calcPages();
	list<DictDO> res = dao.selectWithPage(query);//����һ���б�list
	//����(ת��)���� DO-->DTO
	for (DictDO data : res) 
	{
		//ת��
		auto dto = DictDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, data, name, Name, typetag, Typetag, sort, Sort, visible, Visible,id,Id)
		//д������
		pages->addData(dto);
	}
	//���ؽ��
	return pages;
}
//�������
uint64_t DictManageService::saveData(const DictDTO::Wrapper& dto)
{
	// ��װDO����
	DictDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Typetag, typetag, Sort, sort, Visible, visible)
		// ִ���������
		DictDAO dao;
	return dao.insert(data);
}
//�޸�����
bool DictManageService::updateData(const DictDTO::Wrapper& dto)
{
	// ��װDO����
	DictDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Typetag, typetag, Sort, sort, Visible, visible , Id, id)
		// ִ�������޸�
		DictDAO dao;
	return dao.update(data) == 1;
}
//ɾ��
bool DictManageService::removeData(uint64_t id)
{
	DictDAO dao;
	return dao.deleteById(id) == 1;
}
//��ȡ�����б�
oatpp::List<DictTypeListDTO::Wrapper> DictManageService::getPage()
{
	//���ڷ��ؽ��
	auto ans = oatpp::List<DictTypeListDTO::Wrapper>::createShared();
	 
	DictDAO dao;
	auto res = dao.selectPage();//���ط�������list --DO
	//DO->DTO
	for (auto& name : res) 
	{
		auto t = DictTypeListDTO::createShared();
		t->id = name.getId();
		t->tpyename = name.getName();//��������
		ans->push_back(t);
		//List
	}
	//���ؽ��
	return ans;
}
