#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����΢��
 @Date: 2023/09/26 16:29:52

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
#ifndef _SENDMESSAGEAPICLIENT_H_
#define _SENDMESSAGEAPICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"
#include "domain/dto/supplierLinkman/SendMessageDeclDTO.h"
/**
 * ���÷��Ͷ��ŷ���APICLIENT
 */
class SendMessageApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(SendMessageApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�
	// ����������
	//const oatpp::data::share::StringTemplate Z_PATH_TEMPLATE_smss = parsePathTemplate("smss", "message/smss"); static void Z_ADD_HEADERS_smss(oatpp::web::client::ApiClient::Headers& headers, ...) {
	//	(void)headers;
	//} std::shared_ptr<oatpp::web::protocol::http::incoming::Response> smss(const oatpp::String& token, const Object<SendMessageDeclListDTO>& dto, const std::shared_ptr<oatpp::web::client::RequestExecutor::ConnectionHandle>& __connectionHandle = nullptr) {
	//	oatpp::web::client::ApiClient::Headers __headers; Z_ADD_HEADERS_smss(__headers, 1); std::unordered_map<oatpp::String, oatpp::String> __pathParams; std::unordered_map<oatpp::String, oatpp::String> __queryParams; std::shared_ptr<oatpp::web::protocol::http::outgoing::Body> __body; __headers.put_LockFree("Authorization", ApiClient::TypeInterpretation<oatpp::String>::toString("oatpp::String", token)); __body = oatpp::web::protocol::http::outgoing::BufferBody::createShared(m_objectMapper->writeToString(dto), m_objectMapper->getInfo().http_content_type); return executeRequest("POST", Z_PATH_TEMPLATE_smss, __headers, __pathParams, __queryParams, __body, __connectionHandle);
	//};
	API_CALL(API_M_POST, "message/smss", smss, API_HANDLER_AUTN_HEADER, BODY_DTO(List<SendMessageDeclDTO::Wrapper>,dto));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

#endif 