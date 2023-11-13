/*
 Copyright Zero One Star. All rights reserved.

 @Author: Tapioca
 @Date: 2023/10/22 10:45:11

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
#include "ModifyLinkmanController.h"
#include "service/supplierLinkman/updateSupLinkman/UpdateLinkmanService.h"

Uint64JsonVO::Wrapper ModifyLinkmanController::execModifyLinkman(const LinkmanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建响应数据
	auto vo = Uint64JsonVO::createShared();

    //参数校验
    if (!dto->linkman_id || dto->linkman_id == 0) {
        vo->init(UInt64(-1), RS_PARAMS_INVALID);
        return vo;
    }

    // 定义一个Service
    UpdateLinkmanService service;

    // 执行数据修改
    if (service.updateLinkmanData(dto)) {
        vo->success(dto->linkman_id);
    }
    else {
        vo->fail(dto->linkman_id);
    }
	return vo;
}