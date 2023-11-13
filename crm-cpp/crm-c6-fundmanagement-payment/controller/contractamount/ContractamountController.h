#pragma once
#ifndef _CONTRACTAMOUNT_CONTROLLER
#define _CONTRACTAMOUNT_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/contractamount/ContractamountQuery.h"
#include "domain/dto/contractamount/ContractamountDTO.h"
#include "domain/vo/contractamount/ContractamountVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 �̳п�����
class ContractamountController : public oatpp::web::server::api::ApiController { 
	// 2 ����������������
	API_ACCESS_DECLARE(ContractamountController);
public:
	// 3.1 �����������ʽ������õĽӿ�����0
	ENDPOINT_INFO(queryContractamount) {
		// ����ӿڱ���
		//API_DEF_ADD_TITLE(u8"��ѯ��ͬ���");
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contractamount.controller.title"));
		// // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractamountJsonVO);
		// ����������ѯ��������
		// ��ͬid
		API_DEF_ADD_QUERY_PARAMS(UInt64, "contract_id", ZH_WORDS_GETTER("contractamount.field.contract_id"), 1, true);
		// ���ͣ����� OR �ؿ�
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("contractamount.field.type"), "pay", true);
	}
	// 3.2 �����������ʽ������õĽӿڴ���
	ENDPOINT(API_M_GET, "/payment/contray/query", queryContractamount, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(contractamountQuery, ContractamountQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryContractamount(contractamountQuery, authObject->getPayload()));
	}
	
private:
	ContractamountJsonVO::Wrapper execQueryContractamount(const ContractamountQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif