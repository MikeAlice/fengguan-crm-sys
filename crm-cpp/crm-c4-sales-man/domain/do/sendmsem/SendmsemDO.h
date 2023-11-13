#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: william
 @Date: 2023/10/25 11:27:45

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
#ifndef _SENDMSEMDO_H_
#define _SENDMSEMDO_H_
#include "../DoInclude.h"

class SendmsemDO
{
	//消息类型
	CC_SYNTHESIZE(int, mess_type, Mess_type);
	//收件人
	CC_SYNTHESIZE(string, recv_name, Recv_name);
	//合同名
	CC_SYNTHESIZE(string, contrast_name, Contrast_name);
	//电话
	CC_SYNTHESIZE(string, phone, Phone);
	//时间
	CC_SYNTHESIZE(string, time, Time);
	//邮箱
	CC_SYNTHESIZE(string, mail, Mail);
	//消息内容
	CC_SYNTHESIZE(string, mess, Mess);
public:
	SendmsemDO() {
		mess_type = 1;
		recv_name = "";
		contrast_name = "";
		phone = "";
		time = "";
		mail = "";
		mess = "";
	}
};

#endif // !_SENDMSEMDO_H_