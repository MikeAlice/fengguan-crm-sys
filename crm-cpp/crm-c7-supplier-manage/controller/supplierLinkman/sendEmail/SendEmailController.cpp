/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
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
	// 构建返回对象
	auto jvo = Uint64JsonVO::createShared();

	// 非空校验
	if (recvDTO->id_list->empty())
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}
	// 数据校验
	if (recvDTO->type.getValue(0) <= 0 || recvDTO->type.getValue(0) > 3)
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}

	// 向下调用Service层
	SendEmailService service;
	auto listSendDTO = service.listAll(recvDTO);

	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, SendEmailApiClient, "msg-server-api");
	// 返回查询结果
	jvo = ac->sendEmail(token, listSendDTO)->readBodyToDto<Uint64JsonVO::Wrapper>(om);
	return jvo;
}