#pragma once
/*
 Copyright yunyin. All rights reserved.

 @Author: handeng
 @Date: 2023/10/26
 @FileName:Other_income_statementDAO
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
#include "domain/do/other_income_statement/Other_income_statementDO.h"
#include "domain/dto/other_income_statement/Other_income_statementDTO.h"

/**
 * 负责人：寒灯
 * 描述：导出单据DAO和删除单据DAO
 */
class Other_income_statementDAO : public BaseDAO
{
public:
    // 根据id list查询  负责人：寒灯
    list<Other_income_statementDO> selectWithIdList(const oatpp::List<ExpOisDTO::Wrapper>& dto);
    // 根据id list删除  负责人：寒灯
    uint64_t removeData(const oatpp::List<DelOisDTO::Wrapper>& dto);
    // 其实上面两个Del和Exp的定义源代码是一样的，因为返回的都是id的属性
};

#endif // EXPENDITURESDAO_H__