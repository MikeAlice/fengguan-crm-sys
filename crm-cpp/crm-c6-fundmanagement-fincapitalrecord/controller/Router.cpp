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
#include "fincapitalrecord/querybankaccount/QueryBankAccountController.h"
#include "fincapitalrecord/querycapitalrecord/QueryCapitalRecordController.h"
#include "fincapitalrecord/addcapitalrecord/AddCapitalRecordController.h"
#include "fincapitalrecord/exportcapitalrecord/ExportCapitalRecordController.h"
#include "fincapitalrecord/removecapitalrecord/RemoveCapitalRecordController.h"

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

	// �ʽ����_�ʽ�ע���ȡ_��ȡ�����˻��б�����		�����ˣ�����
	ROUTER_SIMPLE_BIND(QueryBankAccountController);
	// �ʽ����_�ʽ�ע���ȡ_��ȡ�����б�����+��ҳ��	�����ˣ�����
	ROUTER_SIMPLE_BIND(QueryCapitalRecordController);
	// �ʽ����_�ʽ�ע���ȡ_�������				�����ˣ�����
	ROUTER_SIMPLE_BIND(AddCapitalRecordController);
	// �ʽ����_�ʽ�ע���ȡ_��������				�����ˣ�����
	ROUTER_SIMPLE_BIND(ExportCapitalRecordController);
	// �ʽ����_�ʽ�ע���ȡ_ɾ�����ݣ�֧������ɾ����	�����ˣ�����
	ROUTER_SIMPLE_BIND(RemoveCapitalRecordController);		
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
