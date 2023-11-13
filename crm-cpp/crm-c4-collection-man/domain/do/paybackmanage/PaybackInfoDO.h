#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 愿你道路悠长
 @Date: 2022/10/25 11:52:32

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
#ifndef _PAYBACKINFO_DO_
#define _PAYBACKINFO_DO_
#include "../DoInclude.h"

/**
 * 回款合同信息数据库实体类
 */
class PaybackInfoDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 总金额
	CC_SYNTHESIZE(uint64_t, totalamount, Tamo);
	// 去零金额
	CC_SYNTHESIZE(uint64_t, zeroamount, Zamo);
	// 已经回款金额
	CC_SYNTHESIZE(uint64_t, refundedamount, Ramo);
	// 已开发票金额
	CC_SYNTHESIZE(uint64_t, invoicedamount, Iamo);
public:
	PaybackInfoDO() {
		id = 0;
		totalamount = -1;
		zeroamount = -1;
		refundedamount = -1;
		invoicedamount = -1;
	}
};

#endif // !_SAMPLE_DO_
