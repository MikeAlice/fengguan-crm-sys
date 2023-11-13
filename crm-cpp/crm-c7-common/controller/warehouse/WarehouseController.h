#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/10/31 17:56:05

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
#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/dto/warehouse/WarehouseDTO.h"
#include "../../domain/vo/warehouse/WarehouseJsonVO.h"
#include "../../domain/query/PullListQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ȡ�ֿ������б�
 * �����ˣ�����
 */
class WarehouseController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(WarehouseController)
public: // ����ӿ�
	
	ENDPOINT_INFO(queryWarehouse) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("common-usage.warehouse.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WarehouseJsonVO);
		// ��������ֶ�
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
		// ������Ȩ֧��
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, COMMON(/warehouse), queryWarehouse, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// �������query����
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		// �������ִ�к���
		API_HANDLER_RESP_VO(execQueryWarehouse(query, authObject->getPayload()));
	}

private: // ����ӿ�ִ�к���
	WarehouseJsonVO::Wrapper execQueryWarehouse(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WAREHOUSE_H_