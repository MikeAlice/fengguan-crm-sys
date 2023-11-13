#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/update-pay-plan/UpdatePayPlanDO.h"
#include "../../domain/query/add-pay-record/addPayRecordQuerry.h"

/**
 * 示例表数据库操作实现
 */
class UpdatePayPlanDAO : public BaseDAO
{
public:
	/*
	// 统计数据条数
	uint64_t count(const SampleQuery::Wrapper& query);
	// 分页查询数据
	list<addPayRecordDO> selectWithPage(const SampleQuery::Wrapper& query);
	*/
	// 插入数据
	uint64_t update(const UpdatePayPlanDO& iObj);

	// 通过id查询名称
	std::list<UpdatePayPlanDO> selectContractNameByName(const UpdatePayPlanDO& iObj);
	std::list<UpdatePayPlanDO> selectContractNameById(const UpdatePayPlanDO& iObj);
	std::list<UpdatePayPlanDO> selectSupplierNameByName(const UpdatePayPlanDO& iObj);
	std::list<UpdatePayPlanDO> selectSupplierNameById(const UpdatePayPlanDO& iObj);
	// 通过ID删除数据
//	int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
