#pragma once
/*
* 负责人：老菌
*/
#ifndef _IMPORT_CONTROLLER_
#define _IMPORT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/customerfile/ImportResultVO.h"
#include "ApiHelper.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 导入客户控制器
 */
class ImportController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ImportController);
	// 3 定义接口
public:
	// 定义上传单个导入文件接口	负责人：老菌
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/upload-customer-file", uploadCustomerFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadCustomerFileOne(request));
	// 定义上传单个导入文件接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("customer.controller.upload"), uploadCustomerFile, StringJsonVO::Wrapper);


	// 定义导入客户接口	负责人：老菌
	//API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/import-customer", importCustomer, BODY_DTO(FilePathDTO::Wrapper, dto), execImportCustomer(dto, authObject->getPayload()));
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/import-customer", importCustomer, BODY_STRING(String, fileName), execImportCustomer(fileName, authObject->getPayload()));
	// 定义导入客户接口描述
	ENDPOINT_INFO(importCustomer) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.import"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportResultJsonVO);
	}

private:
	/*负责人： 老菌
	* 功能描述：接收Excel文件，临时保存到本地，再将路径发送回前端
	* @param： request  导入请求数据
	* @return： StringJsonVO  成功返回文件路径，失败则返回失败原因
	*/
	StringJsonVO::Wrapper execUploadCustomerFileOne(std::shared_ptr<IncomingRequest> request);

	/*负责人： 老菌
	* 功能描述：将Excel文件读取到内存，然后持久化到数据库
	* @param： filepath   文件路径
	* @return： ImportResultJsonVO  返回成功条数和失败条数
	*/
	ImportResultJsonVO::Wrapper execImportCustomer(String fileName, const PayloadDTO& playload);

};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _IMPORT_CONTROLLER_
