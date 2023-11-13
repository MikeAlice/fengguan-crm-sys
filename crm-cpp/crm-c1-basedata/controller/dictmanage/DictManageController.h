#ifndef _DUCTMANAGE_CONTROLLER_
#define _DUCTMANAGE_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/dictmanage/DictDTO.h"
#include "domain/query/dictmanage/DictQuery.h"
#include "domain/vo/dictmanage/DictVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 字典管理控制器
 */
class DictManageController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DictManageController);
public:// 定义接口
	//添加
	//定义 添加字典 接口描述 使用ZH_WORDS_GETTER(xx.yy)更新描述 在zh-dict更新描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictmanage.add.newdict"), AddDictDTO, BooleanJsonVO::Wrapper);
	//定义 添加字典 接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "data-dictionary/dictmanage/add-dict", AddDictDTO, BODY_DTO(DictDTO::Wrapper, dto), execAddDict(dto, authObject->getPayload()));

	//修改
	//定义 修改字典 接口描述 使用ZH_WORDS_GETTER(xx.yy)更新描述 在zh-dict更新描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictmanage.modify.modifydict"), ModifyDictDTO, BooleanJsonVO::Wrapper);
	//定义 修改字典 接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "data-dictionary/dictmanage/modify-dict", ModifyDictDTO, BODY_DTO(DictDTO::Wrapper, dto), execModifyDict(dto, authObject->getPayload()));

	//删除
	//定义 删除字典 接口描述 使用ZH_WORDS_GETTER(xx.yy)更新描述 在zh-dict更新描述
	ENDPOINT_INFO(DeleteDict) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictmanage.delete.deletedict"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("dictmanage.field.id"), 1, true);
	}
	//定义 删除字典 接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "data-dictionary/dictmanage/delete-dict/{id}",DeleteDict, PATH(UInt64, id), execDeleteDict(id));

	//查询
	// 定义查询接口描述
	ENDPOINT_INFO(QueryDict) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictmanage.get.getdict"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DictPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("dictmanage.field.name"), "kun", false);//字典名字
		API_DEF_ADD_QUERY_PARAMS(String, "typetag", ZH_WORDS_GETTER("dictmanage.field.typetag"), "2.5years student", false);//字典分类名字
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "data-dictionary/dictmanage/get-dict", QueryDict, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DictQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDict(userQuery, authObject->getPayload()));
	}
	//获取分页列表
	//定义接口描述
	ENDPOINT_INFO(PageDict) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictmanage.get.getpage"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DictTypePageJsonVO);
	}
	// 定义接口处理
	ENDPOINT(API_M_GET, "data-dictionary/dictmanage/get-pagedict", PageDict) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execPageDict());
	}

private:// 定义接口执行函数
	//添加字典执行函数
	Uint64JsonVO::Wrapper execAddDict(const DictDTO::Wrapper& dto,const PayloadDTO& payload);
	//修改字典执行函数
	Uint64JsonVO::Wrapper execModifyDict(const DictDTO::Wrapper& dto, const PayloadDTO& payload);
	//删除字典执行函数
	Uint64JsonVO::Wrapper execDeleteDict(const UInt64& id);
	//查询字典执行函数
	DictPageJsonVO::Wrapper execQueryDict(const DictQuery::Wrapper& query, const PayloadDTO& payload);
	//获取分页列表执行函数
	DictTypePageJsonVO::Wrapper execPageDict();
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DUCTMANAGE_CONTwROLLER_