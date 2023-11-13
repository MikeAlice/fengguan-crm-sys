/*
 Copyright Zero One Star. All rights reserved.

 @Author: Tapioca
 @Date: 2023/10/25 13:08:09

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

#include "stdafx.h"
#include "UpdateLinkmanService.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "dao/supplierLinkman/updateSupLinkman/LinkmanDAO.h"

bool UpdateLinkmanService::updateLinkmanData(const LinkmanDTO::Wrapper& dto) {
    // 组装DO数据
    SupplierLinkmanDO data;

    //非扩展字段
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        LinkmanId, linkman_id,
        SupplierId, supplier_id,
        Name, name,
        Gender, gender,
        Position, position,
        Tel, tel,
        Mobile, mobile,
        Qicq, qicq,
        Email, email,
        Address, address
    );
    //扩展字段
    std::map<std::string, std::string> ext;
    if (dto->ext_fields->size()) {
        for (size_t i = 0; i < (dto->ext_fields->size()); ++i) {
            ext.insert((dto->ext_fields)[i]);
        }
        data.setExtFields(ext);
    }
    // 执行数据修改
    LinkmanDAO dao;
    return dao.updateLinkman(data) == 1;
}