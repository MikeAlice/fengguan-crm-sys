#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/23 10:58:36

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
#ifndef _MAILTEST_H_
#define _MAILTEST_H_

#include "../../domain/dto/message/MessageDTO.h"

class Mail
{
public:
	uint64_t sendMail1(const MailDTO::Wrapper& dto);
	uint64_t sendMail2(const MailDTO::Wrapper& dto);
	uint64_t sendMail3(const MailDTO::Wrapper& dto);
	uint64_t sendMail4(const MailDTO::Wrapper& dto);
	uint64_t sendMail5(const MailDTO::Wrapper& dto);
	uint64_t sendMail6(const MailDTO::Wrapper& dto);
	uint64_t sendMail7(const MailDTO::Wrapper& dto);
	uint64_t sendMail8(const MailDTO::Wrapper& dto);
};

#endif // !_MAIL_H_