#include "stdafx.h"
#include "Out_stockController.h"
#include "service/out_stock/Out_stockService.h"


Out_StockPageJsonVO::Wrapper Out_StockController::execQueryOut_Stock(const Out_StockQuery::Wrapper& query, const PayloadDTO& payload)
{
	Out_stockService service;
	auto dto = service.listAll(query);
	auto vo = Out_StockPageJsonVO::createShared();
	vo->success(dto);
	return vo;
}

Uint64JsonVO::Wrapper Out_StockController::execAddOutStock(const AddOut_stock::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->store_name || !dto->number || !dto->status)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->store_name->empty() || dto->number < 0 || dto->status < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	Out_stockService service;
	// ִ����������
	uint64_t id = service.addData(dto);
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

Out_StockJsonVO::Wrapper Out_StockController::execQueryOut_StockDetails(const String& id, const PayloadDTO& payload)
{
	Out_stockService service;
	auto dto = service.queryone(id);
	auto vo = Out_StockJsonVO::createShared();
	vo->success(dto);
	return vo;
}



