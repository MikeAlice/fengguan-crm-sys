#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _TRACE_DO_
#define _TRACE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class TraceDO
{
	//跟踪记录id
	CC_SYNTHESIZE(uint64_t, trace_id, Trace_id);
	//客户名称
	CC_SYNTHESIZE(uint64_t, customer_id, CusId);
	//客户联系人
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkid);
	//客户销售机会
	CC_SYNTHESIZE(uint64_t, chance_id, Chanceid);
	//当前阶段
	CC_SYNTHESIZE(int32_t, salestage, Stage);
	//沟通方式
	CC_SYNTHESIZE(int32_t, salemode, Smode);
	//名称
	CC_SYNTHESIZE(string, name, Name);
	//沟通日期
	CC_SYNTHESIZE(string, conn_time, Ctime);
	// 沟通内容
	CC_SYNTHESIZE(string, intro, Icontent);
	// status
	CC_SYNTHESIZE(uint64_t, status, Status);
	//下次沟通时间
	CC_SYNTHESIZE(string, next_time, Ntime);
	//下次沟通主题
	CC_SYNTHESIZE(string, nexttitle, Ntitle);
	//创建人
	CC_SYNTHESIZE(uint64_t, create_user_id, Createid);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Createtime);

public:
	TraceDO() {
		trace_id = 0;
		customer_id = 1;
		linkman_id = 1;
		chance_id = 1;
		salestage = 1;
		salemode = 49;
		name = "";
		conn_time = "";
		intro = "";
		status = 1;
		next_time = "";
		nexttitle = "";
		create_user_id = 1;
		create_time = "";
	}
};

#endif // !_TRACE_DO_
