/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/23 8:47:13

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
#include "MessageService.h"
#include "../../uselib/mail/Mail.h"
#include "../../uselib/sms/SMS.h"
#include<iostream>

uint64_t MessageService::sendMail(const MailDTO::Wrapper& dto)
{
	Mail m;
	switch (dto->mess_type.getValue({}))
	{
	case 1:
	{
		if (m.sendMail1(dto))return 1;
		return 0;
	}
	case 2:
	{
		if (m.sendMail2(dto))return 1;
		return 0;
	}
	case 3:
	{
		if (m.sendMail3(dto))return 1;
		return 0;
	}
	case 4:
	{
		if (m.sendMail4(dto))return 1;
		return 0;
	}
	case 5:
	{
		if (m.sendMail5(dto))return 1;
		return 0;
	}
	case 6:
	{
		if (m.sendMail6(dto))return 1;
		return 0;
	}
	case 7:
	{
		if (m.sendMail7(dto))return 1;
		return 0;
	}
	case 8:
	{
		if (m.sendMail8(dto))return 1;
		return 0;
	}
	default:
		return 1;
	}
	return 0;
}

uint64_t MessageService::sendSMS(const SMSDTO::Wrapper& dto)
{
	SMS m;
	switch (dto->mess_type.getValue({}))
	{
	case 1:
	{
		if (m.sendSMS1(dto))return 1;
		return 0;
	}
	case 2:
	{
		if (m.sendSMS2(dto))return 1;
		return 0;
	}
	case 3:
	{
		if (m.sendSMS3(dto))return 1;
		return 0;
	}
	case 4:
	{
		if (m.sendSMS4(dto))return 1;
		return 0;
	}
	case 5:
	{
		if (m.sendSMS5(dto))return 1;
		return 0;
	}
	case 6:
	{
		if (m.sendSMS6(dto))return 1;
		return 0;
	}
	case 7:
	{
		if (m.sendSMS7(dto))return 1;
		return 0;
	}
	case 8:
	{
		if (m.sendSMS8(dto))return 1;
		return 0;
	}
	default:
		return 1;
	}
	return 0;
}
