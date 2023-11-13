#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ��
 @Date: 2023/10/21 0:27:04

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
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/supplier/SupplierQuery.h"
#include "domain/dto/supplier/SupplierDTO.h"
#include "domain/vo/supplier/SupplierVO.h"
#include "Macros.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ��Ӧ���б�&��ӹ�Ӧ��Controller
 * ������: ��
 */
class SupplierController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SupplierController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySupplier) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.getSupList.summary"));
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("supplier.getSupList.name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "telephone", ZH_WORDS_GETTER("supplier.getSupList.telephone"), "000-000", false);
		API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("supplier.getSupList.mobile"), "000-000", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("supplier.getSupList.address"), "BeiJing", false);
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, SUP(/get-supplier), querySupplier, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, SupplierQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySupplier(userQuery));
	}

	//3.1������ӽӿ�����
	ENDPOINT_INFO(addSupplier) {
		// ����ƾ֤У��
		API_DEF_ADD_AUTH();
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.addSupplier.summary"));
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, SUP(/add-supplier), addSupplier, BODY_DTO(SupplierDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddSupplier(dto, authObject->getPayload()));
	}
	
private:
	// 3.3 ��ҳ��ѯ����
	SupplierPageJsonVO::Wrapper execQuerySupplier(const SupplierQuery::Wrapper& query);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddSupplier (const SupplierDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_