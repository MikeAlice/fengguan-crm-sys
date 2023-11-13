#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: william
 @Date: 2023/10/25 10:40:57

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
#ifndef _SENDMSEMSERVICE_H_
#define _SENDMSEMSERVICE_H_
#include "stdafx.h"
#include "ApiHelper.h"
#include "domain/do/sendmsem/SendmsemDO.h"
#include "domain/dto/sendmsem/SendmsemDTO.h"

class SendmsemService
{
public:
	//获取客户预约信息
	oatpp::List<InfoDTO::Wrapper> getinfo(const oatpp::List<oatpp::Int64>& dto);
	//发送短信
	bool sendms(const oatpp::List<InfoDTO::Wrapper>& infos);
	//发送邮件
	bool sendem(const oatpp::List<InfoDTO::Wrapper>& infos);
};

#endif // !_SENDMSEMSERVICE_H_