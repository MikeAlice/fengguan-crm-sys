#include "stdafx.h"
#include "TraceController.h"
#include "../../service/trace/TraceService.h"
#include <iostream>

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

//����ģ��
BooleanJsonVO::Wrapper TraceController::execAddTrace(const AddTraceDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = BooleanJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->customer_id || !dto->linkman_id || !dto->AC || !dto->CC || !dto->SOid || !dto->FMethodid || !dto->FTime || !dto->CContent || !dto->CStageid || !dto->SOpportunity || !dto->NTime)
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->customer_id < 0 || dto->linkman_id < 0 || dto->FMethodid < 0 || dto->SOid < 0 || dto->AC->empty() || dto->CC->empty() || dto->FTime->empty() || dto->CContent->empty() || dto->CStageid>0 || dto->SOpportunity->empty() || dto->NTime->empty())
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TraceService service;
	// ִ����������
	Int32 customer_id = service.saveData(dto);

	if (customer_id >= 0) {
		return jvo;
	}
	else
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
}

//�޸�ģ��
BooleanJsonVO::Wrapper TraceController::execModifyTrace(const ModifyTraceDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = BooleanJsonVO::createShared();
	// ����У��
	if (!dto->customer_id || !dto->linkman_id || !dto->SOid || !dto->FMethodid || !dto->FTime || !dto->CContent || !dto->CStageid || !dto->NTime) {
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TraceService service;
	// ִ�������޸�
	if (service.updateData(dto))
		return jvo;
	else
	{
		jvo->init(bool(-1), RS_PARAMS_INVALID);
		return jvo;
	}
}

//��ҳ��ѯģ��
TracePageJsonVO::Wrapper TraceController::execQueryGet(const TraceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	TraceService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = TracePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return TracePageJsonVO::createShared();
}
//ִ��ɾ�����ټ�¼
Uint64JsonVO::Wrapper TraceController::execTraceDelete(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��Service
	TraceService service;
	//ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper TraceController::execListTraceDelete(const ListTraceDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	auto cur = dto->listtrace_id.getPtr();
	if (cur->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto i = cur->begin(); i != cur->end(); i++) {
		if (!*i || *i < 0) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	TraceService service;
	//ִ������ɾ��
	for (auto i = cur->begin(); i !=cur->end(); i++)
	{
		auto id = *i;
		if (service.removeData(id.getValue(0))) {
				jvo->success(id);
			}
		else
		{
			jvo->fail(id);
		}
	}
	//��Ӧ���
	return jvo;
}

//ִ�����ظ��ټ�¼�ļ�
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TraceController::execDownloadFile()
{
	TraceService service;
	service.exportTracefile();
	// ��ȡ�ļ�
	auto fstring = String::loadFromFile("./public/excel/traceFile.xlsx");

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=traceFile.xlsx");

	// Ӱ��ɹ����
	return response;
}