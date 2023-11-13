/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "querySupNameList/QuerySupNameListController.h"
#include "queryLinkmanNameList/QueryLinkmanNameListController.h"
#include "warehouse/WarehouseController.h"
#include "area/AreaController.h"
#include "orgStructure/OrgStructureController.h"
#include "clientManage/ClientManageController.h"
#include "financeType/FinanceTypeController.h"
#include "dataDict/DataDictController.h"
#include "saleManage/SaleManageController.h"
#include "queryGoodsName/QueryGoodsNameListController.h"

// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :系统扩展路由定义，写在这个后面
	// 获取供应商名称列表
	ROUTER_SIMPLE_BIND(QuerySupNameListController);
	// 获取供应商联系人名称列表
	ROUTER_SIMPLE_BIND(QueryLinkmanNameListController);
	// 获取仓库名称列表
	ROUTER_SIMPLE_BIND(WarehouseController);
	// 获取区域名称列表
	ROUTER_SIMPLE_BIND(AreaController);
	// 获取部门名称列表&获取岗位名称列表&获取角色名称列表&系统用户名称列表
	ROUTER_SIMPLE_BIND(OrgStructureController);
	// 获取客户名称列表&获取联系人名称列表
	ROUTER_SIMPLE_BIND(ClientManageController);
	// 获取银行账户列表数据&获取费用开支类型名称列表数据&获取费用收入类型名称列表数据
	ROUTER_SIMPLE_BIND(FinanceTypeController);
	// 获取指定字典分类对应字典列表
	ROUTER_SIMPLE_BIND(DataDictController);
	// 获取销售机会名称列表&获取销售合同名称列表
	ROUTER_SIMPLE_BIND(SaleManageController);
	// 获取商品类型名称列表（用于输入表单下拉列表）
	ROUTER_SIMPLE_BIND(QueryGoodsNameListController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif
