/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "ContactController.h"
#include "../../service/contact/ContactService.h"
#include "service/contact/GetContactFieldService.h"
#include "service/contact/ListContactNameService.h"
#include "service/contact/GetContactListService.h"
//获取姓名列表
NameContactJsonVO::Wrapper ContactController::execQueryContactName(ListContactNameQuery::Wrapper query,const PayloadDTO& playload)
{
	// 定义一个Service
	ListContactNameService service;
	// 查询数据
	auto result = service.getName(query);
	
	return result;
}

ListContactPageJsonVO::Wrapper ContactController::execQueryContactList(ListContactQuery::Wrapper query , const PayloadDTO& playload)
{
	// 定义一个Service
	GetContactListService service;
	// 查询数据
	auto result = service.getContactList(query);
	// 响应结果
	auto jvo = ListContactPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ContactFieldJsonVO::Wrapper ContactController::execGetContactField()
{	
	// 定义一个Service
	GetContactFieldService service;
	// 查询数据
	ContactFieldDTO::Wrapper result = service.getContactField();

	// 响应结果
	auto jvo = ContactFieldJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ContactController::execRemoveContact(DeleteContactDTO::Wrapper dto)
{
	auto jvo = StringJsonVO::createShared();

	for (auto i = 0; i < dto->linkman_id->size(); i++) {
		if (!dto->linkman_id[i] || dto->linkman_id[i].getValue(0) <= 0) {
			jvo->init(u8"上传参数异常", RS_PARAMS_INVALID);
			return jvo;
		}
	}

	// 定义一个Service
	ContactService service;
	// 执行数据删除
	for (auto i = 0; i < dto->linkman_id->size(); i++) {
		if (service.removeContact(dto->linkman_id[i].getValue(0))) {
			jvo->success(u8"删除成功");
		}
		else
		{
			jvo->fail(u8"删除失败");
		}
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper ContactController::execQueryContactFile(ExportContactQuery::Wrapper query)
{

	// 定义一个Service
	ContactService service;
	// 查询数据
	list<ExportContactDTO::Wrapper> result = service.listContact(query);

	//将数据保存为Excel格式并上传到文件服务器
	String url = service.uploadContact(result);
	// 响应结果
	StringJsonVO::Wrapper jvo = StringJsonVO::createShared();
	jvo->success(url);

	return jvo;
}

StringJsonVO::Wrapper ContactController::execAddContact(AddContactDTO::Wrapper dto, const PayloadDTO& playload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	
	// 定义一个Service
	ContactService service;
	// 执行数据修改
	if (service.saveContact(dto, playload)) {
		jvo->success(u8"添加成功");
	}
	else
	{
		jvo->fail(u8"添加失败");
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper ContactController::execModifyContact(UpdateContactDTO::Wrapper dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->linkman_id || dto->linkman_id <= 0)
	{
		jvo->init(u8"传入参数错误", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ContactService service;
	// 执行数据修改
	if (service.updateContact(dto)) {
		jvo->success(u8"修改成功");
	}
	else
	{
		jvo->fail(u8"修改失败");
	}
	// 响应结果
	return jvo;
}
