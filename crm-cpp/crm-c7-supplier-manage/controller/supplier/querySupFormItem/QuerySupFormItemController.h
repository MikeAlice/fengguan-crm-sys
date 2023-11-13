#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 18:38:07

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
#ifndef _QUERYSUPFORMITEM_H_
#define _QUERYSUPFORMITEM_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/supplier/SupFormItemQuery.h"
#include "domain/vo/supplier/SupFormItemJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��Ӧ���б�-��ȡ��Ӧ�̻�����Ϣ��������
 * �����ˣ�Andrew
 */
class QuerySupFormItemController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QuerySupFormItemController);
public: // ����ӿ�
	// ����˵�����
	ENDPOINT_INFO(querySupFormItem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.query-sup-form-item.summary"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SupFormItemJsonVO);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "main_table", ZH_WORDS_GETTER("supplier.query-sup-form-item.field.main-table"), "sup_supplier", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ext_table", ZH_WORDS_GETTER("supplier.query-sup-form-item.field.ext-table"), "sup_supplier", false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, SUP(/query-sup-form-item), querySupFormItem, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����queryParamsΪSupFormItemQuery����
		API_HANDLER_QUERY_PARAM(query, SupFormItemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySupFormItem(query));
	}
private: // ����ӿ�ִ�к���
	SupFormItemJsonVO::Wrapper execQuerySupFormItem(const SupFormItemQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYSUPFORMITEM_H_