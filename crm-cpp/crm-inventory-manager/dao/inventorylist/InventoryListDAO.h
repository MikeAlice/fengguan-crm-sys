/*
 Copyright ruodi. All rights reserved.

 @Author: ruodi
 @Date: 2023/10/25
 @FileName:ExpendituresDAO
 @version:1.0

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
#ifndef INVENTORYLISTDAO_H__
#define INVENTORYLISTDAO_H__
#include "BaseDAO.h"
#include "domain/do/inventorylist/InventoryListDO.h"
#include "domain/dto/inventorylist/InventorylistDTO.h"
#include "domain/query/inventorylist/InventoryListQuery.h"

/**
 * �����ˣ�ruodi
 * ����������б�DAO
 */
class InventoryListDAO : public BaseDAO
{
public:
    // ����id list��ѯΪ�˵���  �����ˣ�ruodi
    list<InventoryListDO> select2export(const oatpp::List<ExportInventoryList::Wrapper>& dto);
    // ��ҳ��ѯ
    list<InventoryListDO> selectWithPage(const InventoryListPageQuery::Wrapper& query);
    // ����id listɾ��  �����ˣ�ruodi
    //uint64_t removeData(const oatpp::List<DelInventoryListDTO::Wrapper>& dto);
};

#endif // EXPENDITURESDAO_H__