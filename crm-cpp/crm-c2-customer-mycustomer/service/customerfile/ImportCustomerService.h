#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _IMPORTCUSTOMER_SERVICE_
#define _IMPORTCUSTOMER_SERVICE_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/customerfile/ImportResultDTO.h"
#include "ApiHelper.h"

/**
 * �����ļ�����ʵ��
 */
class ImportCustomerService
{
public:
	/*
	* �����ˣ��Ͼ�
	* ���ܣ������ϴ��Ŀͻ���Ϣ�ļ�
	* @param request  �ͻ��ϴ��ļ�����
	* @return String	�ɹ� �����ϴ��ļ�������ҵ��������ϵ�·��
	*					ʧ�� ���ؿ��ַ���
	*/
	String uploadImportFile(std::shared_ptr<oatpp::web::protocol::http::incoming::Request>& request);

	/*
	* �����ˣ��Ͼ�
	* ���ܣ������ϴ��ļ��еĿͻ���Ϣ���־û������ݿ�
	* @param fileName  �����ļ��ڱ��ش��̵�·��
	* @return ImportResultDTO  ���سɹ���ʧ����Ϣ
	*/
	ImportResultDTO::Wrapper importCustomer(String& fileName);

};

#endif // !_EXPORTCUSTOMER_SERVICE_