#ifndef CUSTOMERSCONTROLLER_H__
#define CUSTOMERSCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/customer/DetailsCustomerDTO.h"	
#include "domain/dto/customer/ModifyCustomerDTO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Customer控制器：添加客户与修改客户
 */
class CustomerController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CustomerController);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addcustomers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/customer-mycustomer/post-customers", addcustomers, BODY_DTO(DetailsCustomerDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddcustomers(dto, authObject->getPayload()));
	}
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("customer.controller.put.summary"), modifycustomer, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/customer-mycustomer/put-customers", modifycustomer, BODY_DTO(ModifyCustomerDTO::Wrapper, dto), execModifycustomer(dto));
private:
	// 在此添加定义
	Uint64JsonVO::Wrapper execAddcustomers(const DetailsCustomerDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifycustomer(const ModifyCustomerDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // CUSTOMERSCONTROLLER_H__