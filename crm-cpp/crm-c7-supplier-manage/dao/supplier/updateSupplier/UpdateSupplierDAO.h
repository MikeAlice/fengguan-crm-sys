#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/25 18:23:49

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
#ifndef _UPDATE_SUPPLIER_DAO_
#define _UPDATE_SUPPLIER_DAO_
#include "BaseDAO.h"
#include "domain/do/supplier/SupplierDO.h"
#include "domain/dto/supplier/ModifySupplierDTO.h"

/**
 * �޸Ĺ�Ӧ�����ݿ����ʵ��
 */
class UpdateSupplierDAO : public BaseDAO
{
public:
	// �޸�����
	int updateSupplierStatic(const SupplierDO& uObj);//�޸ľ�̬�ֶ�
	int updateSupplierExtFields(const SupplierDO& uObj, const ModifySupplierDTO::Wrapper& dto);//�޸���չ�ֶ�
	int updateSupplierExtFields(const SupplierDO& uObj);//�޸���չ�ֶ�
};
#endif // !_UPDATE_SUPPLIER_DAO_

