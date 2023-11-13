#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#include "domain/do/supplierLinkman/SendMessageDO.h"
#include "domain/dto/supplierLinkman/SendMessageDTO.h"	
/**
 * 发送邮件服务层实体类
 * 负责人: 柏下微雨
 */
class SendMessageService
{
public:
	//获取名字和电话
	std::list<SendMessageDO> getNameAndPhone(const SendMessageDTO::Wrapper& dto);
};

