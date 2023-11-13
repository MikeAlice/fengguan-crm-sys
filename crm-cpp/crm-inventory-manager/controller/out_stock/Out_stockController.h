#ifndef OUT_STOCKCONTROLLER_H__
#define OUT_STOCKCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/out_stock/Out_StockPageJsonVO.h"
#include "domain/query/out_stock/Out_StockQuery.h"
#include "domain/dto/out_stock/Out_stockDTO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Out_Stock控制器：操作出库明细
 */
class Out_StockController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(Out_StockController);
	// 3 定义接口
public:
	// 分页查询出库列表 负责人：小彬
	ENDPOINT_INFO(queryOut_Stock) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_stock.controller.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Out_StockPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "out_stock_id", ZH_WORDS_GETTER("out_stock.field.out_stock_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "number", ZH_WORDS_GETTER("out_stock.field.number"), 5, false);
		API_DEF_ADD_QUERY_PARAMS(String, "out_time", ZH_WORDS_GETTER("out_stock.field.out_time"), String(ZH_WORDS_GETTER("out_stock.example.out_time")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "remarks", ZH_WORDS_GETTER("out_stock.field.remarks"), String(ZH_WORDS_GETTER("out_stock.example.remarks")), false);
		//API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("out_stock.field.supplier_name"), String(ZH_WORDS_GETTER("out_stock.example.supplier_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "out_stock_person", ZH_WORDS_GETTER("out_stock.field.out_stock_person"), String(ZH_WORDS_GETTER("out_stock.example.out_stock_person")), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("out_stock.field.status"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "out_type", ZH_WORDS_GETTER("out_stock.field.out_type"), String(ZH_WORDS_GETTER("out_stock.example.out_type")), false);	
	}
	ENDPOINT(API_M_GET, "inventory-manager/query-out-stock", queryOut_Stock, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, Out_StockQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOut_Stock(userQuery, authObject->getPayload()));
	}

	//添加出库单 负责人：小彬
	ENDPOINT_INFO(addOutStock) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_stock.controller.get.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/inventory-manager/add-out_stock", addOutStock, BODY_DTO(AddOut_stock::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddOutStock(dto));
	}
	
	//获取出库单明细 负责人：小彬
	ENDPOINT_INFO(queryOut_StockDetails) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("out_stock.controller.get.summary2"), Out_StockJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("out_stock.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/inventory-manager/out-stock-details", queryOut_StockDetails, QUERY(String, id), execQueryOut_StockDetails(id, authObject->getPayload()));

private:
	// 在此添加定义
	Out_StockPageJsonVO::Wrapper execQueryOut_Stock(const Out_StockQuery::Wrapper& query, const PayloadDTO& payload); // 分页查询出库单列表 负责人:小彬
	Uint64JsonVO::Wrapper execAddOutStock(const AddOut_stock::Wrapper& dto);//添加出库单 负责人：小彬
	Out_StockJsonVO::Wrapper execQueryOut_StockDetails(const String& id, const PayloadDTO& payload); //获取出库单明细 负责人：小彬
	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //OUT_STOCKCONTROLLER_H__
