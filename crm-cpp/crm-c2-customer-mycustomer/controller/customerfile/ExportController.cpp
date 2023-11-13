/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#include "ExportController.h"

StringJsonVO::Wrapper ExportController::execExportCustomer(ExportCustomerQuery::Wrapper query, const PayloadDTO& playload)
{
	// ����һ��Service
	ExportCustomerService service;
	// ��ѯ����
	list<ExportCustomerDTO::Wrapper> data = service.listAll(query);
	// �����ݱ���ΪExcel��ʽ���ϴ����ļ�������
	String result= service.uploadExportFile(data);
	//cout << url << endl;

	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();

	if (result == "upload fail") 
	{
		jvo->init(result, RS_FAIL);
	}
	else 
	{
		jvo->success(result);
	}
	return jvo;
}


