#ifndef OUT_BOUNDCONTROLLER_H__
#define OUT_BOUNDCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/out_bound/Out_boundDTO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Out_bound控制器：操作出库明细
 */
class Out_boundController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(Out_boundController);
	// 3 定义接口
public:

	//确认出库接口  负责人：千亿
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/inventory-manager/confirm-outstock", confirmOutstock, BODY_DTO(ConfOut_boundDTO::Wrapper, dto), execConfirmOutstock(dto, authObject->getPayload()));
	ENDPOINT_INFO(confirmOutstock) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_bound.controller.put.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "out_id", ZH_WORDS_GETTER("out_bound.field.out_id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("out_bound.field.status"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "number", ZH_WORDS_GETTER("out_bound.field.number"), 100, true);
		API_DEF_ADD_QUERY_PARAMS(Int64, "out_user_id", ZH_WORDS_GETTER("out_bound.field.out_user_id"), 123, true);
	}

	//删除出库单接口  负责人：千亿
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/inventory-manager/delete-outstock", deleteOutstock, BODY_DTO(List<DelOut_boundDTO::Wrapper>, dto), execDeleteOutstock(dto, authObject->getPayload()));
	ENDPOINT_INFO(deleteOutstock) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_bound.controller.delete.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "out_id", ZH_WORDS_GETTER("out_bound.field.out_id"), 123, true);
	}

private:
	// 在此添加定义
	BooleanJsonVO::Wrapper execConfirmOutstock(const ConfOut_boundDTO::Wrapper& dto, const PayloadDTO& payload);//确认出库 负责人：千亿
	BooleanJsonVO::Wrapper execDeleteOutstock(const List<DelOut_boundDTO::Wrapper>& dto, const PayloadDTO& payload);//删除出库单 负责人：千亿
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //OUT_BOUNDCONTROLLER_H__
