#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 21:50:04

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
#ifndef _MODIFY_SUPPLIER_CONTROLLER_
#define _MODIFY_SUPPLIER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/supplier/ModifySupplierDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �޸Ĺ�Ӧ��Controller
 * ������: Juno
 */
class ModifySupplierController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifySupplierController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("supplier.modifySupplier.summary"), modifySupplier, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, SUP(/modify-supplier), modifySupplier, BODY_DTO(ModifySupplierDTO::Wrapper, dto), execModifySupplier(dto, authObject->getPayload()));
private:
	// 3.3 �޸�����
	Uint64JsonVO::Wrapper execModifySupplier(const ModifySupplierDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_