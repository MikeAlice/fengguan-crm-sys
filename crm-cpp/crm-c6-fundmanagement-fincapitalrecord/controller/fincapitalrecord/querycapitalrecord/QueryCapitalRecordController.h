#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/24
 @FileName: QueryCapitalRecordController
 @version: 1.0

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
#ifndef _QUERY_CAPITAL_RECORD_CONTROLLER_H_
#define _QUERY_CAPITAL_RECORD_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/fincapitalrecord/CapitalRecordPageQuery.h"
#include "domain/vo/fincapitalrecord/CapitalRecordPageJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class QueryCapitalRecordController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QueryCapitalRecordController);
public:// ����ӿ�
	// ��ȡ�����б���ҳ+������ �����ˣ�����
	ENDPOINT_INFO(queryCapitalRecord) {
		// �ö˵��������Ϣ
		info->summary = ZH_WORDS_GETTER("fin_capital_record.controller.query.summary");
		// ��Ӱ�ȫ��֤
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������(����)
		API_DEF_ADD_PAGE_PARAMS();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CapitalRecordPageJsonVO);
		// ����
		API_DEF_ADD_QUERY_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("fin_capital_record.field.record_id"), , false);
		// ���
		API_DEF_ADD_QUERY_PARAMS(Int64, "money", ZH_WORDS_GETTER("fin_capital_record.field.money"), , false);
		// ��������
		API_DEF_ADD_QUERY_PARAMS(Int64, "latest_happen_date", ZH_WORDS_GETTER("fin_capital_record.field.latest_happen_date"), 30, false);
		// ����ʱ��
		API_DEF_ADD_QUERY_PARAMS(Int64, "latest_create_time", ZH_WORDS_GETTER("fin_capital_record.field.latest_create_time"), 30, false);

	}

	ENDPOINT(API_M_GET, "/fin-capital-record/query-data", queryCapitalRecord, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(capitalRecordQuery, CapitalRecordPageQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCapitalRecord(capitalRecordQuery, authObject->getPayload()));
	}
private:
	// ��ȡ�����б���ҳ+������ �����ˣ�����
	CapitalRecordPageJsonVO::Wrapper execQueryCapitalRecord(const CapitalRecordPageQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif
