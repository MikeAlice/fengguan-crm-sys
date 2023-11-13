#include "stdafx.h"
#include "DictClassifyController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/dictclassify/DictClassifyDO.h"
#include "service/dictclassify/DictClassifyService.h"
#include"domain/vo/dictclassify/DictClassifyVO.h"
#include "tree/TreeUtil.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
DictClassifyPageJsonVO::Wrapper DictClassifyController::execQueryDictClassify(const DictClassifyQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 定义一个Service
	
	DictClassifyService service;
	auto result = service.listAll(query);
	//响应结果
	auto jvo = DictClassifyPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
// 3.3 演示新增数据
Uint64JsonVO::Wrapper DictClassifyController::execAddDictClassify(const DictClassifyDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	//jvo->success(1);
	//return jvo;
	// 定义一个Service
	DictClassifyService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;

}
// 3.3 演示修改数据
Uint64JsonVO::Wrapper  DictClassifyController::execModifyDictClassify(const DictClassifyDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	DictClassifyService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}
// 3.3 演示删除数据
Uint64JsonVO::Wrapper  DictClassifyController::execRemoveDictClassify(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	/*if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// 定义一个Service
	DictClassifyService service;
	// 执行数据删除

	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}






//Uint64JsonVO::Wrapper DictClassifyController::execRemoveMoreDictClassify(const DictClassifyDTO::Wrapper& dto) {
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 定义一个Service
//	DictClassifyService service;
//	// 执行数据删除
//	
//
//	
//	// 响应结果
//	return jvo;
//}
//









DictClassifyListJsonVO::Wrapper DictClassifyController::execGetDictClassifyList(const DictClassifyListQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 定义一个Service
	DictClassifyService service;
	auto result = service.getlistAll(query);
	//响应结果
	auto jvo = DictClassifyListJsonVO::createShared();
	jvo->success(result);
	return jvo;

}