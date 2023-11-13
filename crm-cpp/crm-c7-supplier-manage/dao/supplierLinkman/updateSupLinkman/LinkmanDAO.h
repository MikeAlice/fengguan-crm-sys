#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Tapioca
 @Date: 2023/10/25 14:58:39

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
#ifndef _LINKMANDAO_H_
#define _LINKMANDAO_H_
#include "BaseDAO.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "domain/dto/supplierLinkman/LinkmanDTO.h"

/**
 * 修改供应商联系人DAO层
 * 负责人: tapioca
 */
class LinkmanDAO : public BaseDAO
{
public:
    // 修改联系人数据
    int updateLinkman(const SupplierLinkmanDO& uObj);
};

#endif // !_LINKMANDAO_H_