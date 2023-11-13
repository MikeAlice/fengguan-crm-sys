#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
//#include "controller/getindex/GetSalesOppoController.h"
#include "controller/opportunityindex/SalesOpController.h"
#include "saleopport/SaleopportController.h"
//#include "controller/getindex/OpportunityController.h"
#include "controller/opportunities/OpportunityController.h"
#include "controller/opportunities/SmsMail.h"

// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
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

	//�󶨿�����
	//ROUTER_SIMPLE_BIND(GetSalesOppoController);//��ȡ���ۻ����ƻ��б���������������б�
	ROUTER_SIMPLE_BIND(SaleopportController);//��ȡ���ۻ����б���ҳ+������
	ROUTER_SIMPLE_BIND(SalesOpController);//������ۻ��ᡢ�޸����ۻ��ᡢɾ�����ۻ��ᣨ֧������ɾ����
	ROUTER_SIMPLE_BIND(OpportunityController);//�������ۻ���
	ROUTER_SIMPLE_BIND(MallController);//�����ţ�֧��������
	ROUTER_SIMPLE_BIND(SmsController);//���ʼ���֧��������

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);
	
	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif
