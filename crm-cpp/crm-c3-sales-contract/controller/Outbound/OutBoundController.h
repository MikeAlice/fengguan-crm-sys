#pragma once
#ifndef GETCUSTOMERCONTROLLER_H__
#define GETCUSTOMERCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/outboundindex/OutBoundDTO.h"
#include "domain/vo/OutBoundVO.h"
#include "domain/query/OutBoundQuery.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

class OutBoundController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OutBoundController);

public: //定义接口
	//生成出库单
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, OTC_PRFIX("/get-customer"), getCustomer, BODY_DTO(GetCustomerDTO::Wrapper, dto), execGetCustomer(dto, authObject->getPayload()));
	ENDPOINT_INFO(queryOutBound) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("OutBound.controller.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(OutBoundJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "OutBoundId", ZH_WORDS_GETTER("OutBound.field.owner_user_id"), "a", false);
	}
	ENDPOINT(API_M_GET, "/sales-contract/OutBound", queryOutBound, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, OutBoundQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOutBound(userQuery, authObject->getPayload()));
	}
private:
	// 在此添加定义
	OutBoundJsonVO::Wrapper execQueryOutBound(const OutBoundQuery::Wrapper& query, const PayloadDTO& payload);
};

//取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // GETCUSTOMERCONTROLLER_H__