#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/confirm_remove_pay/ConfirmRemovePayDTO.h"
#include "oatpp/core/Types.hpp"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 付款控制器，付款计划删除接口和确认付款接口
 * 负责人：rui
 */
class ConfirmRemovePayController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ConfirmRemovePayController);
	// 3 定义接口
public:
	/*
	* 删除接口：
	*负责人：rui
	*/
	// 定义删除接口描述
	ENDPOINT_INFO(removeConfirmpay) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("confirmpay.controller.delete.summary"), Uint64JsonVO::Wrapper);
	}
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/payment/pay-plan/del/{plan_ids}", removeConfirmpay, BODY_DTO(oatpp::List<UInt64>, plan_ids), execRemoveConfirmpay(plan_ids));


	/*
	* 确认付款接口
	* 负责人：rui
	*/
	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("confirmpay.controller.put.summary"), modifyConfirmpay, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/payment/pay-plan/confirm/{plan_id}", modifyConfirmpay, PATH(UInt64, plan_id), execModifyConfirmpay(plan_id));


private:
	Uint64JsonVO::Wrapper execRemoveConfirmpay(oatpp::List<UInt64> plan_ids);
	Uint64JsonVO::Wrapper execModifyConfirmpay(const UInt64& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
//