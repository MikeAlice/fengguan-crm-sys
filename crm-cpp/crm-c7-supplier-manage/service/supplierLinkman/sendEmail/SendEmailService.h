#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2023/10/26 13:39:40

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
#ifndef _SENDEMAILSERVICE_H_
#define _SENDEMAILSERVICE_H_

#include <list>
#include "domain/dto/supplierLinkman/SendEmailDTO.h"

class SendEmailService
{
public:
	oatpp::List<SendEmailSendDTO::Wrapper> listAll(const SendEmailRecvDTO::Wrapper& recvdto);
};

#endif // !_SENDEMAILSERVICE_H_