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
#include "add-pay-record/addPayRecordController.h"
#include "FinInvoiceRece/FinInvoiceReceController.h"
#include "finpayrecord/FinpayrecordController.h"
#include "payplan/PayPlanController.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "get_payment_plan_list/testController.h"
#include "get_payment_plan_list/QueryPaymentPlanController.h"
#include "remove_receipt_record/RemoveReceiptRecordController.h"
#include "export-pay-record/ExportPayRecordController.h"
#include "fin_invoice_rece/exportcapitalrecord/ExportCapitalRecordController.h"
#include "query-invoice-receive/QueryInvoiceReceiveController.h"
#include "confirm_remove_pay/ConfirmRemovePayController.h"
#include "payrecords/PayrecordsController.h"
#include "contractamount/ContractamountController.h"
#include "update-pay-plan/UpdatePayPlanController.h"


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
	////test
	// �󶨲��Կ�����
	//ROUTER_SIMPLE_BIND(TestController);

	//查询付款计划信息(分页) 负责人：灵岚
	ROUTER_SIMPLE_BIND(QueryPaymentPlanController);
	//receipt-record �����ˣ����
	//删除收票记录（可批量） 负责人：灵岚
	ROUTER_SIMPLE_BIND(RemoveReceiptRecordController);
	//添加添加付款记录
	ROUTER_SIMPLE_BIND(AddPayRecordController);
	////添加收票记录
	ROUTER_SIMPLE_BIND(FinInvoiceReceController);
	//负责人：蓝鹤梦
	ROUTER_SIMPLE_BIND(FinpayrecordController);
	//负责人：四一	根据id批量导出付款记录
	ROUTER_SIMPLE_BIND(ExportPayRecordController);
	//负责人：四一	获取收票记录（分页+列表）
	ROUTER_SIMPLE_BIND(QueryInvoiceReceiveController);
	//负责人:邓梓泰	导出收票记录
	ROUTER_SIMPLE_BIND(ExportCapitalRecordController);
	//负责人:rui		确认付款、删除付款计划
	ROUTER_SIMPLE_BIND(ConfirmRemovePayController);
	// 负责人：玛卡巴卡		绑定修改付款计划控制器
	ROUTER_SIMPLE_BIND(UpdatePayPlanController);
	// 负责人：花札卫
	ROUTER_SIMPLE_BIND(PayPlanController);
	//西元	获取付款记录列表
	ROUTER_SIMPLE_BIND(PayrecordsController);
	//西元	获取合同金额消息
	ROUTER_SIMPLE_BIND(ContractamountController);
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
