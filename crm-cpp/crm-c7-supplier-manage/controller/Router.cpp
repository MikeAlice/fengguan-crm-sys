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
#include "supplier/querySupFormItem/QuerySupFormItemController.h"
#include "supplier/querySupplierName/QuerySupplierNameController.h"
#include "supplier/modifySupplier/ModifySupplierController.h"
#include "supplier/removeSupplier/RemoveSupplierController.h"
#include "supplier/SupplierController.h"

#include "supplierLinkman/exportSupLinkman/ExportSupLinkmanController.h"
#include "supplierLinkman/sendMessage/SendMessageController.h"
#include "supplierLinkman/modifyLinkman/ModifyLinkmanController.h"
#include "supplierLinkman/removeSupLinkman/RemoveSupLinkmanController.h"
#include "supplierLinkman/basicData/BasicDataController.h"
#include "supplierLinkman/sendEmail/SendEmailController.h"
#include "supplierLinkman/queryLinkmanName/QueryLinkmanNameController.h"
#include "supplierLinkman/SupplierLinkmanController.h"

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
	createSupplier();
	createSupplierLinkman();
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

void Router::createSupplier()
{
	// #TIP: 供应商列表路由定义，写在这个后面
	/**
	 * 获取供应商名称列表
	 * 负责人: Juno
	 */
	ROUTER_SIMPLE_BIND(SupplierNameController);
	/**
	 * 修改供应商
	 * 负责人: Juno
	 */
	ROUTER_SIMPLE_BIND(ModifySupplierController);
	/**
	 * 获取供应商基础信息表单数据项
	 * 负责人: Andrew
	 */
	ROUTER_SIMPLE_BIND(QuerySupFormItemController);
	/**
	 * 获取供应商列表&添加供应商
	 * 负责人: 峰峰峰
	 */
	ROUTER_SIMPLE_BIND(SupplierController);
	/**
	 * 删除供应商
	 * 负责人: y
	 */
	ROUTER_SIMPLE_BIND(RemoveSupplierController);
}

void Router::createSupplierLinkman()
{
	// #TIP: 供应商联系人路由定义，写在这个后面
	/**
	 * 导出供应商联系人
	 * 负责人: Andrew
	 */
	ROUTER_SIMPLE_BIND(ExportSupLinkmanController);
	/**
	 * 发短信
	 * 负责人: 柏下微雨
	 */
	ROUTER_SIMPLE_BIND(SendMessageController);
	/**
	 * 修改供应商联系人
	 * 负责人: tapioca
	 */
	ROUTER_SIMPLE_BIND(ModifyLinkmanController);
	/**
	 * 修改供应商联系人
	 * 负责人: ll
	 */
	ROUTER_SIMPLE_BIND(RemoveSupLinkmanController);
	/**
	 * 获取供应商联系人基础表单数据项
	 * 负责人：。好
	 */
	ROUTER_SIMPLE_BIND(BasicDataController);
	/**
	 * 发送邮件
	 * 负责人：。好
	 */
	ROUTER_SIMPLE_BIND(SendEmailController);
	/**
	 * 获取供应商联系人名称列表
	 * 负责人: 。
	 */
	ROUTER_SIMPLE_BIND(QueryLinkmanNameController);
	/**
	 * 获取供应商联系人列表&添加供应商联系人
	 * 负责人: telephone
	 */
	ROUTER_SIMPLE_BIND(SupplierLinkmanController);
}