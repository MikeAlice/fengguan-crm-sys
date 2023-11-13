/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/25
 @FileName:StorageDetailsService
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
#ifndef STORAGEDETAILSSERVICE_H__
#define STORAGEDETAILSSERVICE_H__
#include "domain/dto/storagedetails/StorageDetailsDTO.h"
#include "domain/query/storagedetails/StorageDetailsQuery.h"

class StorageDetailsService
{
public:
    // 分页查询入库明细     负责人：云隐
    StorageDetailsPageDTO::Wrapper listAll(const StorageDetailsQuery::Wrapper& query);
    // 导出入库明细         负责人：云隐
    std::string exportData(const oatpp::List<ExportStorageDetailsDTO::Wrapper> storagedetailsQuery);
    // 获取标题             负责人：云隐
    vector<string> getTitles();
};

#endif // STORAGEDETAILSSERVICE_H__