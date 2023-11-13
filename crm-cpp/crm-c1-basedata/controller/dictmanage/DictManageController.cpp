#include "stdafx.h"
#include "DictManageController.h"
#include "../../service/dictmanage//DictManageService.h"
#include "../ApiDeclarativeServicesHelper.h"
//����ֵ�
Uint64JsonVO::Wrapper DictManageController::execAddDict(const DictDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->name || !dto->typetag || !dto->sort || !dto->visible)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->sort < 0 || dto->name->empty() || dto->typetag->empty() || dto->visible > 1 || dto->visible < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ������
	DictManageService service;
	//ִ�����
	int64_t id = service.saveData(dto);
	//�ж��Ƿ�ɹ�
	if (id > 0) jvo->success(UInt64(id));
	else jvo->fail(UInt64(id));
	//���ؽ��
	return jvo;
}
//�޸��ֵ�
Uint64JsonVO::Wrapper DictManageController::execModifyDict(const DictDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->name || !dto->typetag || !dto->sort || !dto->visible)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->sort < 0 || dto->name->empty() || dto->typetag->empty() || dto->visible > 1 || dto->visible < 0 || dto->id < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ������
	DictManageService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	//���ؽ��
	return jvo;
}
//ɾ���ֵ�
Uint64JsonVO::Wrapper DictManageController::execDeleteDict(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// ��ЧֵУ��
	if (id < 0)
	{
		jvo->fail(id);
		return jvo;
	}
	//��������
	DictManageService service;
	//ִ��ɾ�� �����ؽ��
	bool isDelect = service.removeData(id);
	if (isDelect) jvo->success(id);
	else jvo->fail(id);
	//���ؽ��
	return jvo;
}
//��ѯ�ֵ�
DictPageJsonVO::Wrapper DictManageController::execQueryDict(const DictQuery::Wrapper& query, const PayloadDTO& payload)
{
	//�����ѯ���
	auto jvo = DictPageJsonVO::createShared();
	//�������
	DictManageService serice;
	//�����ѯ
	auto res = serice.listAll(query);
	//���ؽ��
	jvo->success(res);
	return jvo;
}
//��ȡ��ҳ�б�
DictTypePageJsonVO::Wrapper DictManageController::execPageDict()
{
	//���巵ֵ
	auto jvo = DictTypePageJsonVO::createShared();
	//�������
	DictManageService service;
	//��ѯ���
	auto res = service.getPage();
	jvo->success(res);
	//���ؽ��
	return jvo;
}