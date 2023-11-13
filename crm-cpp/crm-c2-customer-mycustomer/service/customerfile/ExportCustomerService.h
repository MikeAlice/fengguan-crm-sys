#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _EXPORTCUSTOMER_SERVICE_
#define _EXPORTCUSTOMER_SERVICE_
#include <list>
#include <time.h>
#include "domain/query/customerfile/ExportCustomerQuery.h"
#include "domain/dto/customerfile/ExportCustomerDTO.h"
#include "domain/do/customer/CustomerDO.h"
#include "dao/customerfile/ExportCustomerDAO.h"
#include "domain/vo/BaseJsonVO.h"


/**
 * �����ļ�����ʵ��
 */
class ExportCustomerService
{
public:
	/*
	* �����ˣ��Ͼ�
	* ���ܣ����ݴ�����Ա�͹�����Ա��ѯ�ͻ���Ϣ
	* @param const ExportCustomerQuery::Wrapper&  �����ͻ���ѯ����
	* @return list<ListCustomerDTO::Wrapper>  �����ͻ���Ϣ��DTO����
	*/
	list<ExportCustomerDTO::Wrapper> listAll(const ExportCustomerQuery::Wrapper& query);

	/*
	* �����ˣ��Ͼ�
	* ���ܣ����ͻ���Ϣ����ΪExcel�ļ��ϴ���FastDFS�ļ�������
	* @param list<ListCustomerDTO::Wrapper>&  �����ͻ���Ϣ��DTO����
	* @return string  �ϴ��ļ���·����Ϊ�����ʾ�ϴ�ʧ��
	*/
	String uploadExportFile(list<ExportCustomerDTO::Wrapper>& dto);
	
};

#endif // !_EXPORTCUSTOMER_SERVICE_