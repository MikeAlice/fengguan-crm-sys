/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/01 0:20:25

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
#include "SelectSupLinkmanDAO.h"
#include "dao/mapper/ToStringMapper.h"
#include "dao/mapper/SupplierLinkmanMapper.h"

#define QUERY_TERM_PARSE(_SQL_, _QUERY_) \
SqlParams params; \
_SQL_ << " WHERE 1=1"; \
if (_QUERY_->keywords) \
{ \
	_SQL_ << " AND (a.name LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue({})); \
	_SQL_ << " OR a.tel LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue({})); \
	_SQL_ << " OR a.mobile LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue({})); \
	_SQL_ << " OR a.qicq LIKE CONCAT('%', ?, '%'))"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue({})); \
} \
if (_QUERY_->supplier_name) \
{ \
	_SQL_ << " AND b.name LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->supplier_name.getValue({})); \
} \
if (_QUERY_->address) \
{ \
	_SQL_ << " AND a.address LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->address.getValue({})); \
}

uint64_t SelectSupLinkmanDAO::count(const SupplierLinkmanQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(a.linkman_id) FROM sup_linkman AS a LEFT JOIN sup_supplier AS b ON a.supplier_id = b.supplier_id";
	QUERY_TERM_PARSE(sql, query);
	std::string sql_str = sql.str();
	return sqlSession->executeQueryNumerical(sql_str, params);
}

std::list<SupplierLinkmanDO> SelectSupLinkmanDAO::selectAll(const SupplierLinkmanQuery::Wrapper& query, const std::list<std::string>& extends)
{
	stringstream sql;
	sql << "SELECT a.linkman_id, a.supplier_id, b.name, a.name, a.gender, a.position, a.tel, a.mobile, a.qicq, a.email, a.zipcode, a.address, a.intro, a.create_time, a.create_user_id";
	// À©Õ¹×Ö¶Î
	for (auto item : extends)
		sql << ", " << item;
	sql << " FROM sup_linkman AS a LEFT JOIN sup_supplier AS b ON a.supplier_id = b.supplier_id";
	QUERY_TERM_PARSE(sql, query);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << ", " << query->pageSize;
	SupplierLinkmanMapper mapper(extends);
	std::string sql_str = sql.str();
	return sqlSession->executeQuery<SupplierLinkmanDO, SupplierLinkmanMapper>(sql_str, mapper, params);
}

std::list<std::string> SelectSupLinkmanDAO::selectExtField()
{
	// ²éÑ¯À©Õ¹×Ö¶Î
	stringstream get_fields;
	get_fields << "SELECT field_name FROM cst_field_ext WHERE `main_table`='sup_linkman' AND `ext_table`='sup_linkman'";
	std::string get_fields_str = get_fields.str();
	ToStringMapper ext_mapper;
	return sqlSession->executeQuery<std::string, ToStringMapper>(get_fields_str, ext_mapper);
}
