/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
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
#ifndef EXPENDITURESDAO_H__
#define EXPENDITURESDAO_H__
#include "BaseDAO.h"
#include "domain/do/expenditures/ExpendituresDO.h"
#include "domain/dto/expenditures/ExpendituresDTO.h"
#include "domain/query/expenditures/ExpendituresQuery.h"

/**
 * �����ˣ��������Ǹ����
 * ����������֧������DAO
 */
class ExpendituresDAO : public BaseDAO
{
public:
    // ����id list��ѯ  �����ˣ�����
    list<ExpendituresDO> selectWithIdList(const oatpp::List<ExportExpenditures::Wrapper>& dto);
    // ����id listɾ��  �����ˣ�����
    uint64_t removeData(const oatpp::List<DelExpendituresDTO::Wrapper>& dto);
    //��ȡ��ҳ��ѯ�������� �����ˣ��Ǹ����
    uint64_t count(const ExpendituresPageQuery::Wrapper& query);
    //��ȡ�����б�      �����ˣ��Ǹ����
    list<ExpendituresDO> selectWithPage(const ExpendituresPageQuery::Wrapper& query);
    //��������          �����ˣ��Ǹ����
    uint64_t insert(const ExpendituresAddDO& in);
};

#endif // EXPENDITURESDAO_H__