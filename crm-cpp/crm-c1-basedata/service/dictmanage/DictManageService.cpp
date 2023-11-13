#pragma once
#include "stdafx.h"
#include "DictManageService.h"
#include "../../dao/dictmanage/DictManageDAO.h"
//查询
DictPageDTO::Wrapper DictManageService::listAll(const DictQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DictPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	DictDAO dao;
	auto cnt = dao.count(query);//分页 限制查询数据量
	if (cnt == 0) 
	{
		//没有数据
		return pages;
	}
	//查询信息
	pages->total = cnt;
	pages->calcPages();
	list<DictDO> res = dao.selectWithPage(query);//返回一个列表list
	//解析(转化)数据 DO-->DTO
	for (DictDO data : res) 
	{
		//转化
		auto dto = DictDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, data, name, Name, typetag, Typetag, sort, Sort, visible, Visible,id,Id)
		//写入数据
		pages->addData(dto);
	}
	//返回结果
	return pages;
}
//添加数据
uint64_t DictManageService::saveData(const DictDTO::Wrapper& dto)
{
	// 组装DO数据
	DictDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Typetag, typetag, Sort, sort, Visible, visible)
		// 执行数据添加
		DictDAO dao;
	return dao.insert(data);
}
//修改数据
bool DictManageService::updateData(const DictDTO::Wrapper& dto)
{
	// 组装DO数据
	DictDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Typetag, typetag, Sort, sort, Visible, visible , Id, id)
		// 执行数据修改
		DictDAO dao;
	return dao.update(data) == 1;
}
//删除
bool DictManageService::removeData(uint64_t id)
{
	DictDAO dao;
	return dao.deleteById(id) == 1;
}
//获取下拉列表
oatpp::List<DictTypeListDTO::Wrapper> DictManageService::getPage()
{
	//定于返回结果
	auto ans = oatpp::List<DictTypeListDTO::Wrapper>::createShared();
	 
	DictDAO dao;
	auto res = dao.selectPage();//返回分类名称list --DO
	//DO->DTO
	for (auto& name : res) 
	{
		auto t = DictTypeListDTO::createShared();
		t->id = name.getId();
		t->tpyename = name.getName();//解析数据
		ans->push_back(t);
		//List
	}
	//返回结果
	return ans;
}
