#include "stdafx.h"
#include "DictClassifyController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/dictclassify/DictClassifyDO.h"
#include "service/dictclassify/DictClassifyService.h"
#include"domain/vo/dictclassify/DictClassifyVO.h"
#include "tree/TreeUtil.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
DictClassifyPageJsonVO::Wrapper DictClassifyController::execQueryDictClassify(const DictClassifyQuery::Wrapper& query, const PayloadDTO& payload)
{

	// ����һ��Service
	
	DictClassifyService service;
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = DictClassifyPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
// 3.3 ��ʾ��������
Uint64JsonVO::Wrapper DictClassifyController::execAddDictClassify(const DictClassifyDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	//jvo->success(1);
	//return jvo;
	// ����һ��Service
	DictClassifyService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;

}
// 3.3 ��ʾ�޸�����
Uint64JsonVO::Wrapper  DictClassifyController::execModifyDictClassify(const DictClassifyDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	DictClassifyService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}
// 3.3 ��ʾɾ������
Uint64JsonVO::Wrapper  DictClassifyController::execRemoveDictClassify(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	/*if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// ����һ��Service
	DictClassifyService service;
	// ִ������ɾ��

	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}






//Uint64JsonVO::Wrapper DictClassifyController::execRemoveMoreDictClassify(const DictClassifyDTO::Wrapper& dto) {
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����һ��Service
//	DictClassifyService service;
//	// ִ������ɾ��
//	
//
//	
//	// ��Ӧ���
//	return jvo;
//}
//









DictClassifyListJsonVO::Wrapper DictClassifyController::execGetDictClassifyList(const DictClassifyListQuery::Wrapper& query, const PayloadDTO& payload)
{

	// ����һ��Service
	DictClassifyService service;
	auto result = service.getlistAll(query);
	//��Ӧ���
	auto jvo = DictClassifyListJsonVO::createShared();
	jvo->success(result);
	return jvo;

}