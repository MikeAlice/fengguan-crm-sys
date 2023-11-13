#include "stdafx.h"
#include "FinInvoiceReceController.h"
#include "../../service/FinInvoiceRece/FinInvoiceReceService.h"
//.. / .. / service / add - pay - record / AddPayRecordService.h

Uint64JsonVO::Wrapper FinInvoiceReceController::execAddFinInvoiceRece(const FinInvoiceReceDTO::Wrapper& dto)
{
	//���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��
	//�ǿ�У��
	if (!dto->contract_id || !dto->supplier_id || !dto->money || !dto->stages || !dto->name || !dto->invoice_no) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ЧֵУ��
	if (dto->contract_id < 0 || dto->supplier_id < 0 || dto->money < 0 || dto->stages < 0 || dto->name->empty() || dto->invoice_no->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��service
	FinInvoiceReceService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	return jvo;
}
