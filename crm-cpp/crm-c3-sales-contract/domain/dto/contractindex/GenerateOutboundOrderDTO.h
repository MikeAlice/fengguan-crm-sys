#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _DETAILSCUSTOMER_DTO_
#define _DETAILSCUSTOMER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ͻ����鴫�����
 */
class GenerateOutboundOrderDTO : public oatpp::DTO
{
	DTO_INIT(GenerateOutboundOrderDTO, DTO);
	// �ͻ�ID
	DTO_FIELD(UInt32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("customer.field.customer_id");
	}
	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("customer.field.name"));

	// �ͻ����
	API_DTO_FIELD_DEFAULT(UInt32, customer_no, ZH_WORDS_GETTER("customer.field.customer_no"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, create_user_id, ZH_WORDS_GETTER("customer.field.create_user_id"));

	// ������Ա����
	API_DTO_FIELD_DEFAULT(String, create_user_name, ZH_WORDS_GETTER("customer.field.create_user_name"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("customer.field.owner_user_id"));

	// ������Ա����
	API_DTO_FIELD_DEFAULT(String, owner_user_name, ZH_WORDS_GETTER("customer.field.owner_user_name"));

	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("customer.field.create_time"));

	//�´ι�ͨʱ��
	API_DTO_FIELD_DEFAULT(String, next_time, ZH_WORDS_GETTER("customer.field.next_time"));

	//�����ϵʱ��
	API_DTO_FIELD_DEFAULT(String, conn_time, ZH_WORDS_GETTER("customer.field.conn_time"));

	//�����ͨ����
	API_DTO_FIELD_DEFAULT(String, conn_body, ZH_WORDS_GETTER("customer.field.conn_body"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, linkman, ZH_WORDS_GETTER("customer.field.linkman"));

	//�ͻ���Դ
	API_DTO_FIELD_DEFAULT(String, source, ZH_WORDS_GETTER("customer.field.source"));

	//�ͻ��ȼ�
	API_DTO_FIELD_DEFAULT(String, grade, ZH_WORDS_GETTER("customer.field.grade"));

	//�ͻ���ҵ
	API_DTO_FIELD_DEFAULT(String, industry, ZH_WORDS_GETTER("customer.field.industry"));

	//��ϵ�ֻ�
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("customer.field.mobile"));

	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("customer.field.tel"));

	//��ϵ��ַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("customer.field.address"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("customer.field.intro"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, needs, ZH_WORDS_GETTER("customer.field.needs"));
};

/**
 * �ͻ������ҳ�������
 */
class GenerateOutboundOrderPageDTO : public PageDTO<GenerateOutboundOrderDTO::Wrapper>
{
	DTO_INIT(GenerateOutboundOrderPageDTO, PageDTO<GenerateOutboundOrderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DETAILSCUSTOMER_DTO_