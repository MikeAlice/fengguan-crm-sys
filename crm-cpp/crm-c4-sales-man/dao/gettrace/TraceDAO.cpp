/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "TraceDAO.h"
#include "TraceMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define TRACE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->AC) { \
	sql << " AND t.customer_id in (SELECT customer_id FROM cst_customer WHERE `name` LIKE CONCAT('%', ?, '%'))"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->AC.getValue("")); \
} \
if (query->CContent) { \
	sql << " AND t.intro LIKE CONCAT('%', ?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->CContent.getValue("")); \
} \
if (query->CS) { \
	sql << " AND t.salestage=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->CS.getValue(0)); \
}

// 统计数据条数
uint64_t TraceDAO::count(const TraceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cst_trace t";
	TRACE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询数据
std::list<AllDO> TraceDAO::selectWithPage(const TraceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t.customer_id,t.linkman_id,t.chance_id,t.salestage,t.salemode,t.conn_time,t.intro,t.next_time,c.name,ds.name,dm.name FROM cst_trace t JOIN cst_customer c ON t.customer_id = c.customer_id JOIN cst_dict ds ON t.salestage = ds.dict_id JOIN cst_dict dm ON t.salemode = dm.dict_id";
	TRACE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TraceMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AllDO, TraceMapper>(sqlStr, mapper, params);
}

/*
// 通过客户名称查询数据
std::list<TraceDO> TraceDAO::selectByName(const string& name)
{
	
	std::list<TraceDO> result;
	return result;

	string sql = "SELECT customer_id,linkman_id,chance_id,salestage,salemode,conn_time,intro,next_time FROM cst_trace WHERE `name` LIKE CONCAT('%',?,'%')";
	TraceMapper mapper;
	return sqlSession->executeQuery<TraceDO, TraceMapper>(sql, mapper, "%s", name);
	
}*/

// 插入数据
uint64_t TraceDAO::insert(const AllDO& iObj)
{
	string sql = "INSERT INTO `cst_trace` (`customer_id`, `linkman_id`, `chance_id`, `salestage`, `salemode`, `conn_time`, `intro`, `next_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%i%i%i%i%i%s%s%s", iObj.getCusId(), iObj.getLinkid(), iObj.getChanceid(), iObj.getStage(), iObj.getSmode(), iObj.getCtime(), iObj.getIcontent(), iObj.getNtime());
	//int类型都是%i
}

// 修改数据
int TraceDAO::update(const AllDO& uObj)
{
	string sql = "UPDATE `cst_trace` SET `customer_id`=?, `linkman_id`=?, `chance_id`=?, `salestage`=?, `salemode`=?, `conn_time`=?, `intro`=?, `next_time`=? WHERE `trace_id`=?";
	return sqlSession->executeUpdate(sql, "%i%i%i%i%i%s%s%s%i", uObj.getCusId(), uObj.getLinkid(), uObj.getChanceid(), uObj.getStage(), uObj.getSmode(), uObj.getCtime(), uObj.getIcontent(), uObj.getNtime(), uObj.getTraceId());
}

int TraceDAO::deleteById(uint64_t trace_id)
{
	string sql = "DELETE FROM `cst_trace` WHERE `trace_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", trace_id);
}

list<TraceDO> TraceDAO::seletctAll()
{
	string sql = "SELECT trace_id,customer_id,linkman_id,chance_id,conn_time,salestage,salemode,name,intro,status,next_time,nexttitle,create_user_id,create_time FROM cst_trace";
	TraceMapper mapper;
	return sqlSession->executeQuery<TraceDO, TraceMapper>(sql, mapper);
}

