/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/23 21:37:59

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
#include "ServiceDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}




//添加服务记录
uint64_t ServiceDAO::insert(const ServiceDO & iObj)
{
	string sql = "INSERT INTO `cst_service` (`customer_id`, `linkman_id`,`services`,\
`servicesmodel`,`price`,`status`,\
`service_time`,`tlen`,`content`,\
`intro`,`create_user_id`,`create_time`)\
 VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";//一共12条数据
	return sqlSession->executeInsert(sql, "%i%i%i%i%i%i%s%s%s%s%i%s",
		iObj.getCustomer_id(), iObj.getLinkman_id(), iObj.getServices(),
		iObj.getServicesmodel(), iObj.getPrice(), iObj.getStatus(),
		iObj.getService_time(),iObj.getTlen(),iObj.getContent(),
		iObj.getIntro(),iObj.getCreate_user_id(),iObj.getCreate_time());
}
//更新服务记录
int ServiceDAO::update(const ServiceDO& uObj)
{
	string sql = "UPDATE `cst_service` SET `customer_id`=?, `linkman_id`=?, `services`=?,\
`servicesmodel`=?, `price`=?,`status`=?,\
`service_time`=?,`tlen`=?,`content`=?,\
`intro`=? \
 WHERE `service_id`=?";
	return sqlSession->executeUpdate(sql, "%i%i%i%i%i%i%s%s%s%s%ull",
		uObj.getCustomer_id(), uObj.getLinkman_id(), uObj.getServices(),
		uObj.getServicesmodel(), uObj.getPrice(), uObj.getStatus(),
		uObj.getService_time(), uObj.getTlen(), uObj.getContent(),
		uObj.getIntro(), 
		uObj.getService_id());
}
//删除服务记录
int ServiceDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `cst_service` WHERE `service_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}



