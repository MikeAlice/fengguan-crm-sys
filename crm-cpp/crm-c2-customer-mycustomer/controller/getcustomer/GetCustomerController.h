#ifndef GETCUSTOMERCONTROLLER_H__
#define GETCUSTOMERCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include"domain/dto/getcustomer/GetCustomerDTO.h"
#include "domain/query/getcustomer/GetCustomerQuery.h"
#include "domain/vo/getcustomer/GetCustomerVO.h"
#include "service/getcustomer/GetCustomerService.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 获取客户列表操作接口实现
 */
class GetCustomerController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetCustomerController);
	
public: //定义接口
	//获取客户列表
	ENDPOINT_INFO(getCustomer) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getcustomer.controller.get.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetCustomerPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "conn_time", ZH_WORDS_GETTER("getcustomer.field.conn_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "next_time", ZH_WORDS_GETTER("getcustomer.field.next_time"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("getcustomer.field.name"), u8"", false);
		API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("getcustomer.field.mobile"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("getcustomer.field.tel"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("getcustomer.field.address"), u8"", false);
	}
	ENDPOINT(API_M_GET, "/customer-mycustomer/get-customer" , getCustomer, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetCustomerQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetCustomer(userQuery, authObject->getPayload()));
	}
private:
	// 在获取客户列表
	GetCustomerPageJsonVO::Wrapper execGetCustomer(const GetCustomerQuery::Wrapper& query, const PayloadDTO& payload);
};

//取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // GETCUSTOMERCONTROLLER_H__