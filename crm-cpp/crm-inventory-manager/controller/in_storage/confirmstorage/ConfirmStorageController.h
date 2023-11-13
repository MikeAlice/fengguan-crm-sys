#pragma once
#ifndef $FILE_BASE_UPPER$_H__
#define $FILE_BASE_UPPER$_H__

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "domain/vo/in_storage/InStorageJsonVO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "service/in_storage/InStorageService.h"
#include "ApiHelper.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ConfirmStorage控制器：确认入库 负责人：余晖
 */
class ConfirmStorageController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ConfirmStorageController);
	// 3 定义接口
public:
	ENDPOINT_INFO(modifyConfirmStorage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("confirmstorage.controller.get.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/inventory-manager/query-isStorage", queryIsStorage, BODY_DTO(IntostockDTO::Wrapper, dto), execQueryIsStorage(dto, authObject->getPayload()));
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("confirmstorage.controller.get.summary"), modifyConfirmStorage, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/inventory-manager/modify-ConfirmStorage", modifyConfirmStorage, BODY_DTO(ModifyByIDStorageDTO::Wrapper, dto), execModifyConfirmStorage(dto, authObject->getPayload()));


private:
	// 在此添加定义
	StringJsonVO::Wrapper execModifyConfirmStorage(const ModifyByIDStorageDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // $FILE_BASE_UPPER$_H__