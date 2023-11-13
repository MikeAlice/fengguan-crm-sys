#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/09 20:32:13

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
#ifndef _OTHERCOMMPONENT_H_
#define _OTHERCOMMPONENT_H_
#include "AbstractComponentReg.h"

#ifdef HTTP_SERVER_DEMO
#include "oatpp-websocket/ConnectionHandler.hpp"
#include "uselib/ws/WSInstanceListener.h"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#endif

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"

/**
 * 其它Oatpp组件注册附件，后续如果需要附加其它组件可以在这里进行外部定义
 */
class OtherComponent : public AbstractComponentReg
{
	// 定义RequestExecutor组件用于发送Api请求
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, msgServerApiExecutor)("msg-server-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "8.130.105.4", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());

#ifdef HTTP_SERVER_DEMO
	// 定义一个WebSocket组件用于演示WebSocket的使用
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler)("websocket", [] {
		auto connectionHandler = oatpp::websocket::ConnectionHandler::createShared();
		connectionHandler->setSocketInstanceListener(std::make_shared<WSInstanceListener>());
		return connectionHandler;
		}());
	// 定义一个示例RequestExecutor组件用于发送api请求
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, sampleApiExecutor)("sample-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "192.168.31.99", 10100 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
#endif
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, localApiExecutor)("localhost-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "127.0.0.1", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
};

#endif // _OTHERCOMMPONENT_H_