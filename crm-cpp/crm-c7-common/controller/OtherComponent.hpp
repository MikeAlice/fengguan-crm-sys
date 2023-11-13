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
	// 供应商管理模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, supplierApiExecutor)("supplier-name-list-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "8.130.14.225", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 仓库管理模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, warehouseExecutor)("warehouse-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "8.130.82.226", 10033 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 地区管理模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, areaExecutor)("area-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "118.31.61.96", 10031 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 组织结构模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, orgStructureExecutor)("org-structure-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "101.34.252.80", 10110 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 客户管理模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, clientManageExecutor)("client-manage-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "8.130.17.229", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
    // 联系人管理模块组件
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, contactManageExecutor)("contact-name-api", [] {
        auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "39.101.68.215", 8090 });
        return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
        }());
	// 财务类型&字典数据模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, financeTypeExecutor)("finance-type-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "8.130.16.24", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 销售机会模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, saleOpportunityExecutor)("sale-opportunity-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "124.221.254.153", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 销售合同模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, saleContractExecutor)("sale-contract-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "43.138.164.141", 8090 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
	// 商品类型名称列表模块组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, goodsNameExecutor)("get-goodsName-api", [] {
		auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "47.115.221.50", 10086 });
		return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
		}());
};

#endif // _OTHERCOMMPONENT_H_