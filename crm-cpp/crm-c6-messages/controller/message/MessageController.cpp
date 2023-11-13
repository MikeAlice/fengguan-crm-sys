/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/22 20:20:24

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
#include "MessageController.h"
#include "SimpleDateTimeFormat.h"
#include "service/message/MessageService.h"
#include <iostream>

Uint64JsonVO::Wrapper MessageController::execAddMail(const MailDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	MessageService ms;
	if (!dto->mail || !dto->recv_name || !dto->mess_type)
	{
		jvo->fail(1);
	}
	else
	{
		if (ms.sendMail(dto) == 1)
			jvo->fail(1);
		else
			jvo->success(10000);
	}
	return jvo;
}

Uint64JsonVO::Wrapper MessageController::execAddMails(const List<MailDTO::Wrapper>& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	MessageService ms;
	if (!dto->empty())
	{
		for (auto c:*dto)
			if (ms.sendMail(c) == 1)
			{
				jvo->fail(1);
				return jvo;
			}
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;
}

Uint64JsonVO::Wrapper MessageController::execAddSMS(const SMSDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	MessageService ms;
	if (!dto->phone || !dto->recv_name || !dto->mess_type)
	{
		jvo->fail(1);
	}
	else
	{
		if (ms.sendSMS(dto) == 1)
			jvo->fail(1);
		else
			jvo->success(10000);
	}
	return jvo;
}

Uint64JsonVO::Wrapper MessageController::execAddSMSs(const List<SMSDTO::Wrapper>& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	MessageService ms;
	if (!dto->empty())
	{
		for (auto c : *dto)
			if (ms.sendSMS(c) == 1)
			{
				jvo->fail(1);
				return jvo;
			}
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;
}
