/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/28 0:20:54

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
#include "InsertSupLinkmanDAO.h"
#include "SimpleDateTimeFormat.h"

#define INSERT_PARAM_PARSE(_DO_, _SQL_, _EXT_) \
SqlParams params; \
SQLPARAMS_PUSH(params, "ull", uint64_t, _DO_.getSupplierId()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getName()); \
SQLPARAMS_PUSH(params, "ull", uint64_t, _DO_.getGender()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getPosition()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getTel()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getMobile()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getQicq()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getEmail()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getAddress()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getIntro()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getCreateTime()); \
SQLPARAMS_PUSH(params, "ull", uint64_t, _DO_.getCreateUserId()); \
for (auto item : _EXT_) \
{ \
	_SQL_ << ", ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, item.second); \
}

#define DYNAMIC_TERM_PARSE(_FMT_, _TYPE_, _VAL_) \
if (dto->_VAL_) \
{ \
	SQLPARAMS_PUSH(params, _FMT_, _TYPE_, dto->_VAL_.getValue({})); \
	ins << ", `" << #_VAL_ << "`"; \
	val << ", ?"; \
}

uint64_t InsertSupLinkmanDAO::insert(const SupplierLinkmanDO& data)
{
	// ¹¹½¨SQLÓï¾ä
	stringstream sql;
	sql << "INSERT INTO `sup_linkman` (`supplier_id`, `name`, `gender`, `position`, `tel`, `mobile`, `qicq`, `email`, `address`, `intro`, `create_time`, `create_user_id`";
	// À©Õ¹×Ö¶Î
	for (auto item : data.getExtFields())
		sql << ", `" << item.first << "`";
	sql << ") VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
	
	INSERT_PARAM_PARSE(data, sql, data.getExtFields());
	sql << ")";
	std::string sql_str = sql.str();
	return sqlSession->executeInsert(sql_str, params);
}

uint64_t InsertSupLinkmanDAO::insert(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	stringstream ins, val;
	ins << "INSERT INTO `sup_linkman` (`create_time`, `create_user_id`";
	val << ") VALUES(?, ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, SimpleDateTimeFormat::format());
	SQLPARAMS_PUSH(params, "ull", uint64_t, std::stoull(payload.getId()));
	DYNAMIC_TERM_PARSE("s", std::string, name);
	DYNAMIC_TERM_PARSE("ull", uint64_t, supplier_id);
	DYNAMIC_TERM_PARSE("ull", uint64_t, gender);
	DYNAMIC_TERM_PARSE("s", std::string, position);
	DYNAMIC_TERM_PARSE("s", std::string, tel);
	DYNAMIC_TERM_PARSE("s", std::string, mobile);
	DYNAMIC_TERM_PARSE("s", std::string, qicq);
	DYNAMIC_TERM_PARSE("s", std::string, email);
	DYNAMIC_TERM_PARSE("s", std::string, address);
	DYNAMIC_TERM_PARSE("s", std::string, intro);
	for (auto item : *(dto->ext_fields))
	{
		SQLPARAMS_PUSH(params, "s", std::string, item.second);
		ins << ", `" << item.first.getValue({}) << "`";
		val << ", ?";
	}
	val << ")";
	std::string sql = ins.str() + val.str();
	return sqlSession->executeInsert(sql, params);
}
