#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: y
 @Date: 2023/10/28 13:23:49

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
#ifndef _REMOVE_SUPPLIER_DAO_
#define _REMOVE_SUPPLIER_DAO_
#include "BaseDAO.h"
#include "domain/do/supplier/SupplierDO.h"

/**
 * �޸Ĺ�Ӧ�����ݿ����ʵ��
 */
class RemoveSupplierDAO : public BaseDAO
{
public:

	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_REMOVE_SUPPLIER_DAO_

