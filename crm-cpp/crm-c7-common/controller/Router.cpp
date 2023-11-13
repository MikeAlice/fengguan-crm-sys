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

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	// ��ȡ��Ӧ�������б�
	ROUTER_SIMPLE_BIND(QuerySupNameListController);
	// ��ȡ��Ӧ����ϵ�������б�
	ROUTER_SIMPLE_BIND(QueryLinkmanNameListController);
	// ��ȡ�ֿ������б�
	ROUTER_SIMPLE_BIND(WarehouseController);
	// ��ȡ���������б�
	ROUTER_SIMPLE_BIND(AreaController);
	// ��ȡ���������б�&��ȡ��λ�����б�&��ȡ��ɫ�����б�&ϵͳ�û������б�
	ROUTER_SIMPLE_BIND(OrgStructureController);
	// ��ȡ�ͻ������б�&��ȡ��ϵ�������б�
	ROUTER_SIMPLE_BIND(ClientManageController);
	// ��ȡ�����˻��б�����&��ȡ���ÿ�֧���������б�����&��ȡ�����������������б�����
	ROUTER_SIMPLE_BIND(FinanceTypeController);
	// ��ȡָ���ֵ�����Ӧ�ֵ��б�
	ROUTER_SIMPLE_BIND(DataDictController);
	// ��ȡ���ۻ��������б�&��ȡ���ۺ�ͬ�����б�
	ROUTER_SIMPLE_BIND(SaleManageController);
	// ��ȡ��Ʒ���������б���������������б�
	ROUTER_SIMPLE_BIND(QueryGoodsNameListController);
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
