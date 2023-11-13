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
 * 服务记录数据库实体类
 */
class ServiceDO
{
	//服务记录编号
	CC_SYNTHESIZE(int32_t, service_id, Service_id);
	//客户编号
	CC_SYNTHESIZE(int, customer_id, Customer_id);
	//联系人编号
	CC_SYNTHESIZE(int, linkman_id, Linkman_id);
	//服务类型
	CC_SYNTHESIZE(int, services, Services);
	////服务类型
	//CC_SYNTHESIZE(int, services, Services);
	//服务方式
	CC_SYNTHESIZE(int, servicesmodel, Servicesmodel);
	////服务方式
	//CC_SYNTHESIZE(int, servicesmodel, Servicesmodel);
	//价格
	CC_SYNTHESIZE(int, price, Price);
	//服务状态
	CC_SYNTHESIZE(int, status, Status);
	//服务日期
	CC_SYNTHESIZE(string, service_time, Service_time);
	//服务时长
	CC_SYNTHESIZE(string, tlen, Tlen);
	//服务内容
	CC_SYNTHESIZE(string, content, Content);
	//备注
	CC_SYNTHESIZE(string, intro, Intro);
	//创建者编号
	CC_SYNTHESIZE(int, create_user_id, Create_user_id);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//客户名称
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
// * 服务记录数据库实体类
// */
//class ServiceDO
//{
//	//服务记录编号
//	CC_SYNTHESIZE(uint64_t, service_id, Service_id);
//	//客户编号
//	CC_SYNTHESIZE(int, customer_id, Customer_id);
//	//联系人编号
//	CC_SYNTHESIZE(int, linkman_id, Linkman_id);
//	//服务类型
//	CC_SYNTHESIZE(int, services, Services);
//	//服务方式
//	CC_SYNTHESIZE(int, servicesmodel, Servicesmodel);
//	//价格
//	CC_SYNTHESIZE(int, price, Price);
//	//服务状态
//	CC_SYNTHESIZE(int, status, Status);
//	//服务日期
//	CC_SYNTHESIZE(string, service_time, Service_time);
//	//服务时长
//	CC_SYNTHESIZE(string, tlen, Tlen);
//	//服务内容
//	CC_SYNTHESIZE(string, content, Content);
//	//备注
//	CC_SYNTHESIZE(string, intro, Intro);
//	//创建者编号
//	CC_SYNTHESIZE(int, create_user_id, Create_user_id);
//	//创建时间
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
