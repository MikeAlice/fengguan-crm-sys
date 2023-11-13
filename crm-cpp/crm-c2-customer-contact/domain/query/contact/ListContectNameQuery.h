#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/30 10:32:03

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
#ifndef _GETCUSTOMERNAME_QUERY_
#define _GETCUSTOMERNAME_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ListContactNameQuery :public PageQuery
{
	DTO_INIT(ListContactNameQuery, PageQuery);
	//�ͻ�ID
	DTO_FIELD(UInt32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("contact.controller.customer_id");
	}
	// �ͻ�����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contact.controller.query-contact-name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMERNAME_QUERY_