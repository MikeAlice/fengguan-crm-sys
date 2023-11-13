#include "stdafx.h"
#include "ExpenseTypeController.h"
#include <service/expensetype/ExpenseTypeService.h>

//ExpenseTypePageJsonVO::Wrapper ExpenseTypeController::execQueryExpenseType(const ExpenseTypeQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	return ExpenseTypePageJsonVO::createShared();
//}
ExpenseTypePageJsonVO::Wrapper ExpenseTypeController::execQueryExpenseType(const ExpenseTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ExpenseTypeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ExpenseTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


// 3.3 ��ʾ��������
Uint64JsonVO::Wrapper ExpenseTypeController::execAddExpenseType(const ExpenseTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//// �ǿ�У��
	//if (!dto->card || !dto->name || !dto->holders ||!dto->address||!dto->sort)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ��ЧֵУ��
	//if (dto->card < 0 || dto->name->empty() || dto->address->empty()|| dto->holders->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	// ����һ��Service
	ExpenseTypeService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
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
// 3.3 ��ʾ�޸�����
Uint64JsonVO::Wrapper  ExpenseTypeController::execModifyExpenseType(const ExpenseTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->bank_id || dto->bank_id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// ����һ��Service
	ExpenseTypeService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper ExpenseTypeController::execRemoveType(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ExpenseTypeService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}
ExpenseTreeJsonVO::Wrapper ExpenseTypeController::execQueryALLExpenseTree(const PayloadDTO& payload)
{
	//����һ��Service
	ExpenseService service;
	auto default_query = ExpenseQuery::Wrapper::createShared();
	default_query->parentid = 0;
	default_query->depth = 100;
	// ��ѯ����
	auto result = service.listTree(default_query);
	// ��Ӧ���

	return result;
}

ExpenseTreeJsonVO::Wrapper ExpenseTypeController::execQueryExpenseTree(ExpenseQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��Service
	ExpenseService service;
	// ��ѯ����
	auto result = service.listTree(query);
	// ��Ӧ���

	return result;
}