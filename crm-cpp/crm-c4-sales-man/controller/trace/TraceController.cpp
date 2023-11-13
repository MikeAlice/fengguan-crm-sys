#include "stdafx.h"
#include "TraceController.h"
#include "../../service/trace/TraceService.h"
#include <iostream>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

//增加模块
BooleanJsonVO::Wrapper TraceController::execAddTrace(const AddTraceDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->customer_id || !dto->linkman_id || !dto->AC || !dto->CC || !dto->SOid || !dto->FMethodid || !dto->FTime || !dto->CContent || !dto->CStageid || !dto->SOpportunity || !dto->NTime)
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->customer_id < 0 || dto->linkman_id < 0 || dto->FMethodid < 0 || dto->SOid < 0 || dto->AC->empty() || dto->CC->empty() || dto->FTime->empty() || dto->CContent->empty() || dto->CStageid>0 || dto->SOpportunity->empty() || dto->NTime->empty())
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TraceService service;
	// 执行数据新增
	Int32 customer_id = service.saveData(dto);

	if (customer_id >= 0) {
		return jvo;
	}
	else
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
}

//修改模块
BooleanJsonVO::Wrapper TraceController::execModifyTrace(const ModifyTraceDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	if (!dto->customer_id || !dto->linkman_id || !dto->SOid || !dto->FMethodid || !dto->FTime || !dto->CContent || !dto->CStageid || !dto->NTime) {
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TraceService service;
	// 执行数据修改
	if (service.updateData(dto))
		return jvo;
	else
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
}

//分页查询模块
TracePageJsonVO::Wrapper TraceController::execQueryGet(const TraceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	TraceService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TracePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return TracePageJsonVO::createShared();
}
//执行删除跟踪记录
Uint64JsonVO::Wrapper TraceController::execTraceDelete(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个Service
	TraceService service;
	//执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper TraceController::execListTraceDelete(const ListTraceDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	auto cur = dto->listtrace_id.getPtr();
	if (cur->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto i = cur->begin(); i != cur->end(); i++) {
		if (!*i || *i < 0) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	TraceService service;
	//执行数据删除
	for (auto i = cur->begin(); i !=cur->end(); i++)
	{
		auto id = *i;
		if (service.removeData(id.getValue(0))) {
				jvo->success(id);
			}
		else
		{
			jvo->fail(id);
		}
	}
	//响应结果
	return jvo;
}

//执行下载跟踪记录文件
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TraceController::execDownloadFile()
{
	TraceService service;
	service.exportTracefile();
	// 读取文件
	auto fstring = String::loadFromFile("./public/excel/traceFile.xlsx");

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=traceFile.xlsx");

	// 影响成功结果
	return response;
}