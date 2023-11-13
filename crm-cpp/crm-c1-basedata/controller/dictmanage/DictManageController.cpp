#include "stdafx.h"
#include "DictManageController.h"
#include "../../service/dictmanage//DictManageService.h"
#include "../ApiDeclarativeServicesHelper.h"
//添加字典
Uint64JsonVO::Wrapper DictManageController::execAddDict(const DictDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->name || !dto->typetag || !dto->sort || !dto->visible)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->sort < 0 || dto->name->empty() || dto->typetag->empty() || dto->visible > 1 || dto->visible < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个服务
	DictManageService service;
	//执行添加
	int64_t id = service.saveData(dto);
	//判断是否成功
	if (id > 0) jvo->success(UInt64(id));
	else jvo->fail(UInt64(id));
	//返回结果
	return jvo;
}
//修改字典
Uint64JsonVO::Wrapper DictManageController::execModifyDict(const DictDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->name || !dto->typetag || !dto->sort || !dto->visible)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->sort < 0 || dto->name->empty() || dto->typetag->empty() || dto->visible > 1 || dto->visible < 0 || dto->id < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个服务
	DictManageService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	//返回结果
	return jvo;
}
//删除字典
Uint64JsonVO::Wrapper DictManageController::execDeleteDict(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 有效值校验
	if (id < 0)
	{
		jvo->fail(id);
		return jvo;
	}
	//创建服务
	DictManageService service;
	//执行删除 并返回结果
	bool isDelect = service.removeData(id);
	if (isDelect) jvo->success(id);
	else jvo->fail(id);
	//返回结果
	return jvo;
}
//查询字典
DictPageJsonVO::Wrapper DictManageController::execQueryDict(const DictQuery::Wrapper& query, const PayloadDTO& payload)
{
	//定义查询结果
	auto jvo = DictPageJsonVO::createShared();
	//定义服务
	DictManageService serice;
	//请求查询
	auto res = serice.listAll(query);
	//返回结果
	jvo->success(res);
	return jvo;
}
//获取分页列表
DictTypePageJsonVO::Wrapper DictManageController::execPageDict()
{
	//定义返值
	auto jvo = DictTypePageJsonVO::createShared();
	//定义服务
	DictManageService service;
	//查询结果
	auto res = service.getPage();
	jvo->success(res);
	//返回结果
	return jvo;
}