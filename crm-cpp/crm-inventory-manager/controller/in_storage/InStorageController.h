#pragma once
#ifndef INSTORAGECONTROLLER_H__
#define INSTORAGECONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "domain/vo/in_storage/InStorageJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * InStorage��������
 * �����ˣ�CC
 */
class InStorageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(InStorageController);
	// 3 ����ӿ�
public:

	// ��ȡ��ⵥ�б���ҳ+�����������ˣ�CC
	ENDPOINT_INFO(queryInStorage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("instorage.controller.get.query-instorage"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InStoragePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "title", ZH_WORDS_GETTER("instorage.field.title"), "default", false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "store_id", ZH_WORDS_GETTER("instorage.field.store_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "status", ZH_WORDS_GETTER("instorage.field.status"), 1, false);
	}
	ENDPOINT(API_M_GET, "/inventory-manager/query-instorage", queryInStorage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, InStorageQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryInStorage(userQuery, authObject->getPayload()));
	}

	// ��ѯ�����ϸ  �����ˣ�CC
	ENDPOINT_INFO(queryInStorageDetails) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("instorage.controller.get.query-instorage_details"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InStorageJsonVO);
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("instorage.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/inventory-manager/query-instorage_details/{id}", queryInStorageDetails, PATH(UInt64, id), execQueryInStorageDetails(id));


	// �����ⵥ  �����ˣ�CC
	ENDPOINT_INFO(addInStorage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("instorage.controller.post.add-instorage"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/inventory-manager/add-instorage", addInStorage, BODY_DTO(InStorageBaseDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddInStorage(dto, authObject->getPayload()));
	}

private:
	InStoragePageJsonVO::Wrapper execQueryInStorage(const InStorageQuery::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddInStorage(const InStorageBaseDTO::Wrapper& dto, const PayloadDTO& payload);
	InStorageJsonVO::Wrapper execQueryInStorageDetails(const UInt64& id);

};



// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // INSTORAGECONTROLLER_H__