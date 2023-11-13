#pragma once
#ifndef _GETCUSTOMERDETAILS_CONTROLLER_
#define _GETCUSTOMERDETAILS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/getcutomerdetails/GetCustomerDetailsQuery.h"
#include "domain/vo/getcustomerdetails/GetCustomerDetailsVO.h"
#include "service/getcutomerdetails/GetCustomerDetailsService.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 获取客户详细信息
 */
class GetCustomerDetailsController : public oatpp::web::server::api::ApiController //继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetCustomerDetailsController);

public: 
	//定义接口
	// 定义获取联系人列表接口	负责人：老菌
	ENDPOINT(API_M_GET, "/customer-mycustomer/query-customer-details", queryCustomerDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(customerQuery, GetCustomerDetailsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCustomerDetails(customerQuery, authObject->getPayload()));
	}
	// 定义获取联系人列表接口描述
	ENDPOINT_INFO(queryCustomerDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.query-contact-details"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetCustomerDetailsJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("customer.field.id"), 1, true);
	}
private:
	// 获取客户名称列表
	GetCustomerDetailsJsonVO::Wrapper execQueryCustomerDetails(GetCustomerDetailsQuery::Wrapper query, const PayloadDTO& playload);
};

//取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // _GETCUSTOMERDETAILS_CONTROLLER_