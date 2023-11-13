/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/27
 @FileName:StorageDetailsDAO
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
#ifndef STORAGEDETAILSDAO_H__
#define STORAGEDETAILSDAO_H__
#include "BaseDAO.h"
#include "domain/do/storagedetails/StorageDetailsDO.h"
#include "domain/dto/storagedetails/StorageDetailsDTO.h"
#include "domain/query/storagedetails/StorageDetailsQuery.h"

/**
 * �����ˣ�����
 * ������StorageDetailsDAO
 */
class StorageDetailsDAO : public BaseDAO
{
public:
	// ����id list��ѯ  �����ˣ�����
	list<StorageDetailsDO> selectWithIdList(const oatpp::List<ExportStorageDetailsDTO::Wrapper>& dto);
	// ��ҳ��ѯ			�����ˣ�����
	list<StorageDetailsDO> selectWithPage(const StorageDetailsQuery::Wrapper& query);
	// ͳ����������
	uint64_t count(const StorageDetailsQuery::Wrapper& query);
    
};

#endif // STORAGEDETAILSDAO_H__