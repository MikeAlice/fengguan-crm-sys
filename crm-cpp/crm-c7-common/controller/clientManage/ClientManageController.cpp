/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/02 18:34:37

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
#include "ClientManageController.h"
#include "../ApiDeclarativeServicesHelper.h"

ClientNameArrayJsonVO::Wrapper ClientManageController::execQueryClientName(const PullListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, ClientManageApiClient, "client-manage-api");
	// 生成凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryClientName(token, URIUtil::urlEncode(query->keywords))->readBodyToDto<ClientNameArrayJsonVO::Wrapper>(om);
}

ContactNameArrayJsonVO::Wrapper ClientManageController::execQueryContactName(const ContactNameQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, ClientManageApiClient, "contact-name-api");
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryContactName(token, query->customer_id, URIUtil::urlEncode(query->name))->readBodyToDto<ContactNameArrayJsonVO::Wrapper>(om);
}
