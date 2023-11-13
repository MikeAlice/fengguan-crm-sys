/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/29

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
#include "SalContractListDAO.h"
#include "SalContractListMapper.h"

/**
 * 录入明细条件匹配宏
 */
#define INPUT_TERAM_PARSE(__DO__, __SQL__) \
SqlParams params; \
if (__DO__.getContractID() != -1) { \
	__SQL__ << " `contract_id`,"; \
} \
if (__DO__.getGoodsName() != "") { \
	__SQL__ << " `goods_name`,"; \
} \
if (__DO__.getGoodsID() != -1) { \
	__SQL__ << " `goods_id`,"; \
} \
if (__DO__.getSkuID() != -1) { \
	__SQL__ << " `sku_id`,"; \
} \
if (__DO__.getSkuName() != "") { \
	__SQL__ << " `sku_name`,"; \
} \
if (__DO__.getSalePrice() != -1) { \
	__SQL__ << " `sale_price`,"; \
} \
if (__DO__.getNum() != -1) { \
	__SQL__ << " `num`,"; \
} \
if (__DO__.getGoodsMoney() != -1) { \
	__SQL__ << " `goods_money`,"; \
} \
if (__DO__.getRemarks() != "") { \
	__SQL__ << " `remarks`, "; \
} \
__SQL__ << " `create_time` ";

bool SalContractListDAO::inputList(const SalContractListDO& data)
{
	stringstream ss;
	ss << "INSERT INTO `sal_contract_list` ( ";
	INPUT_TERAM_PARSE(data, ss);
	ss << " ) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ? ) ";
	SQLPARAMS_PUSH(params, "i", int, data.getContractID());
	SQLPARAMS_PUSH(params, "s", string, data.getGoodsName());
	SQLPARAMS_PUSH(params, "i", int, data.getGoodsID());
	SQLPARAMS_PUSH(params, "i", int, data.getSkuID());
	SQLPARAMS_PUSH(params, "s", string, data.getSkuName());
	SQLPARAMS_PUSH(params, "d", double, data.getSalePrice());
	SQLPARAMS_PUSH(params, "i", int, data.getNum());
	SQLPARAMS_PUSH(params, "d", double, data.getGoodsMoney());
	SQLPARAMS_PUSH(params, "s", string, data.getRemarks());
	SQLPARAMS_PUSH(params, "s", string, data.getCreateTime());

	string sql = ss.str();
	return sqlSession->executeUpdate(sql, params);
}
