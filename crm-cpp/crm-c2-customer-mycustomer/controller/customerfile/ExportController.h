#pragma once
/*
* 负责人：老菌
*/
#ifndef _EXPORT_CONTROLLER_
#define _EXPORT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/customer/DetailsCustomerDTO.h"
#include "domain/query/customerfile/ExportCustomerQuery.h"
#include "service/customerfile/ExportCustomerService.h"
#include "ApiHelper.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 导出客户控制器
 */
class ExportController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ExportController);
	// 3 定义接口
public:
	// 定义导出客户接口	负责人：老菌
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/customer-mycustomer/export-customer", queryCustomerFile, BODY_DTO(ExportCustomerDTO::Wrapper, dto), execExportCustomer(dto, authObject->getPayload()));
	// 定义删除客户接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/export-customer", queryCustomerFile, BODY_DTO(ExportCustomerQuery::Wrapper, query), execExportCustomer(query, authObject->getPayload()));
	/*ENDPOINT(API_M_GET, "/customer-mycustomer/export-customer", queryCustomerFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(customerQuery, ExportCustomerQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execExportCustomer(customerQuery, authObject->getPayload()));
	}*/
	// 定义导出客户接口描述
	ENDPOINT_INFO(queryCustomerFile) {
		// 定义删除客户标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("customer.controller.export"), StringJsonVO::Wrapper);
	}
	/*ENDPOINT_INFO(queryCustomerFile) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.export"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(List<Int32>, "customer_id_list", ZH_WORDS_GETTER("customer.field.customer_id_list"),{1}, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_user_id", ZH_WORDS_GETTER("customer.field.create_user_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "owner_user_id", ZH_WORDS_GETTER("customer.field.owner_user_id"), 1, false);
	}*/



private:
	/*
	* 负责人： 老菌
	* 功能描述：将符合条件的客户数据保存为Excel文件，上传到文件服务器，并将路径发送到前端
	* @param： ExportCustomerDTO   筛选条件
	*			PayloadDTO&   
	* @return： StringJsonVO  返回文件路径
	*/
	StringJsonVO::Wrapper execExportCustomer(ExportCustomerQuery::Wrapper query, const PayloadDTO& playload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORT_CONTROLLER