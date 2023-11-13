#pragma once
#ifndef $DELETE_STORAGE_H_
#define $DELETE_STORAGE_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "service/in_storage/InStorageService.h"
#include "ApiHelper.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * DeleteStorage��������ɾ����ⵥ �����ˣ�����
 */
class DeleteStorageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteStorageController);
	// 3 ����ӿ�
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/inventory-manager/delete-storage", deleteStorage, BODY_DTO(List<DeleteByIDStorageDTO::Wrapper>, dto), execDeleteStorage(dto, authObject->getPayload()));
	ENDPOINT_INFO(deleteStorage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deletestorage.controller.delete.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(Int64JsonVO);
		// ����������ѯ��������
	}
private:
	// �ڴ���Ӷ���
	Int64JsonVO::Wrapper execDeleteStorage(const List<DeleteByIDStorageDTO::Wrapper>& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // $FILE_BASE_UPPER$_H__