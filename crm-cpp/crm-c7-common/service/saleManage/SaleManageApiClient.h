#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 20:23:31

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
#ifndef _SALEOPPOTUNITYAPICLIENT_H_
#define _SALEOPPOTUNITYAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ���۹����ýӿ�����ʽ����ApiClient
 * ������: Andrew
 */
class SaleManageApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// ��ʼ������
	API_CLIENT_INIT(SaleManageApiClient);

	// ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ��ȡ���ۻ��������б�
	API_CALL(API_M_GET, "sales-opportunities/sales-oppo-name-list", querySaleOpportunity, API_HANDLER_AUTN_HEADER, QUERY(UInt32, customer_id), QUERY(String, name));
	// ��ȡ���ۺ�ͬ�����б�
	API_CALL(API_M_GET, "sales-contract/sales-cont-list", querySaleContract, API_HANDLER_AUTN_HEADER, QUERY(UInt32, customer_id), QUERY(String, title));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_SALEOPPOTUNITYAPICLIENT_H_