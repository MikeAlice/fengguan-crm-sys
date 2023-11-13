#pragma once
#ifndef OUTBOUNDDETAILCONTROLLER_H__
#define OUTBOUNDDETAILCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/outbounddetail/OutboundDetailsPageJsonVO.h"
#include "domain/query/outbounddetail/OutboundDetailQuery.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * OutboundDetail控制器：操作出库明细
 */
class OutboundDetailController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(OutboundDetailController);
	// 3 定义接口
public:
	//分页获取出库明细列表 负责人：是个天才
	ENDPOINT_INFO(queryOutboundDetail) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("outbounddetail.controller.query.summary"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		//定义相应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OutboundDetailQuery);
		//定义分页参数
		API_DEF_ADD_PAGE_PARAMS();
		//定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String,"SKUname",ZH_WORDS_GETTER("outbounddetail.example.skuname"),"SKUname",false);
		API_DEF_ADD_QUERY_PARAMS(String,"supplierName",ZH_WORDS_GETTER("outbounddetail.example.supplierName"),"supplierName",false);
		API_DEF_ADD_QUERY_PARAMS(String,"contactAdd",ZH_WORDS_GETTER("outbounddetail.example.contactAdd"),"contactAdd",false);
	}

	//定义分页查询接口
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET,"/inventory-manager/query-outbound-detail",
		queryOutboundDetail,OutboundDetailQuery,execQueryOutboundDetail(query,authObject->getPayload()));


	// 导出出库明细 负责人：是个天才
	ENDPOINT_INFO(exportOutboundDetails) {
	// 定义接口标题
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("outbounddetail.controller.export.summary"));	//目录名.controller.方法名.summary
	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	API_DEF_ADD_AUTH();
	// 定义响应参数格式	
	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/inventory-manager/export-outbound-details", 
		exportOutboundDetails, BODY_DTO(List<ExportOutboundDetailsDTO::Wrapper>, dto), execExportOutboundDetails(dto, authObject->getPayload()));

private:
	// 在此添加定义
	OutboundDetailPageJsonVO::Wrapper execQueryOutboundDetail(const OutboundDetailQuery::Wrapper query,const PayloadDTO& payload);						//查询出库明细    负责人：是个天才
	StringJsonVO::Wrapper execExportOutboundDetails(const List<ExportOutboundDetailsDTO::Wrapper> outboundDetailQuery, const PayloadDTO& payload);		// 导出入库明细	  负责人：是个天才
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // OUTBOUNDDETAILCONTROLLER_H__
