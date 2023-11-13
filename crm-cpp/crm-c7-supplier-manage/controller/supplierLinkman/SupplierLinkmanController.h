#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: telephone
 @Date: 2023/10/23 18:20:31

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
#ifndef SUPPLIER_LINK_MAN
#define SUPPLIER_LINK_MAN

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/supplierLinkman/SupplierLinkmanVO.h"
#include "domain/dto/supplierLinkman/SupplierLinkmanDTO.h"
#include "domain/query/supplierLinkman/SupplierLinkmanQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ��Ӧ����ϵ���б�&��ӹ�Ӧ����ϵ��controller
 * ������: telephone
 */
class SupplierLinkmanController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SupplierLinkmanController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySupplierLinkman) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.query-page.summary"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierLinkmanPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("supplier-linkman.query-page.field.keywords"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-name"), "hao", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("supplier-linkman.query-page.field.address"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, SUP_LINKMAN(/query-linkman-page), querySupplierLinkman, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, SupplierLinkmanQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySupplierLinkman(userQuery));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addSupplierLinkman) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.add-linkman.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, SUP_LINKMAN(/add-linkman), addSupplierLinkman, BODY_DTO(AddSupplierLinkmanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddSupplierLinkman(dto, authObject->getPayload()));
	}

	
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	SupplierLinkmanPageJsonVO::Wrapper execQuerySupplierLinkman(const SupplierLinkmanQuery::Wrapper& query);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddSupplierLinkman(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
