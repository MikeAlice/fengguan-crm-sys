/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/26 16:09:42

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
#ifndef _SMS_H_
#define _SMS_H_

#include "../../domain/dto/message/MessageDTO.h"
class SMS
{
public:
	uint64_t sendSMS1(const SMSDTO::Wrapper dto);
	uint64_t sendSMS2(const SMSDTO::Wrapper dto);
	uint64_t sendSMS3(const SMSDTO::Wrapper dto);
	uint64_t sendSMS4(const SMSDTO::Wrapper dto);
	uint64_t sendSMS5(const SMSDTO::Wrapper dto);
	uint64_t sendSMS6(const SMSDTO::Wrapper dto);
	uint64_t sendSMS7(const SMSDTO::Wrapper dto);
	uint64_t sendSMS8(const SMSDTO::Wrapper dto);
};

#endif // !_SMS_H_
