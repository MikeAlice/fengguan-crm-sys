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
#include "controller/deletecustormer/DeleteCustormerController.h"
#include "controller/hightsea/HightSeaController.h"
#include "controller/customerinfo/GetCustormerInfoController.h"
#include "controller/getcustomername/GetCustomerNameController.h"
#include "controller/getcutomerdetails/GetCustomerDetailsController.h"
#include "controller/getcustomer/GetCustomerController.h"
#include "controller/customer/CustomerController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif


#include "customerfile/ExportController.h"
#include "customerfile/ImportController.h"// 如果定义了关闭Swagger文档宏
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

	ROUTER_SIMPLE_BIND(GetCustomerNameController); //负责人：laoli
	ROUTER_SIMPLE_BIND(GetCustomerController); //负责人：laoli
	ROUTER_SIMPLE_BIND(GetCustomerDetailsController);		//负责人：lsc
	// 绑定获取客户基础信息接口
	ROUTER_SIMPLE_BIND(GetCustormerInfoController);	//负责人：电耗子

	ROUTER_SIMPLE_BIND(CustomerController);//负责人：fgg永恒

	// 绑定删除客户接口
	ROUTER_SIMPLE_BIND(DeleteCustormerController);	//负责人：电耗子
	// 绑定投入公海接口
	ROUTER_SIMPLE_BIND(HightSeaController);	//负责人：电耗子
	// 绑定导入导出接口
	ROUTER_SIMPLE_BIND(ExportController);	//负责人：老菌
	ROUTER_SIMPLE_BIND(ImportController);	//负责人：老菌

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
