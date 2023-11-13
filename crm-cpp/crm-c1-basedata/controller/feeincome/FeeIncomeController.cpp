#include "stdafx.h"
#include "FeeIncomeController.h"
#include "../../service/feeincome/FeeIncomeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "tree/TreeUtil.h"
FeeIncomeTreeJsonVO::Wrapper FeeIncomeController::execQueryALLFeeIncome(const PayloadDTO& payload)
{
	 //����һ��Service
	 FeeIncomeService service;
	 auto default_query = FeeIncomeQuery::Wrapper::createShared();
	 default_query->parentid = 0;
	 default_query->depth = 100;
	// ��ѯ����
	auto result = service.listTree(default_query);
	// ��Ӧ���

	return result;
}

FeeIncomeTreeJsonVO::Wrapper FeeIncomeController::execQueryALLFeeIncomeTree(FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload)
{
	 //����һ��Service
	FeeIncomeService service;
	// ��ѯ����
	auto result = service.listTree(query);
	// ��Ӧ���
	
	return result;
}
// ��ȡ�����б�(��ҳ + ����)
FeeIncomePageJsonVO::Wrapper FeeIncomeController::execQueryType(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	FeeIncomeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FeeIncomePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//FeeIncomePageJsonVO::Wrapper FeeIncomeController::execQueryFeeIncome(const FeeIncomeQuery::Wrapper& query, const PayloadDTO& payload)
//{
//
//	// ����һ��Service
//	FeeIncomeService service;
//	auto result = service.listAll(query);
//	//��Ӧ���
//	auto jvo = FeeIncomePageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//
//}
// 3.3 ��ʾ��������
Uint64JsonVO::Wrapper FeeIncomeController::execAddFeeIncome(const FeeIncomeDTO::Wrapper& dto)
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
	FeeIncomeService service;
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
Uint64JsonVO::Wrapper  FeeIncomeController::execModifyFeeIncome(const FeeIncomeDTO::Wrapper& dto)
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
	FeeIncomeService service;
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
// 3.3 ��ʾɾ������
Uint64JsonVO::Wrapper  FeeIncomeController::execRemoveFeeIncome(const UInt64& bank_id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	/*if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// ����һ��Service
	FeeIncomeService service;
	// ִ������ɾ��
	if (service.removeData(bank_id.getValue(0))) {
		jvo->success(bank_id);
	}
	else
	{
		jvo->fail(bank_id);
	}
	// ��Ӧ���
	return jvo;
}