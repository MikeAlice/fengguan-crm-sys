#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/23 16:38:00

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
#ifndef _SERVICE_DO_
#define _SERVICE_DO_
#include "../DoInclude.h"

/**
 * �����¼���ݿ�ʵ����
 */
class ServiceDO
{
	//�����¼���
	CC_SYNTHESIZE(int32_t, service_id, Service_id);
	//�ͻ����
	CC_SYNTHESIZE(int, customer_id, Customer_id);
	//��ϵ�˱��
	CC_SYNTHESIZE(int, linkman_id, Linkman_id);
	//��������
	CC_SYNTHESIZE(int, services, Services);
	////��������
	//CC_SYNTHESIZE(int, services, Services);
	//����ʽ
	CC_SYNTHESIZE(int, servicesmodel, Servicesmodel);
	////����ʽ
	//CC_SYNTHESIZE(int, servicesmodel, Servicesmodel);
	//�۸�
	CC_SYNTHESIZE(int, price, Price);
	//����״̬
	CC_SYNTHESIZE(int, status, Status);
	//��������
	CC_SYNTHESIZE(string, service_time, Service_time);
	//����ʱ��
	CC_SYNTHESIZE(string, tlen, Tlen);
	//��������
	CC_SYNTHESIZE(string, content, Content);
	//��ע
	CC_SYNTHESIZE(string, intro, Intro);
	//�����߱��
	CC_SYNTHESIZE(int, create_user_id, Create_user_id);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//�ͻ�����
	CC_SYNTHESIZE(string, customer_name, Customer_name);

public:
	ServiceDO() {
		customer_id = 1;
		linkman_id = 1;
		services = 1;
		servicesmodel = 1;
		price = 1;
		status = 1;
		service_time = "2018-10-13 14:50:11";
		tlen = "60";
		content = "phone call";
		intro = "";
		create_user_id = 1;
		create_time = "2018-10-13 14:50:11";
	}
};


///**
// * �����¼���ݿ�ʵ����
// */
//class ServiceDO
//{
//	//�����¼���
//	CC_SYNTHESIZE(uint64_t, service_id, Service_id);
//	//�ͻ����
//	CC_SYNTHESIZE(int, customer_id, Customer_id);
//	//��ϵ�˱��
//	CC_SYNTHESIZE(int, linkman_id, Linkman_id);
//	//��������
//	CC_SYNTHESIZE(int, services, Services);
//	//����ʽ
//	CC_SYNTHESIZE(int, servicesmodel, Servicesmodel);
//	//�۸�
//	CC_SYNTHESIZE(int, price, Price);
//	//����״̬
//	CC_SYNTHESIZE(int, status, Status);
//	//��������
//	CC_SYNTHESIZE(string, service_time, Service_time);
//	//����ʱ��
//	CC_SYNTHESIZE(string, tlen, Tlen);
//	//��������
//	CC_SYNTHESIZE(string, content, Content);
//	//��ע
//	CC_SYNTHESIZE(string, intro, Intro);
//	//�����߱��
//	CC_SYNTHESIZE(int, create_user_id, Create_user_id);
//	//����ʱ��
//	CC_SYNTHESIZE(string, create_time, Create_time);
//
//public:
//	ServiceDO() {
//		customer_id = 1;
//		linkman_id = 1;
//		services = 1;
//		servicesmodel = 1;
//		price = 1;
//		status = 1;
//		service_time = "2018-10-13 14:50:11";
//		tlen = "60";
//		content = "phone call";
//		intro = "";
//		create_user_id = 1;
//		create_time = "2018-10-13 14:50:11";
//	}
//};
#endif // !_SERVICE_DO_
