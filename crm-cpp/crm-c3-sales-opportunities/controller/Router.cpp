#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
//#include "controller/getindex/GetSalesOppoController.h"
#include "controller/opportunityindex/SalesOpController.h"
#include "saleopport/SaleopportController.h"
//#include "controller/getindex/OpportunityController.h"
#include "controller/opportunities/OpportunityController.h"
#include "controller/opportunities/SmsMail.h"

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

	//绑定控制器
	//ROUTER_SIMPLE_BIND(GetSalesOppoController);//获取销售机名称会列表（用于输入表单下拉列表）
	ROUTER_SIMPLE_BIND(SaleopportController);//获取销售机会列表（分页+条件）
	ROUTER_SIMPLE_BIND(SalesOpController);//添加销售机会、修改销售机会、删除销售机会（支持批量删除）
	ROUTER_SIMPLE_BIND(OpportunityController);//导出销售机会
	ROUTER_SIMPLE_BIND(MallController);//发短信（支持批量）
	ROUTER_SIMPLE_BIND(SmsController);//发邮件（支持批量）

	//#TIP :系统扩展路由定义，写在这个后面
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
