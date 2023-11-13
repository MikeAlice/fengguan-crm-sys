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
 * 负责人：云隐、是个天才
 * 描述：费用支出单据DAO
 */
class ExpendituresDAO : public BaseDAO
{
public:
    // 根据id list查询  负责人：云隐
    list<ExpendituresDO> selectWithIdList(const oatpp::List<ExportExpenditures::Wrapper>& dto);
    // 根据id list删除  负责人：云隐
    uint64_t removeData(const oatpp::List<DelExpendituresDTO::Wrapper>& dto);
    //获取分页查询数据条数 负责人：是个天才
    uint64_t count(const ExpendituresPageQuery::Wrapper& query);
    //获取单据列表      负责人：是个天才
    list<ExpendituresDO> selectWithPage(const ExpendituresPageQuery::Wrapper& query);
    //新增单据          负责人：是个天才
    uint64_t insert(const ExpendituresAddDO& in);
};

#endif // EXPENDITURESDAO_H__