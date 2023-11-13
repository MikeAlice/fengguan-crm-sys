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
#ifndef _SUPPLIER_NAME_CONTROLLER_
#define _SUPPLIER_NAME_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/supplier/SupplierNameQuery.h"
#include "domain/dto/supplier/SupplierNameDTO.h"
#include "domain/vo/supplier/SupplierNameVO.h"
#include "Macros.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class SupplierNameController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SupplierNameController);
	// 3 ����ӿ�
public:
	// 3.1 ���幩Ӧ�������б��ѯ�ӿ�����
	ENDPOINT_INFO(querySupplierName) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.getSupList.nameList"));
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierNameJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("supplier.getSupList.name"), "li ming", false);
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, SUP(/query-supplier-name), querySupplierName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, SupplierNameQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySupplierName(userQuery));
	}

private:
	// 3.3 �б��ѯ��Ӧ����������
	SupplierNameJsonVO::Wrapper execQuerySupplierName(const SupplierNameQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SUPPLIER_NAME_CONTROLLER_
