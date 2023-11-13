#include "stdafx.h"
#include "InvoiceController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/invoice/InvoiceService.h"
#include "../../domain/dto/invoice/InvoiceAddDTO.h"

InvoicePageJsonVO::Wrapper InvoiceController::execQueryInvoice(const InvoiceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	InvoiceService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InvoicePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper InvoiceController::execAddInvoice(const InvoiceAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->customer_name || !dto->contract_name || !dto->money )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->customer_name->empty() || dto->contract_name->empty() || dto->money<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	InvoiceService service;
	// ִ����������
	uint64_t id = service.saveData(dto, stoi(payload.getId()));
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}