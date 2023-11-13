#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: y
 @Date: 2023/10/24 16:26:29

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
#ifndef _REMOVE_SUPPLIER_CONTROLLER_
#define _REMOVE_SUPPLIER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/supplier/RemoveSupplierDTO.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 删除供应商Controller
 * 负责人: y
 */
class RemoveSupplierController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//2 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveSupplierController);
	//3 定义接口
public:
	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("supplier.removeSupplier.summary"), removeSupplier, Uint64JsonVO::Wrapper);
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, SUP(/remove-supplier), removeSupplier, BODY_DTO(RemoveSupplierDTO::Wrapper, dto), execRemoveSupplier(dto, authObject->getPayload()));
private: // 3.3 定义接口执行函数
	//删除
	Uint64JsonVO::Wrapper execRemoveSupplier(const RemoveSupplierDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

