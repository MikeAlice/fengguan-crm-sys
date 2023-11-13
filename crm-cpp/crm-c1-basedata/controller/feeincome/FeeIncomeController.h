#pragma once
#ifndef _FeeIncome_CONTROLLER_
#define _FeeIncome_CONTROLLER_
#include "ApiHelper.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/feeincome/FeeIncomeQuery.h"
#include "domain/dto/feeincome/FeeIncomeDTO.h"
#include "domain/vo/feeincome/FeeIncomeTreeVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class FeeIncomeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(FeeIncomeController);
	// 3 ����ӿ�
public:
	// 3.1 �����ȡ�����б�(��ҳ + ����)�ӿ�����
	ENDPOINT_INFO(queryFeeIncome) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.query-type.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeIncomePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("FeeIncomeType.field.name"), "����", false);
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "parentID", ZH_WORDS_GETTER("FinIncomeType.field.parentID"), "1", false);
	}
	// 3.1 ��ȡ�����б�(��ҳ + ����)
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, OIC_PRFIX("/query-type"), queryFinIncomeType, BODY_DTO(FinIncomeTypeQuery::Wrapper, query), execQueryType(query, authObject->getPayload()));
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET,"/feeincome/query-feeincome", queryFeeIncome, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, FeeIncomeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryType(userQuery, authObject->getPayload()));
	}
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryALLFeeIncome) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeIncomeTreeJsonVO);
	
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/feeincome/query-all-feeincome", queryALLFeeIncome, API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryALLFeeIncome(authObject->getPayload()));
	}
	// 3.1 ���������ӿ����� 
	ENDPOINT_INFO(addFeeIncome) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/feeincome/add-feeincome", addFeeIncome, BODY_DTO(FeeIncomeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddFeeIncome(dto));
	}
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("feeincome.put.summary"), modifyFeeIncome, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/feeincome/modify-feeincome", modifyFeeIncome, BODY_DTO(FeeIncomeDTO::Wrapper, dto), execModifyFeeIncome(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeFeeIncome) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("feeincome.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("feeincome.field.id"), 1, true);
	}
	//  ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/feeincome/delete-feeincome/{id}", removeFeeIncome, PATH(UInt64, id), execRemoveFeeIncome(id));




	// 3.1 �������ṹ��ѯ�ӿ�����
	ENDPOINT_INFO(queryALLFeeIncomeTree) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("feeincome.get.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeIncomeTreeJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "parentid", ZH_WORDS_GETTER("feeincome.field.parentid"), "0", true);
		API_DEF_ADD_QUERY_PARAMS(String, "depth", ZH_WORDS_GETTER("feeincome.field.depth"), "0", true);
	}
	// 3.2 �������ṹ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/feeincome/query-all-feeincomeTree", queryALLFeeIncomeTree, QUERIES(QueryParams, queryParams),API_HANDLER_AUTH_PARAME) {
	
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, FeeIncomeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryALLFeeIncomeTree(Query, authObject->getPayload()));
	}

	
private:
	FeeIncomePageJsonVO::Wrapper execQueryType(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload);
	FeeIncomeTreeJsonVO::Wrapper execQueryALLFeeIncome(const PayloadDTO& payload);
	FeeIncomeTreeJsonVO::Wrapper execQueryALLFeeIncomeTree(FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload);
	//// 3.3 ��ʾ��ҳ��ѯ����
	//FeeIncomePageJsonVO::Wrapper execQueryFeeIncome(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload);
	//3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddFeeIncome(const FeeIncomeDTO::Wrapper& dto);
	//3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyFeeIncome(const FeeIncomeDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveFeeIncome(const UInt64& id);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_