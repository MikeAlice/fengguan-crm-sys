#pragma once
#ifndef _BANKACCOUNT_CONTROLLER_
#define _BANKACCOUNT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/bankaccount/BankAccountQuery.h"
#include "domain/dto/bankaccount/BankAccountDTO.h"
#include "domain/vo/bankaccount/BankAccountVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class BankAccountController : public oatpp::web::server::api::ApiController  // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(BankAccountController);
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querybankaccount) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bankaccount.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BankAccountPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("bankaccount.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "card", ZH_WORDS_GETTER("bankaccount.field.card"), "123456", false);
	}
	ENDPOINT(API_M_GET, "financial-management/bankaccount/query-bankaccount", querybankaccount, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, BankAccountQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBankAccount(userQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述 
	ENDPOINT_INFO(addBankAccount) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bankaccount.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "financial-management/bankaccount/add-bankaccount", addBankAccount, BODY_DTO(BankAccountDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddBankAccount(dto));
	}
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("bankaccount.put.summary"), modifyBankAccount, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "financial-management/bankaccount/modify-bankaccount", modifyBankAccount, BODY_DTO(BankAccountDTO::Wrapper, dto), execModifyBankAccount(dto));
	
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeBankAccount) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("bankaccount.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "bank_id", ZH_WORDS_GETTER("bankaccount.field.bank_id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "financial-management/bankaccount/delete-bankaccount/{bank_id}", removeBankAccount, PATH(UInt64, bank_id), execRemoveBankAccount(bank_id));




	// 3.1 定义获取下拉列表
	ENDPOINT_INFO(getbankaccountlist) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bankaccount.getlist.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BankAccountListJsonVO);
		// 定义分页查询参数描述
	
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("bankaccount.field.name"), "", false);
		
	}
	ENDPOINT(API_M_GET, "financial-management/bankaccount/get-bankaccountlist", getbankaccountlist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, BankAccountListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetBankAccountList(userQuery, authObject->getPayload()));
	}


	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "financial-management/bankaccount/export-bankaccount", exportbankaccount, BODY_DTO(List<BankAccountExportDTO::Wrapper>, dto), execExportBankAccount(dto, authObject->getPayload()));
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/financial-manager/query-flowrecord", exportFlowrecord, FlowrecordPageQuery, execExportFlowrecord(query, authObject->getPayload()));


	ENDPOINT_INFO(exportbankaccount) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bankaccount.export.summary"));	
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}



private:
	//获取下拉列表
	BankAccountListJsonVO::Wrapper execGetBankAccountList(const BankAccountListQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示分页查询数据
	BankAccountPageJsonVO::Wrapper execQueryBankAccount(const BankAccountQuery::Wrapper& query, const PayloadDTO& payload);
	//3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddBankAccount(const BankAccountDTO::Wrapper& dto);
	//3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyBankAccount(const BankAccountDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveBankAccount(const UInt64& id);
	//导出银行账号xlsx
	StringJsonVO::Wrapper execExportBankAccount(const List<BankAccountExportDTO::Wrapper>& dto, const PayloadDTO& payload); 
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_BANKACCOUNT_CONTROLLER_