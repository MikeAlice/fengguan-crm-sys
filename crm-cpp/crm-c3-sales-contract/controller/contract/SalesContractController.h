#ifndef _SALESCONTRACTCONTROLLER_H_
#define _SALESCONTRACTCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/contractindex/AddSalesContractDTO.h"
#include "service/contractindex/AddDeleteSalesContractService.h"
#include "domain/dto/getindex/SalesContractDTO.h"
#include "domain/dto/getindex/SalesContractDetailDTO.h"
#include "domain/vo/getindex/SalesContractVO.h"
#include "domain/query/getindex/SalesContractQuery.h"
#include "domain/dto/getindex/SalesContractListDTO.h"
#include "domain/vo/getindex/SalesContractListVO.h"
#include "domain/vo/getindex/ContractGoodsVO.h"
#include "domain/query/getindex/ContractGoodsQuery.h"
#include "service/getindex/ContractGoodsService.h"
#include "domain/dto/getindex/GetSalContListDTO.h"
#include "domain/query/getindex/GetSalContListQuery.h"
#include "domain/vo/getindex/GetSalContListVO.h"
#include "service/getindex/GetSalContListService.h"
#include "service/SalesContract/SalesContractListService.h"
#include "domain/dto/getindex/GetSalesContractNoDTO.h"
#include "domain/vo/getindex/GetSalesContractNoVO.h"
#include "service/getindex/GetSalesNoService.h"
#include "domain/dto/salContract/ModifyDeliverStatusDTO.h"
#include "domain/dto/salContract/ModifySalContractBasicInfoDTO.h"
#include "domain/dto/salContractList/InputListDTO.h"
#include "service/salContract/SalContractService.h"
#include "service/salContractList/SalContractListService.h"
#include "domain/dto/contractindex/DeleteDetailsDTO.h"
#include "service/getindex/DeleteDetailsService.h"
#include "domain/dto/contractindex/GenerateOutboundOrderDTO.h"	
#include "domain/query/ExportSalesQUERY.h"
#include "domain/dto/ExportSalesDTO.h"
#include "domain/vo/ExportSalesVO.h"
#include "service/ExportSaleService.h"
#include "domain/query/contractindex/OutStockQuery.h"
#include "domain/dto/contractindex/OutStockDTO.h"
#include "service/contractindex/AddOutStockService.h"

#include "domain/vo/contractindex/SendingFileVO.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 销售合同控制器
 */
class SalesContractController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 控制器访问入口
	API_ACCESS_DECLARE(SalesContractController);

