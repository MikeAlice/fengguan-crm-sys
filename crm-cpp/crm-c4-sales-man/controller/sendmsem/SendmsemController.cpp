#include "stdafx.h"
#include "SendmsemController.h"
#include "service/sendmsem/SendmsemService.h"
#include "domain/dto/sendmsem/SendmsemDTO.h"

//发送短信
BooleanJsonVO::Wrapper SendmsemController::execSendMs(const oatpp::List<oatpp::Int64>& dto) {
	// 定义返回数据对象
	auto jvo = BooleanJsonVO::createShared();
	for (auto& id : *dto) {
		// 参数校验
		// 非空校验
		if (!id) {
			jvo->init(false, RS_PARAMS_INVALID);
			return jvo;
		}
	}

	SendmsemService service;
	//获取客户预约信息
	List<InfoDTO::Wrapper> infos = service.getinfo(dto);
	if (infos && infos->size() == 0) {
		jvo->success(true);
		return jvo;
	}
	//发送短信 
	if (service.sendms(infos)) {
		jvo->success(true);
	}
	else {
		jvo->fail(false);
	}
	return jvo;
};

//发送邮件
BooleanJsonVO::Wrapper SendmsemController::execSendEm(const oatpp::List<oatpp::Int64>& dto) {
	// 定义返回数据对象
	auto jvo = BooleanJsonVO::createShared();
	for (auto& id : *dto) {
		// 参数校验
		// 非空校验
		if (!id) {
			jvo->init(false, RS_PARAMS_INVALID);
			return jvo;
		}
	}

	SendmsemService service;
	//获取客户预约信息
	List<InfoDTO::Wrapper> infos = service.getinfo(dto);
	if (infos && infos->size() == 0) {
		jvo->success(true);
		return jvo;
	}
	//发送短信
	if (service.sendem(infos)) {
		jvo->success(true);
	}
	else {
		jvo->fail(false);
	}
	return jvo;
};

