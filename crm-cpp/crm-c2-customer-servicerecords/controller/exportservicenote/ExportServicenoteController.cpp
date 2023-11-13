#include "stdafx.h"
#include "ExportServicenoteController.h"

StringJsonVO::Wrapper ExportServicenoteController::execExportServiceNote(ExportServiceNoteQuery::Wrapper query, const PayloadDTO& payload)
{
	// ����һ��Service
	ExportServiceNoteService service;
	// ��ѯ����
	list<ServiceDetailDTO::Wrapper> result = service.listAll(query);
	// �����ݱ���ΪExcel��ʽ���ϴ����ļ�������
	String url = service.uploadExportFile(result);
	//cout << url << endl;

	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	jvo->success(url);
	return jvo;
}