public:

	//获取销售合同列表数据（用于输入表单下拉列表）长风
	ENDPOINT_INFO(querySalContList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.controller.querySalContList"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetSalContListJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "title", ZH_WORDS_GETTER("getindex.field.title"), "lt", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "customer_id", ZH_WORDS_GETTER("getindex.field.customer_id"), 123, true);

	}
	ENDPOINT(API_M_GET, "/sales-contract/sales-cont-list", querySalContList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetSalContListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySalContList(userQuery, authObject->getPayload()));
	}


	//获取销售合同唯一编号 长风
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales-contract/get-salesNo/{contract_id}", queryContractNo, PATH(UInt64, contract_id), execQueryContractNo(contract_id));
	ENDPOINT_INFO(queryContractNo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.controller.queryContractNo"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetSalesContractNoJsonVO);
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "contract_id", ZH_WORDS_GETTER("getindex.field.contract_id"), 123, true);
	}


	//获取销售合同列表（分页+条件）    负责人：归途
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/sales-contract/get-sales-contract-list", querySalesContractList, SalesContractPageQuery::Wrapper, execQuerySalConListGT(query));	//定义获取获取销售合同列表接口描述
	ENDPOINT_INFO(querySalesContractList) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.controller.querySalesContractList"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SalesContractListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("SalesContract.field.start_date"), "1888-1-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("SalesContract.field.end_date"), "9999-12-31", false);
	}


	//获取合同详情 鼻子大的猪
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales-contract/get-sales-contract-detail-list", querySalConDetList, BODY_DTO(SalesContractDetailDTO::Wrapper, dto), execQuerySalConDetList(dto, authObject->getPayload()));
	ENDPOINT_INFO(querySalConDetList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.controller.querySalConDetList"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SalesContractDetailJsonVO);
		// 定义id接口
		API_DEF_ADD_QUERY_PARAMS(Int64, "contract_id", ZH_WORDS_GETTER("SalesContract.field.contract_id"), , false);
	}


    //获取合同清单 原味的原味包
	ENDPOINT_INFO(queryContractGoods) {
		info->summary = ZH_WORDS_GETTER("contract.controller.queryContractGoods");
		info->addSecurityRequirement("bearer_auth");
		info->addResponse<ContractGoodsPageJsonVO::Wrapper>(Status::CODE_200, "application/json"); // 响应值暂时设定为分页形式

		info->queryParams.add<String>("contract_no").description = ZH_WORDS_GETTER("contractindex.field.contract_no");
		info->queryParams["contract_no"].required = true; // 必要参数
		info->queryParams["contract_no"].addExample("default", String("2106021686"));
	}
	ENDPOINT(API_M_GET, "/sales-contract/get-contract-goods", queryContractGoods, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// API_HANDLER_QUERY_PARAM(转换后变量名称，查询数据对象类型，QueryParams变量名)
		// 将传入的一系列变量（这里只有String类型的contract_no）转换成ContractGoodsQuery类型的变量userQuery
		API_HANDLER_QUERY_PARAM(userQuery, ContractGoodsQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryContractGoods(userQuery, authObject->getPayload()));
	}


	//添加销售合同 原味的原味包
	ENDPOINT_INFO(addSalesContract) {
		info->summary = ZH_WORDS_GETTER("contract.controller.addSalesContract");
		info->addSecurityRequirement("bearer_auth");
		info->addResponse<Uint64JsonVO::Wrapper>(Status::CODE_200, "application/json");
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-contract/add-contract", addSalesContract, BODY_DTO(AddSalesContractDTO::Wrapper, dto), execAddSalesContract(dto));


	//删除销售合同 原味的原味包
	ENDPOINT_INFO(deleteSalesContract) {
		info->summary = ZH_WORDS_GETTER("contract.controller.deleteSalesContract");
		info->addSecurityRequirement("bearer_auth");
		info->addResponse<Uint64JsonVO::Wrapper>(Status::CODE_200, "application/json"); // 响应值有待确定
		info->pathParams.add<String>("contract_no").description = ZH_WORDS_GETTER("contractindex.field.contract_no");
		info->pathParams["contract_no"].required = true; // 必要参数
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales-contract/delete-contract/{contract_no}", deleteSalesContract, PATH(String, contract_no), execDeleteSalesContract(contract_no));


	//修改销售合同基础信息 咫尺之书
	ENDPOINT_INFO(modifyBasicInfo) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contract.controller.modifyBasicInfo"), BooleanJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "contract_id", ZH_WORDS_GETTER("sal-contract.field.contract-id"), 1, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "contract_no", ZH_WORDS_GETTER("sal-contract.field.contract-no"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "title", ZH_WORDS_GETTER("sal-contract.field.title"), ZH_WORDS_GETTER("sal-contract.field.title"), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "customer_id", ZH_WORDS_GETTER("sal-contract.field.customer-id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "linkman_id", ZH_WORDS_GETTER("sal-contract.field.linkman-id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("sal-contract.field.start-date"), "2021-06-02", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("sal-contract.field.end-date"), "2023-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "money", ZH_WORDS_GETTER("sal-contract.field.money"), 2000.00, false);
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("sal-contract.field.intro"), ZH_WORDS_GETTER("sal-contract.field.intro"), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "our_user_id", ZH_WORDS_GETTER("sal-contract.field.our-user-id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-contract/modify-basic-info", modifyBasicInfo, BODY_DTO(ModifySalContractBasicInfoDTO::Wrapper, dto), execModifyBasicInfo(dto, authObject->getPayload()));


	//修改交付状态 咫尺之书
	ENDPOINT_INFO(modifyDeliverStatus) {
		// 定义接口通用信息
		API_DEF_ADD_QUERY_PARAMS(Int32, "contract_id", ZH_WORDS_GETTER("contract.controller.modifyDeliverStatus"), 1, true);
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sal-contract.modify-deliver-status.summary"), BooleanJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "deliver_status", ZH_WORDS_GETTER("sal-contract.field.deliver-status"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-contract/modify-deliver-status", modifyDeliverStatus, BODY_DTO(ModifyDeliverStatusDTO::Wrapper, dto), execModifyDeliverStatus(dto, authObject->getPayload()));


	//录入明细 咫尺之书
	ENDPOINT_INFO(inputList) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contract.controller.inputList"), BooleanJsonVO::Wrapper);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "contract_id", ZH_WORDS_GETTER("sal-contract.field.contract-id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("sal-contract-list.field.goods-name"), ZH_WORDS_GETTER("sal-contract-list.field.goods-name"), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "goods_id", ZH_WORDS_GETTER("sal-contract-list.field.goods-id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "sku_id", ZH_WORDS_GETTER("sal-contract-list.field.sku-id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "sku_name", ZH_WORDS_GETTER("sal-contract-list.field.sku-name"), ZH_WORDS_GETTER("sal-contract-list.field.sku-name"), false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "sale_price", ZH_WORDS_GETTER("sal-contract-list.field.sale-price"), 200.00, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "num", ZH_WORDS_GETTER("sal-contract-list.field.num"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "goods_money", ZH_WORDS_GETTER("sal-contract-list.field.goods-money"), 2000.00, false);
		API_DEF_ADD_QUERY_PARAMS(String, "remarks", ZH_WORDS_GETTER("sal-contract-list.field.remarks"), ZH_WORDS_GETTER("sal-contract-list.field.remarks"), false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-contract/input-list", inputList, BODY_DTO(InputListDTO::Wrapper, dto), execInputList(dto, authObject->getPayload()));


	//删除明细 长风
	ENDPOINT_INFO(deleteDetails) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("contract.controller.deleteDetails"), Uint64JsonVO::Wrapper);
		API_DEF_ADD_PATH_PARAMS(UInt64, "list_id", ZH_WORDS_GETTER("contractindex.field.list_id"), 123, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales-contract/delete-contract-details/{list_id}", deleteDetails, PATH(UInt64, list_id), execDeleteDetailsId(list_id));


    //添加合同附件 鼻子大的猪
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("contract.controller.uploadFile"), uploadFile, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "/sales-contract/contractfile/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));


	//生成出库单 gugu
	ENDPOINT_INFO(addOutStock) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_stock.controller.get.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/sales-contract/add-out_stock", addOutStock, BODY_DTO(OutStockDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddOutStock(dto, authObject->getPayload()));
	}


	//导出销售合同 科文
	ENDPOINT_INFO(querySalesContract) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.controller.querySalesContract"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportSalesJsonVO);
		// 参数
		API_DEF_ADD_QUERY_PARAMS(UInt64, "contractId", ZH_WORDS_GETTER("SalesContract.field.contract_id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "customer_id", ZH_WORDS_GETTER("SalesContract.field.customer_id"), 1, true);

	}
	ENDPOINT(API_M_GET, "/sales-contract/ExportSales", querySalesContract, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExportSalesQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryExportSales(userQuery, authObject->getPayload()));
	}

private:
	//获取销售合同列表数据（用于输入表单下拉列表）长风
	GetSalContListJsonVO::Wrapper execQuerySalContList(const GetSalContListQuery::Wrapper& query, const PayloadDTO& payload);
	//获取销售合同唯一编号 长风
	GetSalesContractNoJsonVO::Wrapper execQueryContractNo(const UInt64& contract_id);
	//获取销售合同列表 归途   
	SalesContractListPageJsonVO::Wrapper execQuerySalConListGT(const SalesContractPageQuery::Wrapper& query);
	//获取合同详情 鼻子大的猪
	BooleanJsonVO::Wrapper execQuerySalConDetList(const SalesContractDetailDTO::Wrapper& dto, const PayloadDTO& payload);
	//获取合同清单 原味的原味包
	ContractGoodsPageJsonVO::Wrapper execQueryContractGoods(const ContractGoodsQuery::Wrapper& query, const PayloadDTO& payload);
	//添加销售合同 原味的原味包
	Uint64JsonVO::Wrapper execAddSalesContract(const AddSalesContractDTO::Wrapper& dto);
	//删除销售合同 原味的原味包
	Uint64JsonVO::Wrapper execDeleteSalesContract(const String& contract_no);
	//修改销售合同基础信息 咫尺之书
	BooleanJsonVO::Wrapper execModifyBasicInfo(const ModifySalContractBasicInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	//修改交付状态 咫尺之书
	BooleanJsonVO::Wrapper execModifyDeliverStatus(const ModifyDeliverStatusDTO::Wrapper& dto, const PayloadDTO& payload);
	//录入明细 咫尺之书
	BooleanJsonVO::Wrapper execInputList(const InputListDTO::Wrapper& dto, const PayloadDTO& payload);
	//删除明细 长风
	Uint64JsonVO::Wrapper execDeleteDetailsId(const UInt64& list_id);
	//添加合同附件 鼻子大的猪
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	//生成出库单 gugu
	Int64JsonVO::Wrapper execAddOutStock(const OutStockDTO::Wrapper& dto, const PayloadDTO& payload);//添加出库单 
	//导出销售合同 科文
	StringJsonVO::Wrapper execQueryExportSales(const ExportSalesQuery::Wrapper& query, const PayloadDTO& payload);



};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif