#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chou
 @Date: 2023/10/23 14:40:19

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
#ifndef _COLLECTIONPLANSCONTROLLER_H_
#define _COLLECTIONPLANSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/collectionplans/AddCollectionPlanDTO.h"
#include "domain/dto/collectionplans/GetCollectionPlanListDTO.h"
#include "domain/query/collectionplans/CollectionPlansQuery.h"
#include "domain/vo/collectionplans/CollectionPlansVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

// ����ǰ׺
#ifndef CPC_PRFIX
#define CPC_PRFIX(_app_) "/collection-man/collectionplans" _app_
#endif

/**
 * �ؿ�ƻ������ӿ�ʵ��
 */
class CollectionPlansController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(CollectionPlansController);
public: // ����ӿ�
	// ��ȡ�ؿ�ƻ��б�
	ENDPOINT_INFO(queryCollectionPlansList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("collectionplans.get-collectionplans.get"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	    API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CollectionPlansPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// �ؿ�����
		API_DEF_ADD_QUERY_PARAMS(String, "backdate", ZH_WORDS_GETTER("collectionplans.field.backdate1"), "2023-11-11", false);
		// ��ͬ��������
		API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("collectionplans.field.contract"), "Kim Lewis", false);
		// ������ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "createdate", ZH_WORDS_GETTER("collectionplans.field.createdate1"), "2023-11-11", false);
		// ��ѯ�Ƿ񸶿�
		API_DEF_ADD_QUERY_PARAMS(String, "ifpay", ZH_WORDS_GETTER("collectionplans.field.ifpay"), "YES", false);

	}
	ENDPOINT(API_M_GET, CPC_PRFIX("/get-collectionplans"), queryCollectionPlansList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, CollectionPlansQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCollection(userQuery, authObject->getPayload()));
	}


	// ��ӻؿ�ƻ�
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addCollectionPlans) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("collectionplans.add-collection.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, CPC_PRFIX("/add-collection"), addCollectionPlans, BODY_DTO(AddCollectionPlanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddCollectionPlans(dto, authObject->getPayload()));

	}


private: // ����ӿ�ִ�к���
	// ��ȡ�ؿ�ƻ��б�
	CollectionPlansPageJsonVO::Wrapper execQueryCollection(const CollectionPlansQuery::Wrapper& query, const PayloadDTO& payload);
	//
	Uint64JsonVO::Wrapper execAddCollectionPlans(const AddCollectionPlanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COLLECTIONPLANSCONTROLLER_H_