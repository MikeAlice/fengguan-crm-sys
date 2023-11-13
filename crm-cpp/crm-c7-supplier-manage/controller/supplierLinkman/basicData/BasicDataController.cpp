/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/23 17:26:49

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
#include "BasicDataController.h"
#include "service/supplierLinkman/basicData/BasicDataService.h"

BasicDataJsonVO::Wrapper BasicDataController::execQueryBasicData(const PayloadDTO& payload)
{
	// 调用service层
	BasicDataService service;
	auto result = service.listAll();
	// 创建jsonVo对象
	auto jvo = BasicDataJsonVO::createShared();
	jvo->success(result);
	return jvo;
}