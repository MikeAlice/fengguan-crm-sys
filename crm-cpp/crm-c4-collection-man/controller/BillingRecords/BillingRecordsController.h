#ifndef _BillingRecordsController_H_
#define _BillingRecordsController_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"
#include"Macros.h"
#include "domain/GlobalInclude.h"
//#include"domain/vo/ExportBillingRecordsJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

// 定义前缀
#ifndef OIC_PRFIX
#define OIC_PRFIX(_app_) "/collection-man" _app_
#endif

class BillingRecordsController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(BillingRecordsController);
public:
	// 定义删除接口描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("BillingRecords.delete.summary"), DelBillingRecords, Uint64JsonVO::Wrapper);

	//  定义删除接口处理
	API_HANDLER_ENDPOINT(API_M_DEL, OIC_PRFIX("/BillingRecords/DelBillingRecords"), DelBillingRecords, BODY_DTO(oatpp::List<oatpp::UInt64>, dto), execDelBillingRecords(dto));


	//定义一个文件导出接口描述
	ENDPOINT_INFO(ExportBillingRecords) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("BillingRecords.export.summary"), Void);
	}

	// 定义文件导出接口
	ENDPOINT(API_M_POST, "/BillingRecords/ExportBillingRecords", ExportBillingRecords, BODY_DTO(oatpp::List<oatpp::UInt64>, dto)) {
		return  execExportBillingRecords(dto);
	}
	



	/*
	//定义一个文件导出接口描述
	ENDPOINT_INFO(ExportBillingRecords) {
		info->summary = ZH_WORDS_GETTER("BillingRecords.export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}

	// 定义文件导出接口
	ENDPOINT(API_M_POST, OIC_PRFIX("/BillingRecords/ExportBillingRecords"), ExportBillingRecords, BODY_DTO(oatpp::List<oatpp::UInt64>, dto)) {
		return createDtoResponse(Status::CODE_200, execExportBillingRecords(dto));
	}
	*/
private: // 定义接口执行函数

	Uint64JsonVO::Wrapper execDelBillingRecords(const oatpp::List<oatpp::UInt64>& dto);

	//StringJsonVO::Wrapper execExportBillingRecords(const oatpp::List<oatpp::UInt64>& dto);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execExportBillingRecords(const oatpp::List<oatpp::UInt64>& dto);
};


#include OATPP_CODEGEN_END(ApiController)
#endif