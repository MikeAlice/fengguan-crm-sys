#pragma once

#ifndef _EXPENSETYPE_CONTROLLER_
#define _EXPENSETYPE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/expensetype/ExpenseTypeDTO.h"
#include"domain/query/expensetype/ExpenseTypeQuery.h"
#include"domain/vo/expensetype/ExpenseTypeVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����֧��������
 */
class ExpenseTypeController : public oatpp::web::server::api::ApiController // �̳п�����
{
	API_ACCESS_DECLARE(ExpenseTypeController);
	
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryExpenseType) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.get.summarytype"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseTypePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("expensetype.field.name"), "li ming", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/expensetype/query-expensetype", queryExpenseType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ExpenseTypeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryExpenseType(userQuery, authObject->getPayload()));
	}
	// 3.1 ���������ӿ����� 
	ENDPOINT_INFO(addExpenseType) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/expensetype/add-expensetype", addExpenseType, BODY_DTO(ExpenseTypeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddExpenseType(dto));
	}

	// �����޸����ͽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("expensetype.modify-type.summary"), modifyType, Uint64JsonVO::Wrapper);
	// �����޸����ͽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/expensetype/modify-type", modifyType, BODY_DTO(ExpenseTypeDTO::Wrapper, dto), execModifyExpenseType(dto));

	//  ����ɾ���ӿ�����
	ENDPOINT_INFO(removeExpenseType) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("expensetype.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("expensetype.field.id"), 1, true);
	}
	//  ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/expensetype/delete-expensetype/{id}", removeExpenseType, PATH(UInt64, id), execRemoveType(id));
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryALLExpenseTree) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseTreeJsonVO);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/expensetype/query-all-expensetype", queryALLExpenseTree, API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryALLExpenseTree(authObject->getPayload()));
	}




	// 3.1 �������ṹ��ѯ�ӿ�����
	ENDPOINT_INFO(queryExpenseTree) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expensetype.get.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseTreeJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "parentid", ZH_WORDS_GETTER("expensetype.field.parentid"), "0", true);
		API_DEF_ADD_QUERY_PARAMS(String, "depth", ZH_WORDS_GETTER("expensetype.field.depth"), "0", true);
	}
	// 3.2 �������ṹ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/expensetype/query-expensetree", queryExpenseTree, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {

		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ExpenseQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryExpenseTree(Query, authObject->getPayload()));
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ExpenseTypePageJsonVO::Wrapper execQueryExpenseType(const ExpenseTypeQuery::Wrapper& query, const PayloadDTO& payload);
	//3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddExpenseType(const ExpenseTypeDTO::Wrapper& dto);
	// �޸�����
	Uint64JsonVO::Wrapper execModifyExpenseType(const ExpenseTypeDTO::Wrapper& dto);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveType(const UInt64& id);
	//��ѯȫ���ṹ��
	ExpenseTreeJsonVO::Wrapper execQueryALLExpenseTree(const PayloadDTO& payload);
	//ָ�����ڵ�Ͳ�ѯ��ȵĲ�ѯ
	ExpenseTreeJsonVO::Wrapper execQueryExpenseTree(ExpenseQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPENSETYPE_CONTROLLER_