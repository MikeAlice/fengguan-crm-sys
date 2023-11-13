/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/10/27 17:35:16

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
#include "../../mapper/ToStringMapper.h"
#include <sstream>
#include "SupplierListDAO.h"
#include "../../mapper/SupplierListMapper.h"

//定义条件解析宏，减少重复代码
#define SUPPLIERLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND a.name LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->telephone) { \
	sql << " AND a.tel LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->telephone.getValue("")); \
} \
if (query->mobile) { \
	sql << " AND a.mobile LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
} \
if (query->address) { \
	sql << "AND	a.address LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->address.getValue("")); \
}

uint64_t SupplierListDAO::count(const SupplierQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sup_supplier AS a LEFT JOIN sup_linkman AS b ON a.linkman = b.linkman_id";
	SUPPLIERLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// 分页查询数据
list<SupplierDO> SupplierListDAO::selectWithPage(const SupplierQuery::Wrapper& query) {
	// 查询扩展字段
	stringstream get_fields;
	get_fields << "SELECT field_name FROM cst_field_ext WHERE `main_table` = 'sup_supplier' AND `ext_table` = 'sup_supplier'";
	std::string get_fields_str = get_fields.str();
	ToStringMapper ext_mapper;
	std::list<std::string> ext = sqlSession->executeQuery<std::string, ToStringMapper>(get_fields_str, ext_mapper);

	stringstream sql;
	sql << "SELECT a.supplier_id, a.name, a.area_id, a.create_user_id, a.level, a.ecotype, a.trade, a.satisfy, a.credit, a.address, a.linkman, a.website, a.zipcode, a.tel, a.fax, a.email, a.intro, a.create_time, b.name";
	for (auto item : ext) {
		sql << ", " << item;
	}
	sql << " FROM sup_supplier AS a LEFT JOIN sup_linkman AS b ON a.linkman = b.linkman_id";
	SUPPLIERLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SupplierListMapper mapper(ext);
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SupplierDO, SupplierListMapper>(sqlStr, mapper, params);
}
// 插入数据
#define INSERT_PARAM_PARSE(_DO_, _SQL_, _EXT_) \
SqlParams params; \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getName()); \
SQLPARAMS_PUSH(params, "ull", uint64_t, _DO_.getEcotype()); \
SQLPARAMS_PUSH(params, "ull", uint64_t, _DO_.getTrade()); \
SQLPARAMS_PUSH(params, "ull", uint64_t, _DO_.getLinkman()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getTel()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getFax()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getEmail()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getAddress()); \
SQLPARAMS_PUSH(params, "s", std::string, _DO_.getIntro()); \
for (auto item : _EXT_) \
{ \
	_SQL_ << ", ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, item.second); \
}
uint64_t SupplierListDAO::insert(const SupplierDO& iObj) {
	std::map<std::string, std::string> ext = iObj.getExtFields();
	
	stringstream sql;
	sql << "INSERT INTO `sup_supplier` (`name`, `ecotype`, `trade`,  `linkman`, `tel`, `fax`, `email`, `address`, `intro`";
	// 扩展字段
	for (auto item : ext) {
		sql << ", `" << item.first << "`";
	}
	sql << ") VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?";
	INSERT_PARAM_PARSE(iObj, sql, ext);
	sql << ")";
	std::string sql_str = sql.str();
	return sqlSession->executeInsert(sql_str, params);
}