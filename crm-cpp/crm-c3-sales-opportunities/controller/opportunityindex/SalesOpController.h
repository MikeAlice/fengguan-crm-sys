#pragma once
#ifndef _SALESOPCONTROLLER_H_
#define _SALESOPCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/salesopportunityinfo/DeleteSalesOpDTO.h"
#include "domain/dto/salesopportunityinfo/UpdateSalesOpDTO.h"
#include "domain/dto/salesopportunityinfo/InsertSalesOpDTO.h"
#include "domain/query/salesopportunity/SalesOpportunityQuery.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* 销售机会控制函数
*/

class SalesOpController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(SalesOpController);
public:

	//插入销售机会
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales-opportunities/insert-sales-opportunity", addSalesOp, BODY_DTO(InsertSalesOpDTO::Wrapper, dto), execAddSalesOp(dto, authObject->getPayload()));
	// 定义修改联系人接口描述
	ENDPOINT_INFO(addSalesOp) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.addSalesOp"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义销售机会id
		API_DEF_ADD_QUERY_PARAMS(Int32, "chance_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"), 1, false);
		// 定义销售机会主题
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("opportunities.field.cst_chance.name"), , false);
		// 定义销售机会客户id
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"), , false);
		// 定义销售机会联系人id
		API_DEF_ADD_QUERY_PARAMS(String, "linkman_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_id"), , false);
		// 定义销售机会发现日期
		API_DEF_ADD_QUERY_PARAMS(String, "find_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"), , false);
		// 定义销售机会预计签单时间
		API_DEF_ADD_QUERY_PARAMS(String, "bill_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"), , false);
		// 定义销售机会谈判状态
		API_DEF_ADD_QUERY_PARAMS(UInt32, "salestage", ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"), , false);
		// 定义销售机会预计金额
		API_DEF_ADD_QUERY_PARAMS(Float64, "money", ZH_WORDS_GETTER("opportunities.field.cst_chance.money"), , false);
		// 定义销售机会成功率
		API_DEF_ADD_QUERY_PARAMS(UInt32, "success_rate", ZH_WORDS_GETTER("opportunities.field.cst_chance.success_rate"), , false);
		// 定义销售机会状态
		API_DEF_ADD_QUERY_PARAMS(UInt32, "status", ZH_WORDS_GETTER("opportunities.field.cst_chance.status"), , false);
		// 定义销售机会创建人
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_user_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.create_user_id"), , false);
		// 定义userID
		API_DEF_ADD_QUERY_PARAMS(UInt32, "userID", ZH_WORDS_GETTER("opportunities.field.cst_chance.userID"), , false);
		// 定义intro
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("opportunities.field.cst_chance.intro"), , false);
		// 定义create_id
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.create_id"), , false);
		// 定义create_time
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("opportunities.field.cst_chance.create_time"), , false);
	}

	//修改销售机会
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sales-opportunities/update-sales-opportunity", modifySalesOp, BODY_DTO(UpdateSalesOpDTO::Wrapper, dto), execModifySalesOp(dto, authObject->getPayload()));
	// 定义修改联系人接口描述
	ENDPOINT_INFO(modifySalesOp) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.modifySalesOp"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义销售机会id
		 API_DEF_ADD_QUERY_PARAMS(Int32, "chance_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"), 1, false);
		// 定义销售机会主题
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("opportunities.field.cst_chance.name"), , false);
		// 定义销售机会客户id
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"), , false);
		// 定义销售机会联系人id
		API_DEF_ADD_QUERY_PARAMS(String, "linkman_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_id"), , false);
		// 定义销售机会发现日期
		API_DEF_ADD_QUERY_PARAMS(String, "find_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"), , false);
		// 定义销售机会预计签单时间
		API_DEF_ADD_QUERY_PARAMS(String, "bill_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"), , false);
		// 定义销售机会谈判状态
		API_DEF_ADD_QUERY_PARAMS(UInt32, "salestage", ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"), , false);
		// 定义销售机会预计金额
		API_DEF_ADD_QUERY_PARAMS(Float64, "money", ZH_WORDS_GETTER("opportunities.field.cst_chance.money"), , false);
		// 定义销售机会成功率
		API_DEF_ADD_QUERY_PARAMS(UInt32, "success_rate", ZH_WORDS_GETTER("opportunities.field.cst_chance.success_rate"), , false);
		// 定义销售机会状态
		API_DEF_ADD_QUERY_PARAMS(UInt32, "status", ZH_WORDS_GETTER("opportunities.field.cst_chance.status"), , false);
		// 定义销售机会创建人
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_user_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.create_user_id"), , false);
		// 定义userID
		API_DEF_ADD_QUERY_PARAMS(UInt32, "userID", ZH_WORDS_GETTER("opportunities.field.cst_chance.userID"), , false);
		// 定义intro
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("opportunities.field.cst_chance.intro"), , false);
		// 定义create_id
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.create_id"), , false);
		// 定义create_time
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("opportunities.field.cst_chance.create_time"), , false);
	}

	// 删除销售机会
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales-opportunities/delete-sales-opportunity", removeSalesOp, BODY_DTO(DeleteSalesOpDTO::Wrapper, dto), execRemoveSalesOp(dto, authObject->getPayload()));
	ENDPOINT_INFO(removeSalesOp) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.removeSalesOp"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//定义请求参数
		API_DEF_ADD_QUERY_PARAMS(Int32, "chance_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"), 1, true);
	}

private:
	Uint64JsonVO::Wrapper execRemoveSalesOp(const DeleteSalesOpDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifySalesOp(const UpdateSalesOpDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddSalesOp(const InsertSalesOpDTO::Wrapper& dto, const PayloadDTO& payload);
};


#endif /* _SALESOPCONTROLLER_H_ */