#ifndef GETCUSTOMERNAMECONTROLLER_H__
#define GETCUSTOMERNAMECONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include"domain/dto/getcustomername/GetCustomerNameDTO.h"
#include "domain/vo/getcustomername/GetCustomerNameVO.h"
#include "service/getcustomername/GetCustomerNameService.h"
#include "domain/query/getcustomername/GetCustomerNameQuery.h"

// 定义API控制器使用宏

#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 获取客户名称列表操作接口实现
 */
class GetCustomerNameController : public oatpp::web::server::api::ApiController //继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetCustomerNameController);

public: //定义接口
	//获取客户名称列表
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, OTC_PRFIX("/get-customername"), getCustomername, BODY_DTO(GetCustomerNameDTO::Wrapper, dto), execGetCustomerName(dto, authObject->getPayload()));
	ENDPOINT_INFO(getCustomerName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getcustomername.controller.get.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetCustomerNameJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("getcustomername.field.name"), "", false);
	}
	ENDPOINT(API_M_GET, "/customer-mycustomer/get-customername", getCustomerName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetCustomerNameQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetCustomerName(userQuery, authObject->getPayload()));
	}
private:
	// 获取客户名称列表
	GetCustomerNameJsonVO::Wrapper execGetCustomerName(const GetCustomerNameQuery::Wrapper& query, const PayloadDTO& payload);
};

//取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // GETCUSTOMERNAMECONTROLLER_H__