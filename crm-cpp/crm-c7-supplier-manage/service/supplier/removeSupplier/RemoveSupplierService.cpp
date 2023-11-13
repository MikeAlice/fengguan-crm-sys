/*
 Copyright Zero One Star. All rights reserved.

 @Author: y
 @Date: 2023/10/27 21:18:56

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

#include <list>
#include "stdafx.h"
#include "RemoveSupplierService.h"
#include "dao/supplier/removeSupplier/RemoveSupplierDAO.h"
#include "domain/do/supplier/SupplierDO.h"

bool RemoveSupplierService::removeSupplierData(const RemoveSupplierDTO::Wrapper& dto)
{
	RemoveSupplierDAO dao;
	bool flag = true;

	auto sqlSession = dao.getSqlSession();
	sqlSession->beginTransaction();
	for (oatpp::UInt64 item : *(dto->rows))
	{
		if (!dao.deleteById(item))
		{
			sqlSession->rollbackTransaction();
			flag = false;
			break;
		}
	}
	sqlSession->commitTransaction();
	return flag;
}



