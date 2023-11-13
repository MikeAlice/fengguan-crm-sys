/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/10/26 13:07:49

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
#include "SendEmailController.h"
#include "service/supplierLinkman/sendEmail/SendEmailService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/supplierLinkman/sendEmail/declarative/SendEmailApiClient.h"
#include "domain/dto/PayloadDTO.h"

Uint64JsonVO::Wrapper SendEmailController::execSendEmailById(const SendEmailRecvDTO::Wrapper& recvDTO, const PayloadDTO& payload)
{
	// �������ض���
	auto jvo = Uint64JsonVO::createShared();

	// �ǿ�У��
	if (recvDTO->id_list->empty())
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����У��
	if (recvDTO->type.getValue(0) <= 0 || recvDTO->type.getValue(0) > 3)
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}

	// ���µ���Service��
	SendEmailService service;
	auto listSendDTO = service.listAll(recvDTO);

	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, SendEmailApiClient, "msg-server-api");
	// ���ز�ѯ���
	jvo = ac->sendEmail(token, listSendDTO)->readBodyToDto<Uint64JsonVO::Wrapper>(om);
	return jvo;
}