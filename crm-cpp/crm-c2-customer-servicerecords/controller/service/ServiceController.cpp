/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/24 13:44:08

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ServiceController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/service/ServiceService.h"


//��ӷ����¼
Uint64JsonVO::Wrapper ServiceAddRemoveModifyController::execAddServices(const ServiceBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->customer_id || !dto->linkman_id || !dto->services || 
		!dto->servicesmodel|| !dto->price || !dto->status ||
		!dto->tlen )
	{
		jvo->init(UInt64(-1), RS_PARAMS_EMPTY);
		return jvo;
	}
	
	//cout << dto->tlen->empty() << !dto->status << endl;
	// ��ЧֵУ��
	if (dto->services < 0 || (dto->status < 1 || dto->status > 4))
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ServiceService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
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
//����ɾ�������¼
Uint64JsonVO::Wrapper ServiceAddRemoveModifyController::execRemoveServices(const ServiceIdListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	ServiceService service;
	auto jvo = Uint64JsonVO::createShared();
	Vector<UInt64> arr = dto->service_id_s;
	for (int i = 0; i < arr->size(); i++) {
		// ���巵�����ݶ���
		
		// ����У��
		if (!arr[i] || arr[i] <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		
		// ִ������ɾ��
		if (service.removeData(arr[i].getValue(0))) {
			jvo->success(arr[i]);
		}
		else
		{
			jvo->fail(arr[i]);
			return jvo;
		}
		// ��Ӧ���
	}
	
	return jvo;
}
//�޸ķ����¼
Uint64JsonVO::Wrapper ServiceAddRemoveModifyController::execModifyServices(const ServiceModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->service_id || dto->service_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//�Դ������������Ч����֤
	if (dto->services && dto->services < 0) {
		jvo->init(UInt64(-1), RS_PARAMS_SELECTABLE_ERROR);
		return jvo;
	}
	if (dto->status && (dto->status < 1 || dto->status > 4)) {
		jvo->init(UInt64(-1), RS_PARAMS_SELECTABLE_ERROR);
		return jvo;
	}
	// ����һ��Service
	ServiceService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->service_id);
	}
	else
	{
		jvo->fail(dto->service_id);
	}
	// ��Ӧ���
	return jvo;
}

