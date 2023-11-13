#include "stdafx.h"
#include "SendmsemController.h"
#include "service/sendmsem/SendmsemService.h"
#include "domain/dto/sendmsem/SendmsemDTO.h"

//���Ͷ���
BooleanJsonVO::Wrapper SendmsemController::execSendMs(const oatpp::List<oatpp::Int64>& dto) {
	// ���巵�����ݶ���
	auto jvo = BooleanJsonVO::createShared();
	for (auto& id : *dto) {
		// ����У��
		// �ǿ�У��
		if (!id) {
			jvo->init(false, RS_PARAMS_INVALID);
			return jvo;
		}
	}

	SendmsemService service;
	//��ȡ�ͻ�ԤԼ��Ϣ
	List<InfoDTO::Wrapper> infos = service.getinfo(dto);
	if (infos && infos->size() == 0) {
		jvo->success(true);
		return jvo;
	}
	//���Ͷ��� 
	if (service.sendms(infos)) {
		jvo->success(true);
	}
	else {
		jvo->fail(false);
	}
	return jvo;
};

//�����ʼ�
BooleanJsonVO::Wrapper SendmsemController::execSendEm(const oatpp::List<oatpp::Int64>& dto) {
	// ���巵�����ݶ���
	auto jvo = BooleanJsonVO::createShared();
	for (auto& id : *dto) {
		// ����У��
		// �ǿ�У��
		if (!id) {
			jvo->init(false, RS_PARAMS_INVALID);
			return jvo;
		}
	}

	SendmsemService service;
	//��ȡ�ͻ�ԤԼ��Ϣ
	List<InfoDTO::Wrapper> infos = service.getinfo(dto);
	if (infos && infos->size() == 0) {
		jvo->success(true);
		return jvo;
	}
	//���Ͷ���
	if (service.sendem(infos)) {
		jvo->success(true);
	}
	else {
		jvo->fail(false);
	}
	return jvo;
};

