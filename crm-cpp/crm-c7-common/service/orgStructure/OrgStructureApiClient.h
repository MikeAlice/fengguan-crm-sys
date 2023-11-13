#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/01 22:13:28

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
#ifndef _DEPARTMENTNAMEAPICLIENT_H_
#define _DEPARTMENTNAMEAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 组织结构公用接口声明式服务ApiClient
 * 负责人: Andrew
 */
class OrgStructureApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(OrgStructureApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 获取部门名称列表
	API_CALL(API_M_GET, "orgstructure/dept/dept/list-name-all", queryDepartmentName, API_HANDLER_AUTN_HEADER, QUERY(String, deptName));
	// 获取岗位名称列表
	API_CALL(API_M_GET, "orgstructure/position/position/query-name-all", queryPositionName, API_HANDLER_AUTN_HEADER, QUERY(String, positionName));
	// 获取角色名称列表
	API_CALL(API_M_GET, "orgstructure/role/role/query-name-all", queryRoleName, API_HANDLER_AUTN_HEADER);
	// 系统用户名称列表
	API_CALL(API_M_GET, "orgstructure/user/user/get-userName-list", querySysUserName, API_HANDLER_AUTN_HEADER, QUERY(String, name));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_DEPARTMENTNAMEAPICLIENT_H_