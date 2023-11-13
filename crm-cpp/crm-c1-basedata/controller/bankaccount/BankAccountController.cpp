#include "stdafx.h"
#include "BankAccountController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/bankaccount/BankAccountDO.h"
#include "service/bankaccount/BankAccountService.h"
#include "tree/TreeUtil.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
//��ҳ��ѯ
BankAccountPageJsonVO::Wrapper BankAccountController::execQueryBankAccount(const BankAccountQuery::Wrapper& query, const PayloadDTO& payload)
{
	
	// ����һ��Service
	BankAccountService service;
	auto result = service.listAll(query);
	 //��Ӧ���
	auto jvo = BankAccountPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
BankAccountListJsonVO::Wrapper BankAccountController::execGetBankAccountList(const BankAccountListQuery::Wrapper& query, const PayloadDTO& payload)
{

	// ����һ��Service
	BankAccountService service;
	auto result = service.getlistAll(query);
	//��Ӧ���
	auto jvo = BankAccountListJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
// 3.3 ��ʾ��������
Uint64JsonVO::Wrapper BankAccountController::execAddBankAccount(const BankAccountDTO::Wrapper& dto)
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
	BankAccountService service;
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
Uint64JsonVO::Wrapper  BankAccountController::execModifyBankAccount(const BankAccountDTO::Wrapper& dto)
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
	BankAccountService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->bank_id);
	}
	else
	{
		jvo->fail(dto->bank_id);
	}
	// ��Ӧ���
	return jvo;
}
// 3.3 ��ʾɾ������
Uint64JsonVO::Wrapper  BankAccountController::execRemoveBankAccount(const UInt64&bank_id)
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
	BankAccountService service;
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
StringJsonVO::Wrapper BankAccountController::execExportBankAccount(const List<BankAccountExportDTO::Wrapper>& query, const PayloadDTO& payload)
{
	// ����һ��Service
	BankAccountService service;
	std::string url = service.exportData(query);
	auto jvo = StringJsonVO::createShared();
	if (query->size() == 0)
		jvo->init({}, RS_PARAMS_INVALID);
	if (url == "")
		jvo->fail({});
	else
		jvo->success(url);
	return jvo;
}
