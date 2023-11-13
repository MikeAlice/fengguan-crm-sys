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
	//��Ϣ����
	CC_SYNTHESIZE(int, mess_type, Mess_type);
	//�ռ���
	CC_SYNTHESIZE(string, recv_name, Recv_name);
	//��ͬ��
	CC_SYNTHESIZE(string, contrast_name, Contrast_name);
	//�绰
	CC_SYNTHESIZE(string, phone, Phone);
	//ʱ��
	CC_SYNTHESIZE(string, time, Time);
	//����
	CC_SYNTHESIZE(string, mail, Mail);
	//��Ϣ����
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