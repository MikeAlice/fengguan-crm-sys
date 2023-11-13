#pragma once
#ifndef _SELAMOUNTINFO_CONTROLLER_
#define _SELAMOUNTINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/paybackmanage/VectorAmountJsonVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取金额
 */
class SelectAmountInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SelectAmountInfoController);
	// 3 定义接口
public:

		// 3.1 定义查询接口描述
	ENDPOINT_INFO(selectAmountInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("paybackmanage.query.amount"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(VectorAmountJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "amountid", ZH_WORDS_GETTER("paybackmanage.field.amountid"), 123, true);
	}
	// 3.2 定义查询接口处理
	//ENDPOINT(API_M_GET, "payback-manage/select-amountinfo", selectAmountInfo, QUERIES(QueryParams, queryParams)) {
	//	// 解析查询参数为Query领域模型
	//	API_HANDLER_QUERY_PARAM(userQuery, SelectAmountInfoQuery, queryParams);
	//	// 呼叫执行函数响应结果
	//	API_HANDLER_RESP_VO(execSelectAmountInfo(userQuery));

	//}
	API_HANDLER_ENDPOINT(API_M_GET, "/collection-man/payback-manage/select-amountinfo", selectAmountInfo, QUERY(UInt64, amountid), execSelectAmountInfo(amountid));

private:
	VectorAmountJsonVO::Wrapper execSelectAmountInfo(const UInt64& amountid);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_