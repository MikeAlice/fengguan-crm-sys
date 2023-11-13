#include "stdafx.h"
#include "addPayRecordController.h"
#include "../../service/add-pay-record/AddPayRecordService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper AddPayRecordController :: execaddPayRecord(const AddPayRecordDTO::Wrapper& dto) {
	/*auto result = StringJsonVO::createShared();
	result->success(String("add pay record !"));
	return result;*/
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto-> contract_name || !dto->bank_id || !dto->create_user_id || !dto->supplier_name || !dto->money || !dto->zero_money || !dto->stages){
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (stof(dto->money) < 0.0 || stof(dto->zero_money) < 0.0){
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AddPayRecordService service;
	// ִ����������
	uint64_t id = service.dealWithResult(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}