#pragma once
#ifndef $DELETE_STORAGE_H_
#define $DELETE_STORAGE_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "service/in_storage/InStorageService.h"
#include "ApiHelper.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * DeleteStorage控制器：删除入库单 负责人：余晖
 */
class DeleteStorageController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteStorageController);
	// 3 定义接口
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/inventory-manager/delete-storage", deleteStorage, BODY_DTO(List<DeleteByIDStorageDTO::Wrapper>, dto), execDeleteStorage(dto, authObject->getPayload()));
	ENDPOINT_INFO(deleteStorage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deletestorage.controller.delete.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(Int64JsonVO);
		// 定义其他查询参数描述
	}
private:
	// 在此添加定义
	Int64JsonVO::Wrapper execDeleteStorage(const List<DeleteByIDStorageDTO::Wrapper>& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // $FILE_BASE_UPPER$_H__