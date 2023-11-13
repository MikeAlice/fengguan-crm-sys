#include "stdafx.h"
#include"Out_boundController.h"
#include "service/out_bound/Out_boundService.h"




BooleanJsonVO::Wrapper Out_boundController::execConfirmOutstock(const ConfOut_boundDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = BooleanJsonVO::createShared();
	// ����У��
	if (!dto->out_id || dto->out_id <= 0 || dto->status == 1 || dto->number <= 0 )//���ⵥ���Ų��Ϸ������ⵥ״̬Ϊ�ѳ��⡢���������������
	{
		jvo->init(Boolean(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	Out_boundService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// ��Ӧ���
	return jvo;
}

BooleanJsonVO::Wrapper Out_boundController::execDeleteOutstock(const List<DelOut_boundDTO::Wrapper>& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = BooleanJsonVO::createShared();
	// ���б����У��
	if (!dto)
	{
		jvo->init(Boolean(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//���б�����������
	for (auto i = dto->begin(); i != dto->end(); i++)
	{	
		if (!((*i)->out_id) || (*i)->out_id.getValue({}) <= 0)
		{
			jvo->init(Boolean(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// ����һ��Service
	Out_boundService service;
	// ִ������ɾ��
	if (service.removeData(dto)){
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// ��Ӧ���
	return jvo;
}


