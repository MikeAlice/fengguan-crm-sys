#pragma once
#ifndef _DELPAYPLAN_CONTROLLER_
#define _DELPAYPLAN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/paybackmanage/DeletePayPlanDTO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 删除指定合同
 */
class DelPayPlanController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DelPayPlanController);
	// 3 定义接口
public:

	//ENDPOINT_INFO(delPayPlan) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON(ZH_WORDS_GETTER("paybackmanage.delete.payplan"), Uint64JsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(List<Int32>, "dto", ZH_WORDS_GETTER("paybackmanage.field.dto"), , true);
	//}

	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("paybackmanage.delete.payplan"), delPayPlan, Uint64JsonVO::Wrapper);

	API_HANDLER_ENDPOINT(API_M_DEL, "/collection-man/payback-manage/del-payplan", delPayPlan, BODY_DTO(DeletePayPlanDTO::Wrapper, dto), execDelPayPlan(dto));
	//ENDPOINT_INFO(recordDelete) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("record.delete.summary"), Uint64JsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("record.field.id"), , true);
	//}
	//// 定义跟踪记录删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/record/{id}", recordDelete, PATH(UInt64, id), execDelPayPlan(id));

private:
	Uint64JsonVO::Wrapper execDelPayPlan(const DeletePayPlanDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_