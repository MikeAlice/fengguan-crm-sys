/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 19:21:52

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
#include "ExportSupLinkmanDAO.h"
#include "domain/do/cstFieldExt/CstFieldExtDO.h"
#include "dao/mapper/CstFieldExtMapper.h"
#include "dao/mapper/SupplierLinkmanMapper.h"
#include "dao/mapper/ToStringMapper.h"

#define EXPORT_TERM_PARSE(_QUERY_, _SQL_) \
SqlParams params; \
_SQL_ << " WHERE 1=1"; \
if (_QUERY_->keywords) { \
	_SQL_ << " AND (a.name=? OR a.tel=? OR a.mobile=? OR a.qicq=?)"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue("")); \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue("")); \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue("")); \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->keywords.getValue("")); \
} \
if (_QUERY_->address) {	\
	_SQL_ << " AND a.address=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->address.getValue("")); \
} \
if (_QUERY_->supplier_name) { \
	_SQL_ << " AND b.supplier_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, _QUERY_->supplier_name.getValue("")); \
}

std::list<SupplierLinkmanDO> ExportSupLinkmanDAO::selectAll(const ExportSupLinkmanQuery::Wrapper& query, const std::list<std::string>& extends)
{
	stringstream sql;
	sql << "SELECT a.linkman_id, a.supplier_id, b.name AS supplier_name, a.name, a.gender, a.position, a.tel, a.mobile, a.qicq, a.email, a.zipcode, a.address, a.intro, a.create_time, a.create_user_id";
	for (std::string item : extends)
		sql << ", a." << item;
	sql << " FROM sup_linkman AS a LEFT JOIN sup_supplier AS b ON a.supplier_id = b.supplier_id";
	EXPORT_TERM_PARSE(query, sql);
	std::string sql_str = sql.str();
	SupplierLinkmanMapper mapper(extends);
	return sqlSession->executeQuery<SupplierLinkmanDO, SupplierLinkmanMapper>(sql_str, mapper, params);
}

std::list<std::string> ExportSupLinkmanDAO::selectField(const std::string& table)
{
	stringstream sql;
	sql << "DESC " << table;
	std::string sql_str = sql.str();
	ToStringMapper mapper;
	return sqlSession->executeQuery<std::string, ToStringMapper>(sql_str, mapper);
}

std::list<std::string> ExportSupLinkmanDAO::selectExtField()
{
	// ²éÑ¯À©Õ¹×Ö¶Î
	stringstream get_fields;
	get_fields << "SELECT field_name FROM cst_field_ext WHERE `main_table`='sup_linkman' AND `ext_table`='sup_linkman'";
	std::string get_fields_str = get_fields.str();
	ToStringMapper ext_mapper;
	return sqlSession->executeQuery<std::string, ToStringMapper>(get_fields_str, ext_mapper);
}
