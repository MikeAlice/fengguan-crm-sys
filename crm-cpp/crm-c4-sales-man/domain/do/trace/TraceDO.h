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
 * ʾ�����ݿ�ʵ����
 */
class TraceDO
{
	//���ټ�¼id
	CC_SYNTHESIZE(uint64_t, trace_id, Trace_id);
	//�ͻ�����
	CC_SYNTHESIZE(uint64_t, customer_id, CusId);
	//�ͻ���ϵ��
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkid);
	//�ͻ����ۻ���
	CC_SYNTHESIZE(uint64_t, chance_id, Chanceid);
	//��ǰ�׶�
	CC_SYNTHESIZE(int32_t, salestage, Stage);
	//��ͨ��ʽ
	CC_SYNTHESIZE(int32_t, salemode, Smode);
	//����
	CC_SYNTHESIZE(string, name, Name);
	//��ͨ����
	CC_SYNTHESIZE(string, conn_time, Ctime);
	// ��ͨ����
	CC_SYNTHESIZE(string, intro, Icontent);
	// status
	CC_SYNTHESIZE(uint64_t, status, Status);
	//�´ι�ͨʱ��
	CC_SYNTHESIZE(string, next_time, Ntime);
	//�´ι�ͨ����
	CC_SYNTHESIZE(string, nexttitle, Ntitle);
	//������
	CC_SYNTHESIZE(uint64_t, create_user_id, Createid);
	//����ʱ��
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
