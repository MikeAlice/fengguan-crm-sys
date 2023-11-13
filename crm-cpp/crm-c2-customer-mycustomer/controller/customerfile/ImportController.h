#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _IMPORT_CONTROLLER_
#define _IMPORT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/customerfile/ImportResultVO.h"
#include "ApiHelper.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����ͻ�������
 */
class ImportController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ImportController);
	// 3 ����ӿ�
public:
	// �����ϴ����������ļ��ӿ�	�����ˣ��Ͼ�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/upload-customer-file", uploadCustomerFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadCustomerFileOne(request));
	// �����ϴ����������ļ��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("customer.controller.upload"), uploadCustomerFile, StringJsonVO::Wrapper);


	// ���嵼��ͻ��ӿ�	�����ˣ��Ͼ�
	//API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/import-customer", importCustomer, BODY_DTO(FilePathDTO::Wrapper, dto), execImportCustomer(dto, authObject->getPayload()));
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-mycustomer/import-customer", importCustomer, BODY_STRING(String, fileName), execImportCustomer(fileName, authObject->getPayload()));
	// ���嵼��ͻ��ӿ�����
	ENDPOINT_INFO(importCustomer) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.import"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportResultJsonVO);
	}

private:
	/*�����ˣ� �Ͼ�
	* ��������������Excel�ļ�����ʱ���浽���أ��ٽ�·�����ͻ�ǰ��
	* @param�� request  ������������
	* @return�� StringJsonVO  �ɹ������ļ�·����ʧ���򷵻�ʧ��ԭ��
	*/
	StringJsonVO::Wrapper execUploadCustomerFileOne(std::shared_ptr<IncomingRequest> request);

	/*�����ˣ� �Ͼ�
	* ������������Excel�ļ���ȡ���ڴ棬Ȼ��־û������ݿ�
	* @param�� filepath   �ļ�·��
	* @return�� ImportResultJsonVO  ���سɹ�������ʧ������
	*/
	ImportResultJsonVO::Wrapper execImportCustomer(String fileName, const PayloadDTO& playload);

};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _IMPORT_CONTROLLER_
