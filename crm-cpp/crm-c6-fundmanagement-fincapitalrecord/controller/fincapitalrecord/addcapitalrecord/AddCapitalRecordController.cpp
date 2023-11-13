#include "stdafx.h"
#include "AddCapitalRecordController.h"
#include "service/fincapitalrecord/addcapitalrecord/AddCapitalRecordService.h"

// 添加数据
StringJsonVO::Wrapper AddCapitalRecordController::execAddCapitalRecord(const AddCapitalRecordDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->type_id != 1 && dto->type_id != -1)
	{
		jvo->init(u8"type_id必须为1或-1", RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->money) {
		jvo->init(u8"金额不能为空", RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->money <= 0) {
		jvo->init(u8"金额不能小于0", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个service
	AddCapitalRecordService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(u8"添加成功");
	}
	else
	{
		jvo->fail(u8"添加失败");
	}
	//响应结果
	return jvo;
}