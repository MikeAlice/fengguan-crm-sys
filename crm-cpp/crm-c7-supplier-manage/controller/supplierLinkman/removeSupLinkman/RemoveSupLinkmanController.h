#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/23 22:22:38

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
#ifndef _DELSUPLINKMAN_H_
#define _DELSUPLINKMAN_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/supplierLinkman/RemoveSupLinkmanDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 删除供应商联系人Controller
 * 负责人: ll
 */
class RemoveSupLinkmanController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveSupLinkmanController);
public: // 定义接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("supplier-linkman.remove-sup-linkman.summary"), removeLinkman, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, SUP_LINKMAN(/remove-linkman), removeLinkman, BODY_DTO(RemoveSupLinkmanDTO::Wrapper, dto), execRemoveSupLinkman(dto, authObject->getPayload()));
private: // 定义接口执行函数
	BooleanJsonVO::Wrapper execRemoveSupLinkman(const RemoveSupLinkmanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DELSUPLINKMAN_H_